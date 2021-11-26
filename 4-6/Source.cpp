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
    double x; // �������� ���������
    double func; // ������ �������� �������
    double sum; // �������� ��������� �����
    int n; // ����� ��������� � ��������� �����

    cout << "������� 1" << endl;
    cout << "������� �������� ��������� > ";
    cin >> x;
    cout << "������� ����� ��������� > ";
    cin >> n;
    func = (1 / sqrt(1 + x * x));// ���������� "�������" ��������
    double last;
    sum = sumN(x, n, last);
    cout << "������ �������� ������� ����� " << func << endl;
    cout << "��������� ����� ���� ����� " <<abs(sum) << endl;
    cout << "���������� ����������� ����� " << fabs(func - sum) << endl;
    cout << "��������� ��������� ����� " << last << endl;

    cout << "\n������� 2" << endl;
    double E;
    cout << "������� �������� ��������� > ";
    cin >> x;
    cout << "������� �������� ���������� > ";
    cin >> E;
    func = 1 / sqrt(1 + x * x);// ���������� "�������" ��������
    sum = sumE(x, E, n);
    cout << "������ �������� ������� ����� " << func << endl;
    cout << "��������� ����� ���� c �������� ��������� ����� " <<abs(sum) << endl;
    cout << "������ " << n << " ������ ����" << endl;
    sum = sumE(x, E / 10, n);
    cout << "��������� ����� ���� c ���������, ������� � 10 ���, ����� " << sum << endl;
    cout << "������ " << n << " ������ ����" << endl;
    _getch();
    return 0;
}

double sumN(double x, int n, double& last)
{

   

    // ������������� ���������� last

    double sum = last;
    last = x;
    for (int i = 1; i < n; ++i)
    {
        double r; // ��������� i-�� ����������� � (i - 1)-��
       // ���������� �������� r
        r = pow(x,i*2) * (2 * i - 1) / (2 * i);
        last *= r;
        sum += last;
    
    }
    return sum;
}

double sumE(double x, double E, int& n)
{
    double last;
    // ������������� ���������� last
    last = x;
    double sum = last;
    for (n = 1; fabs(last) > E; ++n)
    {
        double r; // ��������� n-�� ����������� � (n - 1)-��
      // ���������� �������� r
        r = pow(x,n*2) * (2 * n - 1) / (2 * n);
        last *= r;
        sum += last;
    }
    return sum;
}


