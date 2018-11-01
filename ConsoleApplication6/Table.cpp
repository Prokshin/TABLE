#include "pch.h"
#include "Table.h"
#include <iostream>

Table::Table(int m)
{
	tSize = 1.5*m;
	nSize = m;
	gen_index();
}

void Table::gen_index()
{

	for (int i = 0; i < tSize; i++)
	{
		index.push_back(i);
		value.push_back(0);
	}
}


int Table::SearchNum(int num)
{
	int index = -1;
	for (int i = 0; i < tSize; i++)
	{
		if (value[i] == num) 
		{
			index = i;
			break;
		}
	}
	return index;
}

void Table::GenValues()
{
	int temp;

	for (int i = 0; i < nSize; i++)
	{
		temp = GenKey(numbers[i]);

		NumInsert(temp, numbers[i]);
	}
}

void Table::Add(int num)
{
	if (SearchNum(num) != -1) 
	{
		std::cout << "\n||   This number is already in the table. ||\n";
	}
	else 
	{
		int key = GenKey(num);
		CheckFull();
		NumInsert(key, num);
	}
}

void Table::NumInsert(int key,int num)
{
	if (value[key] == 0)
	{
		value[key] = num;
	}
	else
	{
		int j = key;
		while (value[j] != 0)
		{
			j++;
			count++;
			if (value.size() - j == 0)
			{
				j = 0;

			}
		}
		value[j] = num;
	}
}

int Table::GenKey(int num)
{
	int key = ((num * num) % 1000) % tSize;
	return key;
}

void Table::GenNumbers()
{
	for (int i = 0; i < nSize; i++)
	{
		numbers.push_back(rand() % 899 + 100);
	}
}

void Table::CheckFull()
{
	int flag = 0;
	for (int i = 0; i < tSize; i++)
	{
		if (value[i] == 0) 
		{
			flag++;
		}
	}
	if (tSize - flag == 0) 
	{
		tSize++;
		index.push_back(tSize+1);
		value.push_back(0);
	}
}

void Table::Change(int oldNum, int newNum)
{
	DeleteNum(oldNum);
	Add(newNum);
}

void Table::DeleteOnIndex(int index)
{
	if (value[index] == 0)
	{
		std::cout << "\n||   This index empty||\n";
	}
	else if(value[index] == -1)
	{
		std::cout << "\n||   This number was deleted||\n";
	}
	else 
	{
		value[index] = -1;
	}
}

void Table::DeleteNum(int num)
{
	int index = SearchNum(num);
	if (index != -1)
	{
		value[index] = -1;
	}
	else
	{
		std::cout << "\n||   This number is not in the tableþ ||\n";
	}
}



void Table::Info()
{
	double empty = 0;
	for (int i = 0; i < this->tSize; i++) {
		if (value[i] == 0)
		{
			empty++;
		}
		std::cout.width(4);
		std::cout << index[i] << " | ";
		std::cout << value[i] << "\n";
	}
	coef = double((tSize - empty) / tSize);
	count = double(count / tSize);
	std::cout << "_________________________________\n\n";
	std::cout << "coefficient= " << coef << "\n";
	std::cout << "count = " << count << "\n\n";
}


Table::~Table()
{
}