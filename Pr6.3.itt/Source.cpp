#include <iostream>
#include <iomanip>
#include <time.h>
#include <locale>
using namespace std;

// ������ ������� ��� ��������� ������
template <typename T>
T Create(T* a, int size, T Low, T High) {
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
    return 0;
}

// ������ ������� ��� ��������� ������� �������� ��������
template <typename T>
int quantity(T* a, int size, int& q) {
    for (int i = 0; i < size; i++)
        if (a[i] % 2 != 0)
            q++;
    return 0;
}

// ������ ������� ��� ��������� ������
template <typename T>
void Print(T* a, int size) {
    cout << "a[" << setw(1);
    for (int i = 0; i < size; i++)
        if (i == size - 1)
            cout << setw(1) << a[i];
        else
            cout << setw(1) << a[i] << ", ";
    cout << "]" << endl;
}

// ������ ������� ��� �������� �������������� ������ �� �����������
template <typename T>
bool isSorted(T* a, int size) {
    for (int i = 1; i < size; i++) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Ukrainian"); 
    srand((unsigned)time(NULL)); // ����������� ���������� ���������� �����

    int q = 0;  
    const int n = 10; 
    int a[n]; 
    int Low = 5;  
    int High = 90;  

    // ��������� ������� ������� ��� ������ ���� int
    Create(a, n, Low, High);  
    quantity(a, n, q);  

    cout << "�i���i��� �������� �������i�: " << setw(2) << q << endl;

    // �������� �� �������������� ������
    if (isSorted(a, n)) {
        cout << "����� ������������� �� �� ���������." << endl;
    }
    else {
        cout << "����� �� �������������." << endl;
    }

    // ��������� ������
    Print(a, n);

    return 0;
}
