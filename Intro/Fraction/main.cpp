#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Fraction;	//Объявление класса (Class declaration)
Fraction operator*(Fraction left, Fraction right);

class Fraction
{
	int integer;		//Целая часть
	int numerator;		//Числитель
	int denominator;	//Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;//Фильтрация данных
		this->denominator = denominator;
	}
	//			Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstruct:" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor:" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//			Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		/*int a = 2;
		int b = 3;
		a *= b;
		a = a * b;*/
		return *this = *this*other;
		//Возвращает результат операции по ссылке, поскольку результат сохраняется в this,
		//следовательно this является результатом.
		//this - это указатель на объект, для которого вызывается метод.
		//Для того чтобы вызвать метод, объект должен быть уже создан,
		//то есть объект появляется раньше, чем для него вызывается метод,
		//и после того, как метод отработал, с объектом для которого он вызвался (this)
		//ничего не происходит, он никуда не девается и не удаляется, так как объекты 
		//может удалять только деструктор.
		//Поскольку этот объект никуда не девается после отработки метода, мы можем вернуть его
		//по ссылке (by reference), чтобы не создавать копию этого объекта.
	}
	Fraction& MultiplyAndAssign(const Fraction& other)
	{
		/*int a = 2;
		int b = 3;
		a *= b;
		a = a * b;*/
		return *this = *this*other;
	}


	//				Increment/Decrement:
	Fraction& operator++()		//Prefix increment
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)	//Postfix (Suffix) increment
	{
		Fraction old = *this;	//Сохраняем старое значение. CopyConstructor
		integer++;
		return old;	//CopyConstructor
	}

	//			Type-cast operators:
	explicit operator int()
	{
		return integer;
	}

	//			Methods:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()	//Обращает дробь - меняет местами числитель и знаменатель
	{
		to_improper();
		/*int buffer = numerator;
		numerator = denominator;
		denominator = buffer;
		return *this;*/
		return Fraction(denominator, numerator);
	}
	void print()const
	{
		if (integer)cout << integer;
		if (integer && numerator)cout << "(";
		if (numerator)cout << numerator << "/" << denominator;
		if (integer && numerator)cout << ")";
		if (integer == 0 && numerator == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction sum
	(
		left.get_numerator()*right.get_denominator() + right.get_numerator()*left.get_denominator(),
		left.get_denominator()*right.get_denominator()
	);
	sum.to_proper();
	return sum;*/

	return Fraction
	(
		left.get_numerator()*right.get_denominator() + right.get_numerator()*left.get_denominator(),
		left.get_denominator()*right.get_denominator()
	).to_proper();
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	result.to_proper();
	//result - это локальный объект, он объявлен в функции oprtator*, 
	//и сущестует только в этой функции, и по завершении этой функции
	//result будет удален из памяти, и если вернуть ссылку на этот локальный объект,
	//то на месте вызова мы получим мусор.
	//Поэтому возвращаем объект по значению, чтобы скопровать его не место вызова.
	return result;
	//return Fraction	//Здесь мы явно вызываем конструктор, который создает временный безымянный объект, с нужным нам результатом
	//(
	//	left.get_numerator()*right.get_numerator(),
	//	left.get_denominator()*right.get_denominator()
	//);
}

Fraction multiply(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	return result;*/
	return Fraction	//Здесь мы явно вызываем конструктор, который создает временный безымянный объект, с нужным нам результатом
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
}


Fraction operator/(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	Fraction result
	(
		left.get_numerator()*right.get_denominator(),
		left.get_denominator()*right.get_numerator()
	);
	return result;*/

	Fraction result = left * right.inverted();
	return result;

	//return left * right.inverted();
}

int dva_plus_dva()
{
	return 2 + 2;
}

//#define CONSTRUCTORS_CHECK
//#define INCREMENT_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPOUND_ASSIGNMENTS_CHECK
//#define OPTIMISATION_CHECK
//#define TYPE_CONVERSIONS
#define TYPE_CONVERSIONS_HOME_WORK


void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;		//Default constructor
	A.print();
	Fraction B = 3;	//Single-argument constructor
	B.print();
	Fraction C(0, 3, 4);
	C.print();
	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;	//CopyConstructor
	E.print();

	Fraction F;		//Default constructor
	F = E;			//operator= (CopyAssignment)
	F.print();

	cout << dva_plus_dva << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	int a = 2;
	int b = 3;
	int c = a * b;
	int d = a / b;
	int e = a + b;

	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	Fraction C = A * B;
	C.print();
	Fraction D = A / B;
	D.print();

	Fraction E = A + B;
	E.print();

	(A + B).print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef INCREMENT_CHECK
	for (double i = .25; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;

	for (Fraction i(1, 4); i.get_integer() < 10; i++)
	{
		i.print();
	}
#endif // INCREMENT_CHECK

#ifdef COMPOUND_ASSIGNMENTS_CHECK
	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	A *= B;	//Неявный вызов оператора (implicit operator call)
	A.operator*=(B);	//Явный вызов оператора (explicit operator call)
	A.MultiplyAndAssign(B);
	A.print();

	A*B;			//Неявный вызов оператора (implicit operator call)
	operator*(A, B);//Явный вызов оператора (explicit operator call)
	multiply(A, B);
#endif // DEBUG

#ifdef OPTIMISATION_CHECK
	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	cout << "\n------------------------------------\n";
	Fraction C = A * B;
	cout << "\n------------------------------------\n";
	C.print();
#endif // OPTIMISATION_CHECK

#ifdef TYPE_CONVERSIONS
	//(type)value; - C-like notation
//type(value); - Functional notation
//Warning: ... possible loss of data;
//int a = 2;		//No conversions
//double b = 3;	//From int to double (From less to more)
//int c = 4.5;	//From double to int (From more to less with data loss)
//int d = b;		//From double to int (From more to less no data loss)
//double e = 5.3;
//int f = a + e;

//		OTHER TYPES TO OUR TYPE
//Single-argument constructor
//Assignment operator (CopyAssignment)

	int a = 2;//	No conversions
	Fraction A = (Fraction)5;	//From int to Fraction  (From less to more)
	A.print();
	Fraction B;
	B = (Fraction)3;
	B.print();

	//		OUR OBJECTS TO OTHER TYPES
	//		type-cast operators

	/*
	---------------
	operator type()
	{
		.....
		.....
	}
	---------------
	*/

	int b = (int)B;
	cout << b << endl;
#endif // TYPE_CONVERSIONS

#ifdef TYPE_CONVERSIONS_HOME_WORK
	//Task1
	Fraction A(2, 3, 4);
	double a = A;
	cout << a << endl;

	//Task2
	double b = 3.14;
	Fraction B = b;
	B.print();
#endif // TYPE_CONVERSIONS_HOME_WORK

}