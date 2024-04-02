#include <iostream>

class String {

    char* str; // ��������� �� ������
    int length; // ����� ������

public:
    // ����������� �� ���������
    String() {
        str = nullptr; // ������ ������
        length = 0; // ������� �����
    }

    // �����������
    String(const char* s) {
        length = 0;
        while (s[length] != '\0') {
            length++; // ���������� ����� ������
        }
        str = new char[length + 1]; // �������� ������ ��� ������
        for (int i = 0; i <= length; i++) {
            str[i] = s[i]; // �������� ������ � ���������� ������
        }
    }

    // ����������� �����������
   String(const String& other) {
        length = other.length; // �������� �����
        str = new char[length + 1]; // �������� ������
        for (int i = 0; i <= length; i++) {
            str[i] = other.str[i]; // �������� ������
        }
    }

    // �������� ������������ ������������
    String& operator=(const String& other) {
        delete[] str; // ����������� ������
        length = other.length; 
        str = new char[length + 1]; 
        for (int i = 0; i <= length; i++) {
            str[i] = other.str[i]; 
        }
        return *this;
    }

    // ����������
    ~String() {
        delete[] str; 
    }

    // ����� ��� ��������� ������
    const char* getString() const {
        return str;
    }
};

// ������� main ��� ������������ ������������� ������
int main() {
    String str1("Hello, world!"); // ������� ������ � �������� ��� ������
    String str2 = str1; // ������� ������ ������, ��������� ����������� �����������
    String str3; 

    str3 = str1; // ����������� �������� ������� �������� ������� �������

    // ������� �� ����� ���������� ���� �����
    std::cout << "String 1: " << str1.getString() << std::endl;
    std::cout << "String 2: " << str2.getString() << std::endl;
    std::cout << "String 3: " << str3.getString() << std::endl;

    return 0;
}
