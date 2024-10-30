#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Шаблонна рекурсивна функція для створення масиву
template <typename T>
T Create(T* a, int size, T Low, T High, int i) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
    return 0;
}

// Шаблонна рекурсивна функція для підрахунку кількості непарних елементів
template <typename T>
int quantity(T* a, int size, int& q, int i) {
    if (a[i] % 2 != 0)
        q++;
    if (i < size - 1)
        quantity(a, size, q, i + 1);
    return 0;
}

// Шаблонна рекурсивна функція для виведення масиву
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
    srand((unsigned)time(NULL));  // Ініціалізація генератора випадкових чисел

    int q = 0;  // Змінна для збереження кількості непарних елементів
    const int n = 10;  // Розмір масиву
    int a[n];  // Масив
    int Low = 5;  // Нижня межа випадкових чисел
    int High = 90;  // Верхня межа випадкових чисел

    // Виклик шаблонних функцій для масиву типу int
    Create(a, n, Low, High, 0);
    quantity(a, n, q, 0);

    cout << "Кiлькiсть непарних елементiв: " << setw(2) << q << endl;
    cout << "a[" << setw(1);
    Print(a, n, 0);

    return 0;
}
