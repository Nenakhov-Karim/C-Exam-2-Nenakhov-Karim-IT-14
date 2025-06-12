#include <iostream>
#include "Functions.h"
#include "Data_Handler.h"
using namespace std;

int main() {
    int N, start, step;
    string input;

    cout << "Enter N: " << endl;
    while (true) {
        getline(cin, input);
        if (IsInt(input) and IsBiggerThanZero(input)) {
            N = stoi(input);
            break;
        }
        if (!IsInt(input))
            cout << "It must be int and be positive, try again please: ";
        else if (!IsBiggerThanZero(input))
            cout << "It cant be a zero, try again please: ";

    }

    CircularList list;

    for (int i = 1; i <= N * 2; i++)
        list.addEnd(i);


    list.Print();


    cout << "Enter start number: (it must be between 1 and 31)" << endl;
    while (true) {
        getline(cin, input);
        if (IsInt(input) and IsBiggerThanZero(input) and IsCorrectRange(input, 1, 31)) {
            start = stoi(input);
            if (start > N) {
                start = start % N;
                if (start == 0)
                    start = N;

            }
            break;
        }
        if (!IsInt(input))
            cout << "It must be int, positive and be between 1 and 31, try again please: ";
        else if (!IsBiggerThanZero(input))
            cout << "It cant be a zero, try again please: ";
    }


    cout << "Enter step: " << endl;
    while (true) {
        getline(cin, input);
        if (IsInt(input) and IsBiggerThanZero(input)) {
            step = stoi(input);
            break;
        }
        if (!IsInt(input))
            cout << "It must be int and be positive, try again please: ";
        else if (!IsBiggerThanZero(input))
            cout << "It cant be a zero, try again please: ";
    }

    list.DeleteNEveryKth(start, step, N);

    cout << "List after deleting: " << endl;

    list.Print();

}