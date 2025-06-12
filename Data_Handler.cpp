#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
using namespace std;



// Проверка на целое число
bool IsInt(const string& str) {
    if (str.empty())
        return false;  // Пустой ввод
    for (int i = 0; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;  // Посимвольный проход по строке
    }
    return true;
}


bool IsBiggerThanZero(const string& str) {
  if (str.empty())
    return false;
  return (stoi(str) > 0);
}




bool IsCorrectRange(const string& str, double x, double y) {
    if (str.empty())
        return false;
    return (x <= stod(str) and stod(str) <= y);
}