#include<iostream>
using namespace std;

class Element
{
	int Data;		//Значение элемента
	Element* pNext;	//Адрес следующего элемента
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

class ForwardList
{
	Element* Head;	//Голова списка - указывает на начальный (нулевой) элемент списка.
public:
	ForwardList()
	{
		//Конструктор по умолчанию, создает пустой список.
		Head = nullptr;
		//Если Голова указывает на 0, то список пуст, т.е., не содержит элементов,
		//и Голове больше не на что указывать.
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//						Adding elements:
	void push_front(int Data)
	{
		//1) Создаем новый элемент:
		Element* New = new Element(Data);
		//2) Прикрепляем элемент к списку:
		New->pNext = Head;
		//3) Говорим что Новый элемент теперь Начальный элемент списка:
		Head = New;
	}

	//					Methods:
	void print()const
	{
		Element* Temp = Head; //Temp - это итератор.
		//Итератор - это указатель, при помощи которого можно получить доступ 
		//к элементам структуры данных
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext; //Переход на следующий элемент.
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n; cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
}