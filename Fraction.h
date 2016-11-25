#pragma once
#include <iostream>
#include <Windows.h>
//����������� ������� ����� �����
class AbstractFraction
{
public:
	virtual void Print() = 0;		//����� �� ����� (����� ����������� �������)
	virtual ~AbstractFraction(){}	//����������� ���������� ��� ���������� ������ ������ ��� �������� ������������ ������� �� ��������� �������� ������
	virtual int & GetNumerator()=0;	//���������� �������� ��������� (����� ����������� �������)
	virtual int & GetDenominator()=0;	//���������� �������� ����������� (����� ����������� �������)
};
//����� �����
class Fraction: public AbstractFraction
{
	int Numerator;		//���������
	int Denominator;	//�����������
	static AbstractFraction **PFraction;//Static ������������ ������ ���������� �� ������� �������� (������������) ������
	static int Size;	//������ ������� PFraction
public:
	Fraction();							//����������� �� ���������
	Fraction(const int N, const int D);				//����������� � �����������
	Fraction(const Fraction &F);				//����������� �����������
	virtual ~Fraction();				//����������� ���������� ��� ���������� ������ ������ ��� �������� ������������ ������� �� ��������� �������� ������
	static void SetNumerator(const int N, const int Index);		//��������� �������� ��������� �������, �� ������� ��������� ��������� ������� PFraction �� ������� Index
	static void SetDenominator(const int D, const int Index);	//��������� �������� ����������� �������, �� ������� ��������� ��������� ������� PFraction �� ������� Index
	virtual int & GetNumerator();		//���������� �������� ��������� (�������������� ����� ����������� �������)
	virtual int & GetDenominator();		//���������� �������� ����������� (�������������� ����� ����������� �������)
	static int GetSize();				//���������� ������� ������� PFraction
	virtual void Print();				//����� �� ����� (�������������� ����� ����������� �������)
	static void PrintAll();				//����� �� ����� ���� ��������, ��������� �� ������� ��������� � PFraction
	static void clearArray();			//�������� ���� ��������, �� ������� ��������� ��������� ������� PFraction
	static void delElem(const int n);			//�������� �������, �� ������� ��������� ��������� ������� PFraction �� ������� n
};
//������� ����
void Menu();