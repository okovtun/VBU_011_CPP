//Recursion
#include<iostream>
using namespace std;

void elevator(int level)
{
	if (level == 0)return;
	cout << level << endl;
	elevator(level - 1);//Рекурсивный вызов
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
//main();	//Рекурсивный вызов функции main()
	int n;
	cout << "Введите номер этажа: "; cin >> n;
	elevator(n);
#endif // RECURSION_BASICS

#ifdef FACTORIAL
	int n;
	cout << "Введите число для вычисления факториала: "; cin >> n;
	cout << factorial(n) << endl;
#endif // FACTORIAL

	int a;	//Основание степени
	int n;	//Показател степени
	cout << "Введите основание степени: "; cin >> a;
	cout << "Введите показатель степени: "; cin >> n;
	cout << power(a, n) << endl;

	main();
}

//Итерационно - при помощи циклов
//Рекурсивно - при помощи рекурсии