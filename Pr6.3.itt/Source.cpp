#include <iostream>
#include <iomanip>
#include <time.h>
#include <locale>
using namespace std;

// Шаблон функції для створення масиву
template <typename T>
T Create(T* a, int size, T Low, T High) {
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
    return 0;
}

// Шаблон функції для підрахунку кількості непарних елементів
template <typename T>
int quantity(T* a, int size, int& q) {
    for (int i = 0; i < size; i++)
        if (a[i] % 2 != 0)
            q++;
    return 0;
}

// Шаблон функції для виведення масиву
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

// Шаблон функції для перевірки впорядкованості масиву за неспаданням
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
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел

    int q = 0;  
    const int n = 10; 
    int a[n]; 
    int Low = 5;  
    int High = 90;  

    // Викликаємо шаблонні функції для масиву типу int
    Create(a, n, Low, High);  
    quantity(a, n, q);  

    cout << "Кiлькiсть непарних елементiв: " << setw(2) << q << endl;

    // Перевірка на впорядкованість масиву
    if (isSorted(a, n)) {
        cout << "Масив впорядкований за не спаданням." << endl;
    }
    else {
        cout << "Масив не впорядкований." << endl;
    }

    // Виведення масиву
    Print(a, n);

    return 0;
}
