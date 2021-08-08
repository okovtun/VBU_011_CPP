#include"String.h"

///////////////////////////////////////////////////////////////////////////////////////
//////////////////		����������� ������ (CLASS DEFINITION)		///////////////////
///////////////////////////////////////////////////////////////////////////////////////
unsigned int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
String::String(unsigned int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)	//���������� ��������� ������ ������� ������������
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "1argConstructor:" << this << endl;
}
String::String(const String& other) : String(other.str)
{
	cout << "CopyConstructor:" << this << endl;
}
String::~String()
{
	delete[] this->str;	//[] ����������, ��� ��������� ������
	cout << "Destructor:\t" << this << endl;
}

//			Operators:
String& String::operator=(const String& other)
{
	//0) ���������, �� �������� �� �������� ������ ����� ��������:
	if (this == &other)return *this;
	//1) ������� ������ �������� �������, �.�. ����������� ���������� �� ������.
	delete[] this->str;
	//2) ��������� deep copy:
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment: " << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}
//�������� ���������� c����� (�������� ��������������� - Subscript operator) ���������� �������� �� �������
const char& String::operator[](unsigned int i)const //i - index
{
	return str[i];
}
char& String::operator[](unsigned int i)//i - index
{
	return str[i];
}

//			Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	//1) ������� ������, � ������� �������� ���������:
	String cat(left.get_size() + right.get_size() - 1);	//��������� ������
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}