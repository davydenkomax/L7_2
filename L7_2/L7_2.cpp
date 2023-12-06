/*
    Для любого задания лабораторных работ № 5 и №6 реализовать ввод,
    формирование/обработку и вывод массивов с применением функций.
*/
#include <iostream>

using namespace std;

void inputMatrix(int, int, double**);

void processMatrix(int, int, double**);

void printMatrix(int, int, double**);

int main() {
    setlocale(LC_ALL, "ru");
    // Объявление переменных
    int m, n;
    // Ввод значения переменной m
    cout << "Введите значение переменной m (m > 0): ";
    cin >> m;
    // Ввод значения переменной n                                             
    cout << "Введите значение переменной n (n > 0 и n-четное): ";
    cin >> n;
    // Проверка на неправильный ввод размера матрицы
    if (m <= 0 || m > 10 || n % 2 != 0 || n <= 0 || n > 10) {
        cerr << "\nНеправильный ввод значений пременных";
        return 1;
    }
    double** matrix;
    // Выделение памяти под массив указателей
    matrix = new double* [m];
    for (int i = 0; i < m; i++) {
        // Выделение памяти под массив
        matrix[i] = new double[n];
    }
    //Вызов финкции inputMatrix
    inputMatrix(m, n, matrix);
    //Вызов финкции processMatrix
    processMatrix(m, n, matrix);
    //Вызов финкции printMatrix
    printMatrix(m, n, matrix);
    // Освобождение выделенной памяти
        for (int i = 0; i < n; i++) {
            delete[] matrix[i];
        }
    delete[] matrix;
}

void inputMatrix(int m, int n, double** matrix) {
    // Ввод значений в матрицу
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

void processMatrix(int m, int n, double** matrix) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n / 2; j++) {
            // Сохраняем значение matrix[i][j] в переменную el
            double el = matrix[i][j];
            // Присваиваем элементу matrix[i][j] значение зеркального элемента матрицы
            matrix[i][j] = matrix[i][j + n / 2];
            // Присваиваем зеркальному элементу первоначальное значение matrix[i][j], которое сохранили в переменную el
            matrix[i][j + n / 2] = el;
        }
    }
}

void printMatrix(int m, int n, double** matrix) {
    // Вывод полученной матрицы
    cout << "Полученная матрица: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}