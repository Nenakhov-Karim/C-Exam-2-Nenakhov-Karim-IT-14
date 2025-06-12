#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <iostream>

using namespace std;

// Структура узла
struct Node {
    int data;  // Поле данных
    Node* Next;  // Указатель на следующий элемент

    Node(int value) : data(value), Next(nullptr) {}  // Конструктор нового узла
};


class CircularList {
private:
    Node *Head;
    // Даём доступ только методам класса (Мы объявили переменную Head - указатель на объект типа данных Node, но пока не присвоили ей конкретное значение)

public:
    CircularList() : Head(nullptr) {}  // Тут мы присваиваем голове списка нулевой указатель


    void addEnd(int value) {
        Node* newNode = new Node(value);  // Смотри файл с объяснениями

        if (!Head) {  // Если список пустой
            Head = newNode;  // Делаем созданный ранее узел головой
            Head->Next = Head; // И замыкаем цепочку на самом себе (так как список у нас циклический)
        }

        Node* temp = Head;  // Создаём временный указатель, который равен голове
        while (temp->Next != Head) {  // Двигаемся пока н наткнёмся на последний элемент списка
            temp = temp->Next;
        }

        temp->Next = newNode;
        newNode->Next = Head;
    }


    void Print() const {
        if (!Head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = Head;
        do {
            cout << temp-> data << " ";
            temp = temp->Next;
        } while (temp != Head);
        cout << "\n";
    }

    void deleteNode(int value) {
        if (!Head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = Head;
        Node* prev = nullptr;

        if (Head->data == value and Head->Next == Head) {
            delete Head;  // Сначала освобождаем память
            Head = nullptr;  // Затем удаляем ссылку
            return;
        }

        if (Head->data == value) {
            Node* ToDelete = Head;
            while (temp->Next != Head) {
                temp = temp->Next;
            }
            Head = Head->Next;
            temp->Next = Head;
            delete ToDelete;
        }


    }



    void DeleteNEveryKth(int start, int step, int N) {

        if (!Head or step <= 0 or N <= 0) return;

        Node* current = Head;
        Node* prev = nullptr;

        for (int i = 1; i < start; i++) {  // Переходим к элементу, от которого начнётся отсчёт
            prev = current;
            current = current->Next;
        }

        if (!prev) {  // Если отсчёт начинается с головы, то предыдущий элемент - последний элемент списка
            prev = Head;
            while (prev ->Next != Head)
                prev = prev->Next;  // До него мы и доходим
        }


        for (int deleted = 0; deleted < N; deleted++) {
            cout << current->data << " was deleted" << endl;
            if (current == Head)
                Head = Head->Next;
            prev->Next = current->Next;
            delete current;
            current = prev->Next;

            for (int count = 1; count < step; count++) {
                prev = current;
                current = current->Next;
            }
        }
    }

};

#endif //FUNCTIONS_H
