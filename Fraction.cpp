#include "Fraction.h"
//Инициализация статических членов класса Fraction
int Fraction::Size = 0;
AbstractFraction ** Fraction::PFraction = NULL;
//Конструктор по умолчанию
Fraction::Fraction():Numerator(1), Denominator(1)
{
	//Создание нового массива указателей с кол-вом эл-тов на 1 больше, чем в PFraction
	AbstractFraction** nArr = new AbstractFraction*[Size + 1];
	//Скопировать все эл-ты PFraction в новый массив
	for (int i = 0; i < Size; i++)
	{
		nArr[i] = PFraction[i];
	}
	nArr[Size++] = this;//Вновь созданный элемент тоже записать в массив
	if (PFraction != NULL)
	{
		delete[] PFraction;
	}
	PFraction = nArr;//Вновь созданный массив - член класса Fraction
}
//Конструктор с параметрами
Fraction::Fraction(const int N, const int D) : Numerator(N), Denominator(D)
{
	//Создание нового массива указателей с кол-вом эл-тов на 1 больше, чем в PFraction
	AbstractFraction** nArr = new AbstractFraction*[Size + 1];
	//Скопировать все эл-ты PFraction в новый массив
	for (int i = 0; i < Size; i++)
	{
		nArr[i] = PFraction[i];
	}
	nArr[Size++] = this;//Вновь созданный элемент тоже записать в массив
	if (PFraction != NULL)
	{
		delete[] PFraction;
	}
	PFraction = nArr;//Вновь созданный массив - член класса Fraction
}
//Конструктор копирования
Fraction::Fraction(const Fraction & F) : Numerator(F.Numerator), Denominator(F.Denominator)
{
	//Создание нового массива указателей с кол-вом эл-тов на 1 больше, чем в PFraction
	AbstractFraction** nArr = new AbstractFraction*[Size + 1];
	//Скопировать все эл-ты PFraction в новый массив
	for (int i = 0; i < Size; i++)
	{
		nArr[i] = PFraction[i];
	}
	nArr[Size++] = this;//Вновь созданный элемент тоже записать в массив
	if (PFraction != NULL)
	{
		delete[] PFraction;
	}
	PFraction = nArr;//Вновь созданный массив - член класса Fraction
}
//Деструктор
Fraction::~Fraction()
{
	if (Size == 1)
	{
		delete [] PFraction;//удаляется массив указателей, сам элемент удаляется в функциях clearArray и delElem после отработки деструктора
		PFraction = NULL;
		Size--;
	}
	else
		if(Size > 1 && PFraction[Size - 1] != this)//если удаляем элемент не с максимальным значением индекса в массиве
		{
			AbstractFraction** nArr = new AbstractFraction*[Size - 1];
			for (int i = 0, j = 0; i < Size; i++)
			{
				if (PFraction[i] != this)//Копируются все, кроме указателя на удаляемый элемент
				{
					nArr[j++] = PFraction[i];
				}
			}
			delete[] PFraction;//Удаление массива указателей
			PFraction = nArr;//Вновь созданный массивn Arr - член класса Fraction
			Size--;
		}
		else
			if (Size > 1 && PFraction[Size - 1] == this)//если удаляем элемент с максимальным значением индекса в массиве
			{
				Size--;
			}
}
//Установка значения числителя объекта
void Fraction::SetNumerator(const int N, const int Index)
{
	PFraction[Index]->GetNumerator() = N;
}
//Установка значения знаменателя
void Fraction::SetDenominator(const int D, const int Index)
{
	PFraction[Index]->GetDenominator() = D;
}
//Извлечение ссылки на числитель (виртуальная реализация)
int & Fraction::GetNumerator()
{
	return Numerator;
}
//Извлечение ссылки на знаменатель (виртуальная реализация)
int & Fraction::GetDenominator()
{
	return Denominator;
}
int Fraction::GetSize()
{
	return Size;
}
//Вывод на экран (реализация виртуальной функции)
void Fraction::Print()
{
	std::cout << Numerator << "\t\t" << Denominator << std::endl;
}
//Вывод на экран всех объектов на которые ссылаются указатели массива PFraction
void Fraction::PrintAll()
{
	std::cout << "Size=" << Size << std::endl;
	std::cout << std::endl << "№" << "\t" << "Числитель" << "\t" << "Знаменатель" << std::endl;
	for (int i = 0; i < Size; i++)
	{
		std::cout << i << "\t";
		PFraction[i]->Print();
	}
}
//Удаление всех объектов, на которые ссылаются указатели массива PFraction
void Fraction::clearArray()
{
	for (int i= Size-1;i>=0;i--)
	{
		delete PFraction[i];
	}
}
//Удаление объекта на который ссылается указатель по индексу n в массиве PFraction
void Fraction::delElem(const int n)
{
	if (n >= 0 && n < Size)
	{
		delete PFraction[n];
	}
}
