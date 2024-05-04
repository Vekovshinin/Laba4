#include <iostream>
#include <clocale>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Ru");
    int a[100];
    int n, k, cnt = 0, ch = 0;
    cout << "Введите количество элементов в массиве: ";
    cin >> n;
    cout << "Введите индекс элемента( начало кольца ): ";
    cin >> k;
    cout << "Исходный массив: ";
    for (int i = 0; i < n; ++i)
        a[i] = rand() % 100;
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << endl << "Однонаправленное кольцо в виде массива: ";
    for (int i = 0; i < n; ++i) {
        cout << a[k] << ' ';
        k--;
        if (k == -1) k = n - 1;
    }
    cout << endl << "Упорядоченный массив по убыванию: ";
    for (int i = 0; i < (n - 1); ++i) {
        for (int j = 0; j < (n - 1 - i); ++j) {
            if (a[j] < a[j + 1]) {
                int m = a[j];
                a[j] = a[j + 1];
                a[j + 1] = m;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {

            for (int j = i; j < n; j++)
            {
                a[j] = a[j + 1];
            }
            n--;
            i--;
        }
    }
    cout << endl << "Массив без нечетных элементов: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl << "Полученный массив без нечетных элементов с k: ";
    if (k >= n) k = k % n;
    for (int i = 0; i < n; ++i) {
        cout << a[k] << ' ';
        k--;
        if (k == -1) k = n - 1;
    }
}
