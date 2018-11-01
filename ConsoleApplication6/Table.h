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

	int SearchNum(int);// поиск числа, если число есть возвращает индекс, если нет, то число -1
	void GenValues();//добавление в таблицу массива сгенерированных числел
	void Add(int);// добавление переданного числа в таблицу
	void NumInsert(int,int);// вставка числа в таблицу
	int GenKey(int);// создание ключа для переданного значения
	void GenNumbers();// генерация рандомных чисел
	void CheckFull();// проверка заплоненности таблицы
	void Change(int, int);
	void DeleteOnIndex(int);
	void DeleteNum(int);


	void Info();

	virtual ~Table();

};

