#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void sound() = 0;	//Pure Virtual Function (Чисто виртуальный метод)
	//Мы НЕ знаем как именно перемещается транспортое средство, пока не узнаем, 
	//какое именно это транспортное средство. Поэтому, определение этой функции
	//неизвестно = 0;
	//ЕСЛИ В КЛАССЕ ЕСТЬ ХОТЯ БЫ ОДИН ЧИСТО ВИРТУАЛЬНЫЙ МЕТОД, КЛАСС ЯВЛЯЕТСЯ АБСТРАКТНЫМ!!!
};

class Cat :public Animal
{
public:
	void sound()
	{
		cout << "Мяу" << endl;
	}
};

class Dog :public Animal
{
public:
	void sound()
	{
		cout << "Гав" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	//Animal animal;	//Can not instatiate abstract class
	Cat cat;
	cat.sound();
	Dog hot;
	hot.sound();
}