#ifndef LAB_20_1_2_DATA_HANDLER_H
#define LAB_20_1_2_DATA_HANDLER_H

#include <string>

using namespace std;

// Объявление функций валидации входных данных
bool IsInt(const string& str);
bool IsBiggerThanZero(const string& str);
bool IsCorrectRange(const string& str, double x, double y);


#endif //LAB_20_1_2_DATA_HANDLER_H 