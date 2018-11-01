// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Table.h"

int main()
{
	Table a(51);

	a.GenNumbers();
	a.GenValues();
	std::cout << "\n_____________________READY TABLE______________________\n";
	a.Info();
	
	a.Add(999);
	std::cout << "\n_______________________ADD NUMBER____________________\n";
	a.Info();
	

	a.Change(999, 777);
	std::cout << "\n____________________CHANGE NUMBER_______________________\n";
	a.Info();
	
	a.Add(999);
	a.DeleteOnIndex(2);
	std::cout << "\n________________________DELETE NUMBER___________________\n";
	a.Info();

	
}

