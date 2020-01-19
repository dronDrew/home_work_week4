#pragma once
#include "dependies.h"
class string_check
{
	class element_check
	{
	public:
		char data;
		element_check* next_adress;
		element_check(char data);
	};
	public:
	element_check* top;
	string_check(const char*);
	void Add_elem(char a);
	void Pop_elem();
	bool is_corect();
	void show();
	char last();

};

