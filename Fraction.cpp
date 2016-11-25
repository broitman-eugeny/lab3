#include "Fraction.h"
//������������� ����������� ������ ������ Fraction
int Fraction::Size = 0;
AbstractFraction ** Fraction::PFraction = NULL;
//����������� �� ���������
Fraction::Fraction():Numerator(1), Denominator(1)
{
	//�������� ������ ������� ���������� � ���-��� ��-��� �� 1 ������, ��� � PFraction
	AbstractFraction** nArr = new AbstractFraction*[Size + 1];
	//����������� ��� ��-�� PFraction � ����� ������
	for (int i = 0; i < Size; i++)
	{
		nArr[i] = PFraction[i];
	}
	nArr[Size++] = this;//����� ��������� ������� ���� �������� � ������
	if (PFraction != NULL)
	{
		delete[] PFraction;
	}
	PFraction = nArr;//����� ��������� ������ - ���� ������ Fraction
}
//����������� � �����������
Fraction::Fraction(const int N, const int D) : Numerator(N), Denominator(D)
{
	//�������� ������ ������� ���������� � ���-��� ��-��� �� 1 ������, ��� � PFraction
	AbstractFraction** nArr = new AbstractFraction*[Size + 1];
	//����������� ��� ��-�� PFraction � ����� ������
	for (int i = 0; i < Size; i++)
	{
		nArr[i] = PFraction[i];
	}
	nArr[Size++] = this;//����� ��������� ������� ���� �������� � ������
	if (PFraction != NULL)
	{
		delete[] PFraction;
	}
	PFraction = nArr;//����� ��������� ������ - ���� ������ Fraction
}
//����������� �����������
Fraction::Fraction(const Fraction & F) : Numerator(F.Numerator), Denominator(F.Denominator)
{
	//�������� ������ ������� ���������� � ���-��� ��-��� �� 1 ������, ��� � PFraction
	AbstractFraction** nArr = new AbstractFraction*[Size + 1];
	//����������� ��� ��-�� PFraction � ����� ������
	for (int i = 0; i < Size; i++)
	{
		nArr[i] = PFraction[i];
	}
	nArr[Size++] = this;//����� ��������� ������� ���� �������� � ������
	if (PFraction != NULL)
	{
		delete[] PFraction;
	}
	PFraction = nArr;//����� ��������� ������ - ���� ������ Fraction
}
//����������
Fraction::~Fraction()
{
	if (Size == 1)
	{
		delete [] PFraction;//��������� ������ ����������, ��� ������� ��������� � �������� clearArray � delElem ����� ��������� �����������
		PFraction = NULL;
		Size--;
	}
	else
		if(Size > 1 && PFraction[Size - 1] != this)//���� ������� ������� �� � ������������ ��������� ������� � �������
		{
			AbstractFraction** nArr = new AbstractFraction*[Size - 1];
			for (int i = 0, j = 0; i < Size; i++)
			{
				if (PFraction[i] != this)//���������� ���, ����� ��������� �� ��������� �������
				{
					nArr[j++] = PFraction[i];
				}
			}
			delete[] PFraction;//�������� ������� ����������
			PFraction = nArr;//����� ��������� ������n Arr - ���� ������ Fraction
			Size--;
		}
		else
			if (Size > 1 && PFraction[Size - 1] == this)//���� ������� ������� � ������������ ��������� ������� � �������
			{
				Size--;
			}
}
//��������� �������� ��������� �������
void Fraction::SetNumerator(const int N, const int Index)
{
	PFraction[Index]->GetNumerator() = N;
}
//��������� �������� �����������
void Fraction::SetDenominator(const int D, const int Index)
{
	PFraction[Index]->GetDenominator() = D;
}
//���������� ������ �� ��������� (����������� ����������)
int & Fraction::GetNumerator()
{
	return Numerator;
}
//���������� ������ �� ����������� (����������� ����������)
int & Fraction::GetDenominator()
{
	return Denominator;
}
int Fraction::GetSize()
{
	return Size;
}
//����� �� ����� (���������� ����������� �������)
void Fraction::Print()
{
	std::cout << Numerator << "\t\t" << Denominator << std::endl;
}
//����� �� ����� ���� �������� �� ������� ��������� ��������� ������� PFraction
void Fraction::PrintAll()
{
	std::cout << "Size=" << Size << std::endl;
	std::cout << std::endl << "�" << "\t" << "���������" << "\t" << "�����������" << std::endl;
	for (int i = 0; i < Size; i++)
	{
		std::cout << i << "\t";
		PFraction[i]->Print();
	}
}
//�������� ���� ��������, �� ������� ��������� ��������� ������� PFraction
void Fraction::clearArray()
{
	for (int i= Size-1;i>=0;i--)
	{
		delete PFraction[i];
	}
}
//�������� ������� �� ������� ��������� ��������� �� ������� n � ������� PFraction
void Fraction::delElem(const int n)
{
	if (n >= 0 && n < Size)
	{
		delete PFraction[n];
	}
}
