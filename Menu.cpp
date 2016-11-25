#include "Fraction.h"
//������� ����������� ����
void ShowMenu()
{
	std::cout << std::endl << "������������ ������ �3 (���)";
	std::cout << std::endl << "[�]. �������� ������";
	std::cout << std::endl << "[�]. ���� ����� �������� ��� ������� � �������� �������";
	std::cout << std::endl << "[�]. ������� ������";
	std::cout << std::endl << "[�]. �������� ��� �������";
	std::cout << std::endl << "[�]. �����";
	std::cout << std::endl << "������� ����� ���������� ������ ����: ";
}
//������� ����������� ������� ���������� �������
void ShowMenu2()
{
	std::cout << std::endl << "[1]. �������� �� ���������";
	std::cout << std::endl << "[2]. ���� �������� ��������� � �����������";
	std::cout << std::endl << "[3]. �����";
	std::cout << std::endl << "������� ����� ���������� ������ �������: ";
}
//������� �������� ����� �� ������ std::cin �������������� ��������
//Value - ������ �� ���������� � ������� �������������� ����
//LeftBorder - ����� ������� ������� ����������� �������� ����������
//LeftIncluded - ������� ��������� � ������� ����������� ���������� ����� �������
//RightBorder - ������ ������� ������� ����������� �������� ����������
//RightIncluded - ������� ��������� � ������� ����������� ���������� ������ �������
void CheckCinInt(int &Value, const int LeftBorder, const bool LeftIncluded, const int RightBorder, const bool RightIncluded)
{
	while ((LeftIncluded==true)?(Value<LeftBorder):(Value<=LeftBorder) || (RightIncluded == true) ? (Value>RightBorder) : (Value >= RightBorder) || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());//������� ������
		std::cout << std::endl << "�������� ������� �������, ������� ��� ���: ";
		std::cin >> Value;
	}
}
//������� �������� ����� �� ������ std::cin �������� ���� char
//Value - ������ �� ���������� � ������� �������������� ����
//LeftBorder - ����� ������� ������� ����������� �������� ����������
//LeftIncluded - ������� ��������� � ������� ����������� ���������� ����� �������
//RightBorder - ������ ������� ������� ����������� �������� ����������
//RightIncluded - ������� ��������� � ������� ����������� ���������� ������ �������
void CheckCinChar(char &Value, const char LeftBorder, const bool LeftIncluded, const char RightBorder, const bool RightIncluded)
{
	while ((LeftIncluded == true) ? (Value<LeftBorder) : (Value <= LeftBorder) || (RightIncluded == true) ? (Value>RightBorder) : (Value >= RightBorder) || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());//������� ������
		std::cout << std::endl << "�������� ������� �������, ������� ��� ���: ";
		std::cin >> Value;
	}
}
//������� ����
void Menu()
{
	char C = -1;
	int Index, C2;
	while (C != '�')//� - �����
	{
		ShowMenu();
		std::cin >> C;
		CheckCinChar(C, '�', true, '�', true);//�������� ������������ �����
		switch (C)
		{
		case '�'://�������� ������
			C2 = -1;
			while (C2 != 3)//3 - �����
			{
				ShowMenu2();
				std::cin >> C2;
				CheckCinInt(C2, 1, true, 3, true);//�������� ������������ �����
				switch (C2)
				{
				case 1://�������� �� ���������
					new Fraction();
					break;
				case 2://���� �������� ��������� � �����������
					std::cout << "���������: ";
					int N, D;
					std::cin >> N;
					CheckCinInt(N, INT_MIN, true, INT_MAX, true);//�������� ������������ �����
					std::cout << "�����������: ";
					std::cin >> D;
					CheckCinInt(D, INT_MIN, true, INT_MAX, true);//�������� ������������ �����
					new Fraction(N, D);
					break;
				}//switch (C2)
			}//while (C2 != 3)//3 - �����
			break;
		case '�'://���� ����� �������� ��� ������� � �������� �������
			std::cout << "������� ����� �������: ";
			std::cin >> Index;
			if (Index < 0 || Index >= Fraction::GetSize())
			{
				std::cout << "����������� ������� � ��������� �������" << std::endl;
				break;
			}
			std::cout << "���������: ";
			int N, D;
			std::cin >> N;
			CheckCinInt(N, INT_MIN, true, INT_MAX, true);//�������� ������������ �����
			std::cout << "�����������: ";
			std::cin >> D;
			CheckCinInt(D, INT_MIN, true, INT_MAX, true);//�������� ������������ �����
			Fraction::SetNumerator(N, Index);
			Fraction::SetDenominator(D, Index);
			break;
		case '�'://������� ������
			if (Fraction::GetSize() == 0)
			{
				std::cout << "������� �������� �������" << std::endl;
				break;
			}
			std::cout << "������� ����� ���������� �������: ";
			std::cin >> Index;
			if (Index < 0 || Index >= Fraction::GetSize())
			{
				std::cout << "����������� ������� � ��������� �������" << std::endl;
				break;
			}
			Fraction::delElem(Index);
			break;
		case '�'://�������� ��� �������
			Fraction::PrintAll();
			break;
		case '�'://�����
			Fraction::clearArray();
			break;
		}//switch (C)
	}//while (C != '�')//� - �����
}