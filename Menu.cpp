#include "Fraction.h"
//Функция отображения меню
void ShowMenu()
{
	std::cout << std::endl << "Лабораторная работа №3 (ООП)";
	std::cout << std::endl << "[а]. Добавить объект";
	std::cout << std::endl << "[б]. Ввод новых значений для объекта с заданным номером";
	std::cout << std::endl << "[в]. Удалить объект";
	std::cout << std::endl << "[г]. Показать все объекты";
	std::cout << std::endl << "[д]. Выход";
	std::cout << std::endl << "Введите букву требуемого пункта меню: ";
}
//Функция отображения подменю добавления объекта
void ShowMenu2()
{
	std::cout << std::endl << "[1]. Значения по умолчанию";
	std::cout << std::endl << "[2]. Ввод значений числителя и знаменателя";
	std::cout << std::endl << "[3]. Выход";
	std::cout << std::endl << "Введите номер требуемого пункта подменю: ";
}
//Функция проверки ввода из потока std::cin целочисленного значения
//Value - ссылка на переменную в которую осуществляется ввод
//LeftBorder - левая граница области определения вводимой переменной
//LeftIncluded - признак включения в область определения переменной левой границы
//RightBorder - правая граница области определения вводимой переменной
//RightIncluded - признак включения в область определения переменной правой границы
void CheckCinInt(int &Value, const int LeftBorder, const bool LeftIncluded, const int RightBorder, const bool RightIncluded)
{
	while ((LeftIncluded==true)?(Value<LeftBorder):(Value<=LeftBorder) || (RightIncluded == true) ? (Value>RightBorder) : (Value >= RightBorder) || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());//Очистка буфера
		std::cout << std::endl << "Значение введено неверно, введите еще раз: ";
		std::cin >> Value;
	}
}
//Функция проверки ввода из потока std::cin значения типа char
//Value - ссылка на переменную в которую осуществляется ввод
//LeftBorder - левая граница области определения вводимой переменной
//LeftIncluded - признак включения в область определения переменной левой границы
//RightBorder - правая граница области определения вводимой переменной
//RightIncluded - признак включения в область определения переменной правой границы
void CheckCinChar(char &Value, const char LeftBorder, const bool LeftIncluded, const char RightBorder, const bool RightIncluded)
{
	while ((LeftIncluded == true) ? (Value<LeftBorder) : (Value <= LeftBorder) || (RightIncluded == true) ? (Value>RightBorder) : (Value >= RightBorder) || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());//Очистка буфера
		std::cout << std::endl << "Значение введено неверно, введите еще раз: ";
		std::cin >> Value;
	}
}
//Функция меню
void Menu()
{
	char C = -1;
	int Index, C2;
	while (C != 'д')//д - выход
	{
		ShowMenu();
		std::cin >> C;
		CheckCinChar(C, 'а', true, 'д', true);//проверка корректности ввода
		switch (C)
		{
		case 'а'://Добавить объект
			C2 = -1;
			while (C2 != 3)//3 - выход
			{
				ShowMenu2();
				std::cin >> C2;
				CheckCinInt(C2, 1, true, 3, true);//проверка корректности ввода
				switch (C2)
				{
				case 1://Значения по умолчанию
					new Fraction();
					break;
				case 2://Ввод значений числителя и знаменателя
					std::cout << "Числитель: ";
					int N, D;
					std::cin >> N;
					CheckCinInt(N, INT_MIN, true, INT_MAX, true);//проверка корректности ввода
					std::cout << "Знаменатель: ";
					std::cin >> D;
					CheckCinInt(D, INT_MIN, true, INT_MAX, true);//проверка корректности ввода
					new Fraction(N, D);
					break;
				}//switch (C2)
			}//while (C2 != 3)//3 - выход
			break;
		case 'б'://Ввод новых значений для объекта с заданным номером
			std::cout << "Введите номер объекта: ";
			std::cin >> Index;
			if (Index < 0 || Index >= Fraction::GetSize())
			{
				std::cout << "Отсутствует элемент с указанным номером" << std::endl;
				break;
			}
			std::cout << "Числитель: ";
			int N, D;
			std::cin >> N;
			CheckCinInt(N, INT_MIN, true, INT_MAX, true);//проверка корректности ввода
			std::cout << "Знаменатель: ";
			std::cin >> D;
			CheckCinInt(D, INT_MIN, true, INT_MAX, true);//проверка корректности ввода
			Fraction::SetNumerator(N, Index);
			Fraction::SetDenominator(D, Index);
			break;
		case 'в'://Удалить объект
			if (Fraction::GetSize() == 0)
			{
				std::cout << "Сначала добавьте объекты" << std::endl;
				break;
			}
			std::cout << "Введите номер удаляемого объекта: ";
			std::cin >> Index;
			if (Index < 0 || Index >= Fraction::GetSize())
			{
				std::cout << "Отсутствует элемент с указанным номером" << std::endl;
				break;
			}
			Fraction::delElem(Index);
			break;
		case 'г'://Показать все объекты
			Fraction::PrintAll();
			break;
		case 'д'://Выход
			Fraction::clearArray();
			break;
		}//switch (C)
	}//while (C != 'д')//д - выход
}