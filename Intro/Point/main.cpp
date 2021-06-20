#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n------------------------------------------------------------\n"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//			Constructors:
	Point()
	{
		//Конструктор по умолчанию
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		//Конструктор с одним параметром
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		//Shallow copy - повехностное копирование объекта
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//			Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	//			Methods:

	double distance(const Point& other)
	{
		//A - this;
		//B - other;
		//other.x += 100;
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		//sqrt - Square Root (Квадратный корень).
		return distance;
	}

	void print()const
	{
		cout << "X = " << x << tab << "Y = " << y << endl;
	}
};
//Создавая структуру или класс мы создаем тип данных.
//Классы и структуры еще называют пользовательскими типами данных.
//Соответственно, объекты являются переменными пользвательского типа.
//					СТРУКТУРА - ЭТО ТИП ДАННЫХ!!!
//						КЛАСС - ЭТО ТИП ДАННЫХ!!!

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	// type name;
	int a;		//Объявляем переменную 'a' типа 'int'
	//Создание объекта
	Point A;	//Объявляем переменную 'A' типа 'Point'	
				//Объявляем объект 'A' структуры 'Point'
				//Создаем экземпляр 'A' структуры 'Point'
	//Объект класса или структуры еще называют экземпляром (instance) класса или структуры.
	//Instantiate - создать экземпляр (объект).
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;	//Объявляем указатель на Point и берем адрес точки 'A'
	cout << pA->x << tab << pA->y << endl;
	cout << (*pA).x << tab << (*pA).y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << tab << A.get_y() << endl;
	Point B;
	B.set_x(4);
	B.set_y(5);
	cout << delimiter << endl;
	cout << B.distance(A) << endl;	//Мы находимся в точке B, и вычисляем расстояние от этой точки (B) до точки A.
	cout << delimiter << endl;
	cout << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << distance(B, A) << endl;
	cout << delimiter << endl;

	/*for (int i = 0; i < 5; i++)
	{
		cout << i << tab;
	}
	cout << endl;*/
#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	Point A;	//Default constructor
	A.print();
	Point B = 3;//Single-argument constructor
	B.print();
	Point C(2, 3);//Parametrized constructor
	C.print();
	//ДЕСТРУКТОР ВЫЗЫВАЕТСЯ НЕ ДЛЯ КОНСТРУКТОРА, ДЕСТРУКТОР ВЫЗЫВАЕТСЯ ДЛЯ ОБЪЕКТА
	//Shallow copy
	Point D = C;	//CopyConstructor
	D.print();
	Point E;	//DefaultConstructor
	E = C;		//CopyAssignment
	E.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	
	int a, b, c;
	a = b = c = 0;
	cout << a << tab << b << tab << c << endl;

	Point A, B, C;
	cout << "\n-----------------------------------------\n";
	A = B = C = Point(4, 5);
	cout << "\n-----------------------------------------\n";
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK

}

/*
------------------------------------------------------------
.  - Оператор прямого доступа (Point operator).
-> - Оператор косвенного доступа (Arrow operator).
------------------------------------------------------------
*/

/*
------------------------------------------------------------
Концепции ООП:
1.	Инкапсуляция;
2.	Наследование;
3.	Полиморфизм;
Инкапсуляция (Encapsulation)
Модификаторы доступа:
private:
public:
protected:

get/set-методы
get(взять, получить)   - открывают доступ к переменным на чтение;
set(задать, установить)- открывают доступ к переменным на запись.
set-методы так-же обеспечивают фильтрацию данных, если она нужна;
------------------------------------------------------------
*/

/*
------------------------------------------------------------
Constructor - это метод, который создает объект.
~Destructor  - это метод, который уничтожает объект по завершении его времени жизни.
Operator=
------------------------------------------------------------
*/