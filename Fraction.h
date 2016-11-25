#pragma once
#include <iostream>
#include <Windows.h>
//Абстрактный базовый класс дроби
class AbstractFraction
{
public:
	virtual void Print() = 0;		//Вывод на экран (чисто виртуальная функция)
	virtual ~AbstractFraction(){}	//Виртуальный деструктор для исключения утечки памяти при удалении производного объекта по указателю базового класса
	virtual int & GetNumerator()=0;	//Извлечение значения числителя (чисто виртуальная функция)
	virtual int & GetDenominator()=0;	//Извлечение значения знаменателя (чисто виртуальная функция)
};
//Класс дроби
class Fraction: public AbstractFraction
{
	int Numerator;		//Числитель
	int Denominator;	//Знаменатель
	static AbstractFraction **PFraction;//Static ДИНАМИЧЕСКИЙ массив указателей на объекты БАЗОВОГО (абстрактного) класса
	static int Size;	//Размер массива PFraction
public:
	Fraction();							//Конструктор по умолчанию
	Fraction(const int N, const int D);				//Конструктор с параметрами
	Fraction(const Fraction &F);				//Конструктор копирования
	virtual ~Fraction();				//Виртуальный деструктор для исключения утечки памяти при удалении производного объекта по указателю базового класса
	static void SetNumerator(const int N, const int Index);		//Установка значения числителя объекта, на который ссылается указатель массива PFraction по индексу Index
	static void SetDenominator(const int D, const int Index);	//Установка значения знаменателя объекта, на который ссылается указатель массива PFraction по индексу Index
	virtual int & GetNumerator();		//Извлечение значения числителя (унаследованная чисто виртуальная функция)
	virtual int & GetDenominator();		//Извлечение значения знаменателя (унаследованная чисто виртуальная функция)
	static int GetSize();				//Извлечение размера массива PFraction
	virtual void Print();				//Вывод на экран (унаследованная чисто виртуальная функция)
	static void PrintAll();				//Вывод на экран всех объектов, указатели на которые находятся в PFraction
	static void clearArray();			//Удаление всех объектов, на которые ссылаются указатели массива PFraction
	static void delElem(const int n);			//Удаление объекта, на который ссылается указатель массива PFraction по индексу n
};
//Функция меню
void Menu();