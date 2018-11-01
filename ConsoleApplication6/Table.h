#pragma once
#include <vector>
class Table
{
private:
	int tSize, nSize;
	double coef, count;
	std::vector<int> index;
	std::vector<int> value;
	std::vector<int> numbers;

	void gen_index();

public:
	Table(int m);

	int SearchNum(int);// ����� �����, ���� ����� ���� ���������� ������, ���� ���, �� ����� -1
	void GenValues();//���������� � ������� ������� ��������������� ������
	void Add(int);// ���������� ����������� ����� � �������
	void NumInsert(int,int);// ������� ����� � �������
	int GenKey(int);// �������� ����� ��� ����������� ��������
	void GenNumbers();// ��������� ��������� �����
	void CheckFull();// �������� ������������� �������
	void Change(int, int);
	void DeleteOnIndex(int);
	void DeleteNum(int);


	void Info();

	virtual ~Table();

};

