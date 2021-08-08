#include<iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);

class String
{
	unsigned int size;	//Размер строки в Байтах
	char* str;			//Указатель на строку в динамической памяти
public:
	unsigned int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	explicit String(unsigned int size = 80) :size(size), str(new char[size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str) :String(strlen(str)+1)	//Делегируем выделение памяти первому конструктору
	{
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "1argConstructor:" << this << endl;
	}
	String(const String& other) :String(other.str)
	{
		cout << "CopyConstructor:" << this << endl;
	}
	~String()
	{
		delete[] this->str;	//[] показывают, что удаляется массив
		cout << "Destructor:\t" << this << endl;
	}

	//			Operators:
	String& operator=(const String& other)
	{
		//0) Проверяем, не является ли принятый объект нашим объектом:
		if (this == &other)return *this;
		//1) Удаляем старое значение объекта, т.е. освобождаем занимаемую им память.
		delete[] this->str;
		//2) Выполняем deep copy:
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment: " << this << endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	//Оператор квадратные cкобки (Оператор интдексирования - Subscript operator) возвращает значение по индексу
	const char& operator[](unsigned int i)const //i - index
	{
		return str[i];
	}
	char& operator[](unsigned int i)//i - index
	{
		return str[i];
	}

	//			Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	//1) Создаем строку, в которую поместим результат:
	String cat(left.get_size() + right.get_size() - 1);	//Локальный объект
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}

//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef CONSTRUCTORS_CHECK
	int a = 2;
	int b = 3;
	a = b;

	//String str = 5;	//Implicit conversion from int to String
	String str(5);		//explicit constructor можно вызвать только так, 
						//и нельзя вызвать оператором =
	str.print();
	String str1 = "Hello";
	str1 = str1;
	str1.print();

	String str2 = str1;	//CopyConstructor
	str2.print();

	String str3;
	str3 = str2;		//CopyAssignment
	str3.print();
#endif // CONSTRUCTORS_CHECK

	int a = 2;
	int b = 3;
	int c = a + b;

	String str1 = "Hello";
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;
	/*cout << "\n------------------------------------\n";
	String str3 = str1 + " " + str2;
	cout << "\n------------------------------------\n";
	cout << str3 << endl;*/
	//cout << str1 + str2 << endl;
	str1 += str2;
	cout << str1 << endl;
}