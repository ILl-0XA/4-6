                  /////1/sqrt(1+x^2)=1+1/2*x^2+(1/2*3/4)*x^4+(1/2*3/4*5/6)*x^6+.....
#include <conio.h>
#include <locale>
#include <iostream>

using namespace std;

double sumN(double, int, double&);
double sumE(double, double, int&);

int main()
{
    setlocale(LC_ALL, "rus");
    double x; // Значение аргумента
    double func; // Точное значение функции
    double sum; // Значение частичной суммы
    int n; // Число слагаемых в частичной сумме

    cout << "Задание 1" << endl;
    cout << "Введите значение аргумента > ";
    cin >> x;
    cout << "Задайте число слагаемых > ";
    cin >> n;
    func = (1 / sqrt(1 + x * x));// Вычисление "точного" значения
    double last;
    sum = sumN(x, n, last);
    cout << "Точное значение функции равно " << func << endl;
    cout << "Частичная сумма ряда равна " <<abs(sum) << endl;
    cout << "Абсолютная погрешность равна " << fabs(func - sum) << endl;
    cout << "Последнее слагаемое равно " << last << endl;

    cout << "\nЗадание 2" << endl;
    double E;
    cout << "Введите значение аргумента > ";
    cin >> x;
    cout << "Задайте точность вычислений > ";
    cin >> E;
    func = 1 / sqrt(1 + x * x);// Вычисление "точного" значения
    sum = sumE(x, E, n);
    cout << "Точное значение функции равно " << func << endl;
    cout << "Частичная сумма ряда c заданной точностью равна " <<abs(sum) << endl;
    cout << "Учтено " << n << " членов ряда" << endl;
    sum = sumE(x, E / 10, n);
    cout << "Частичная сумма ряда c точностью, большей в 10 раз, равна " << sum << endl;
    cout << "Учтено " << n << " членов ряда" << endl;
    _getch();
    return 0;
}

double sumN(double x, int n, double& last)
{

   

    // Инициализация переменной last

    double sum = last;
    last = x;
    for (int i = 1; i < n; ++i)
    {
        double r; // Отношение i-го слагаемлого к (i - 1)-му
       // Вычисление значения r
        r = pow(x,i*2) * (2 * i - 1) / (2 * i);
        last *= r;
        sum += last;
    
    }
    return sum;
}

double sumE(double x, double E, int& n)
{
    double last;
    // Инициализация переменной last
    last = x;
    double sum = last;
    for (n = 1; fabs(last) > E; ++n)
    {
        double r; // Отношение n-го слагаемлого к (n - 1)-му
      // Вычисление значения r
        r = pow(x,n*2) * (2 * n - 1) / (2 * n);
        last *= r;
        sum += last;
    }
    return sum;
}


