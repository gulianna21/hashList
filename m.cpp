#include "Hastable.h"
#include <iostream>

void main()
{
	Table<int,double> t(50);
	t.Add(5.123, 100);
	t.Add(6.123, 500);
	t.Add(7.123, 600);
	t.Add(8.123, 990);

	std::cout << t[100].GetData() << std::endl;
	std::cout << t[500].GetData() << std::endl;
	std::cout << t[600].GetData() << std::endl;
	t.Del(600);
	std::cout << t[990].GetData() << std::endl;
	t.resize(14);
	try {
		std::cout << t[600].GetData() << std::endl;//Îøèáêà
	}
	catch (int e) { std::cout << "error" << e; }
	std::cin.get();

}