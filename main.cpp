#include <iostream>

class String {

    char* str; // Указатель на строку
    int length; // Длина строки

public:
    // Конструктор по умолчанию
    String() {
        str = nullptr; // Пустая строка
        length = 0; // Нулевая длина
    }

    // Конструктор
    String(const char* s) {
        length = 0;
        while (s[length] != '\0') {
            length++; // Определяем длину строки
        }
        str = new char[length + 1]; // Выделяем память под строку
        for (int i = 0; i <= length; i++) {
            str[i] = s[i]; // Копируем строку в выделенную память
        }
    }

    // Конструктор копирования
   String(const String& other) {
        length = other.length; // Копируем длину
        str = new char[length + 1]; // Выделяем память
        for (int i = 0; i <= length; i++) {
            str[i] = other.str[i]; // Копируем строку
        }
    }

    // Оператор присваивания копированием
    String& operator=(const String& other) {
        delete[] str; // Освобождаем память
        length = other.length; 
        str = new char[length + 1]; 
        for (int i = 0; i <= length; i++) {
            str[i] = other.str[i]; 
        }
        return *this;
    }

    // Деструктор
    ~String() {
        delete[] str; 
    }

    // Метод для получения строки
    const char* getString() const {
        return str;
    }
};

// Функция main для демонстрации использования класса
int main() {
    String str1("Hello, world!"); // Создаем объект и передаем ему строку
    String str2 = str1; // Создаем второй объект, используя конструктор копирования
    String str3; 

    str3 = str1; // Присваиваем третьему объекту значение первого объекта

    // Выводим на экран содержимое всех строк
    std::cout << "String 1: " << str1.getString() << std::endl;
    std::cout << "String 2: " << str2.getString() << std::endl;
    std::cout << "String 3: " << str3.getString() << std::endl;

    return 0;
}
