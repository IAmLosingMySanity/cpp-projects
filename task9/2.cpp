#include <iostream>
#include <string>
#include <clocale>

using namespace std;

// Функция для проверки, можно ли переставить str1 в str2
constexpr bool canPermute(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) {
        return false; // Если длины строк разные, невозможно переставить
    }

    constexpr int size = 95;
    int count[size] = {0}; // Массив для подсчета количества букв (a-z)

    // Подсчет букв в str1
    for (auto c : str1) {
        count[c - '!']++;
    }

    // Вычитаем буквы str2 из массива
    for (auto c : str2) {
        count[c - '!']--;
    }

    // Если все элементы массива count равны нулю, строки можно переставить
    for (int i = 0; i < size; i++) {
        if (count[i] > 0) {
            return false;
        }
    }

    return true;
}

int main() {
    setlocale(LC_ALL, "");
    string str1, str2;
    cout << "1: ";
    cin >> str1;
    cout << "2: ";
    cin >> str2;

    if (canPermute(str1, str2)) {
        cout << "True." << endl;
    } else {
        cout << "False." << endl;
    }

    return 0;
}