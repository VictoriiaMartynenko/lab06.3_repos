#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// �������� ���������� ������� ��� ��������� ������
template <typename T>
T Create(T* a, int size, T Low, T High, int i) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
    return 0;
}

// �������� ���������� ������� ��� ��������� ������� �������� ��������
template <typename T>
int quantity(T* a, int size, int& q, int i) {
    if (a[i] % 2 != 0)
        q++;
    if (i < size - 1)
        quantity(a, size, q, i + 1);
    return 0;
}

// �������� ���������� ������� ��� ��������� ������
template <typename T>
void Print(T* a, int size, int i) {
    if (i == size - 1)
        cout << setw(1) << a[i];
    else
        cout << setw(1) << a[i] << ", ";
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << "]" << endl;
}

int main() {
    setlocale(LC_ALL, "Ukrainian"); 
    srand((unsigned)time(NULL));  // ����������� ���������� ���������� �����

    int q = 0;  // ����� ��� ���������� ������� �������� ��������
    const int n = 10;  // ����� ������
    int a[n];  // �����
    int Low = 5;  // ����� ���� ���������� �����
    int High = 90;  // ������ ���� ���������� �����

    // ������ ��������� ������� ��� ������ ���� int
    Create(a, n, Low, High, 0);
    quantity(a, n, q, 0);

    cout << "�i���i��� �������� �������i�: " << setw(2) << q << endl;
    cout << "a[" << setw(1);
    Print(a, n, 0);

    return 0;
}
