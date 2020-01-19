#include "string_check.h"
string_check::element_check::element_check(char data) {
	this->data = data;
	this->next_adress = nullptr;
}
string_check:: string_check(const char* a) {
	this->top = nullptr;
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == 46 || a[i] == 59) {
			std::cout << std::boolalpha << this->is_corect() <<std::endl;
		}
		if (a[i] == 40 || a[i] == 41 || a[i] == 91 || a[i] == 93 || a[i] == 123 || a[i] == 125) {
			if ((last() == 40 && a[i] == 41) || (last() == 91 && a[i] == 93) || (last() == 123 && a[i] == 125)) {
				Pop_elem();
				//show();
			}
			else
			{
				Add_elem(a[i]);
				//show();
				//this->a += a[i];
			}
			
		}


	}
}

void string_check::Add_elem(char a) {
	if (this->top == nullptr) {
		top = new element_check(a);
	}
	else
	{
		element_check* temp = this->top;
		while (temp->next_adress!=nullptr)
		{
			temp = temp->next_adress;
		}
		temp->next_adress = new element_check(a);
	}
}
void string_check::Pop_elem() {
	if (this->top == nullptr) {
		
	}
	else
	{
		int i = 0;
		element_check* temp = this->top;
		while (temp->next_adress != nullptr)
		{
			temp = temp->next_adress;
			i++;
		}
		if (i==0) {
			temp = this->top;
			delete temp;
			temp = nullptr;
			this->top = temp;
		}
		else
		{
			i--;
			temp = this->top;
			while (i > 0)
			{
				i--;
				temp = temp->next_adress;
			}
			delete temp->next_adress;
			temp->next_adress = nullptr;
		}
	}
}
void string_check::show() {
	element_check* temp = this->top;
	while (temp != nullptr)
	{
		std::cout << temp->data << std::endl;
		temp = temp->next_adress;
	}
}
char string_check::last() {
	if (this->top == nullptr) {
		return 0;
	}
	element_check* temp = this->top;
	while (temp->next_adress != nullptr)
	{
		temp = temp->next_adress;
	}
	return temp->data;
}
bool string_check::is_corect() {
	if (this->top==nullptr)
	{
		return true;
	}
	else {
		return false;
	}
}
