//Recursion, Factorial, Power
#include<iostream>
using namespace std;
#define FACTORIAL_RECURSION
//#define POWER_RECURSION

#ifdef POWER_RECURSION
double power = 1;
void Power(int stepen, float m)
{
	if (stepen == 0)return;
	//cout << stepen << endl;
	power = power * m;
	Power(stepen - 1, m); // рекурсивный вызов
}
void main()
{
	setlocale(LC_ALL, "Russian");
	float a;
	float m;
	int n;
	cout << "Введите основание: "; cin >> m;
	cout << "Введите степень числа: "; cin >> a;
	int p = a;
	float c = a - p;
	n = a * a;
	n = sqrt(n);
	Power(n, m);

	//cout << c << endl;
	//cout << p << endl;
	cout << endl;
	if (c != 0)
	{
		cout << "Я не настолько продвинутый, чтоб возводить" << endl;
		cout << "в дробную степень. Она будет округлена до: " << p << endl;
	}
	if (a < 0)
	{
		cout << "Результат: " << 1 / power << endl;
	}
	else
	{
		cout << "Результат: " << power << endl;
	}

}
#endif // POWER_RECURSION

#ifdef FACTORIAL_RECURSION
unsigned long long Factorial = 1;
void elevator(int level)
{
	if (level == 0) return;
	if (level > 60) return;
	if (level < 0) return;
	//cout << level << endl;
	Factorial = Factorial * level;
	elevator(level - 1); // рекурсивный вызов
}
void main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Факториал: ";
	int n;
	cout << "Введите число: "; cin >> n;
	elevator(n);
	cout << endl;
	if (n > 60)
	{
		Factorial = 0;
		cout << "Много, столько не надо знать." << endl;
		cout << "Машину хочешь повесить??? - Не выйдет!" << endl;
	}
	else
	{
		if (n < 0)
		{
			//cout << "Факториал: --" << endl;
			cout << "Не бывает факториала от отрицательных чисчел! Учи матчасть!" << endl;
		}
		else
		{
			cout << "Факториал: " << Factorial << endl;
		}
	}
	cout << endl;
}
#endif // FACTORIAL_RECURSION