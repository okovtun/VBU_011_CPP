//Recursion
#include<iostream>
using namespace std;

void elevator(int level)
{
	if (level == 0)return;
	cout << level << endl;
	elevator(level - 1);//����������� �����
	cout << level << endl;
}

int factorial(int n)
{
	/*if (n == 0)return 1;
	return n * factorial(n - 1);*/
	return n == 0 ? 1 : n * factorial(n - 1);
}

double power(double a, int n)
{
	/*if (n == 0)return 1;
	if (n > 0)return a * power(a, n - 1);
	else return 1 / a * power(a, n + 1);*/
	return n == 0 ? 1 : n > 0 ? a * power(a, n - 1) : 1 / a * power(a, n + 1);
}

//#define RECURSION_BASICS
//#define FACTORIAL
#define POWER

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef RECURSION_BASICS
	//cout << "Hello World";
//main();	//����������� ����� ������� main()
	int n;
	cout << "������� ����� �����: "; cin >> n;
	elevator(n);
#endif // RECURSION_BASICS

#ifdef FACTORIAL
	int n;
	cout << "������� ����� ��� ���������� ����������: "; cin >> n;
	cout << factorial(n) << endl;
#endif // FACTORIAL

	int a;	//��������� �������
	int n;	//��������� �������
	cout << "������� ��������� �������: "; cin >> a;
	cout << "������� ���������� �������: "; cin >> n;
	cout << power(a, n) << endl;

	main();
}

//����������� - ��� ������ ������
//���������� - ��� ������ ��������