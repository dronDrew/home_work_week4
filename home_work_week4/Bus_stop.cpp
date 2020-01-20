#include "Bus_stop.h"
Bus_stop::People_on_busstation::People_on_busstation(int people) {
	this->people = people;
	this->next_inline = nullptr;
}
Bus_stop::time::time(int time) {
	this->average = time;
	this->nexttime = nullptr;
}
Bus_stop::Bus_stop(int average_people_come, int average_bus_com, int max_on_bus_stop) {
	this->bus_come = average_bus_com;
	this->time_people_come = average_people_come;
	this->max_on_bus_stop = max_on_bus_stop;
	this->stand = nullptr;
	this->t = nullptr;
}
void Bus_stop::Add(int people) {
	People_on_busstation* temp;
	if (this->stand == nullptr) {
		this->stand = new People_on_busstation(people);
	}
	else
	{
		temp = this->stand;
		while (temp->next_inline!=nullptr)
		{
			temp = temp->next_inline;
		}
		temp->next_inline = new People_on_busstation(people);
	}
}
void Bus_stop::Pop() {
	People_on_busstation* temp;
	if (this->stand == nullptr) {
	}
	else
	{
		temp = this->stand->next_inline;
		People_on_busstation* temp_second= this->stand;
		delete temp_second;
		temp_second = nullptr;
		this->stand = temp;
	}
}
int Bus_stop::Sum_of_pasenger() {
	People_on_busstation* temp;
	if (this->stand == nullptr) {
		return 0;
	}
	else
	{
		int res = 0;
		temp = this->stand;
		while (temp!=nullptr)
		{
			res += temp->people;
			temp = temp->next_inline;
		}
		return res;
	}
}
void Bus_stop::Push_to_time(int info) {
	time* temp;
	if (this->t == nullptr) {
		t = new time(info);
	}
	else
	{
		temp = this->t;
		while (temp->nexttime != nullptr)
		{
			temp = temp->nexttime;
		}
		temp->nexttime= new time(info);
	}
}
int Bus_stop::average_time() {
	time* temp;
	if (this->t == nullptr) {
		return 0;
	}
	else
	{
		int i{0}, res{ 0 };
		temp = this->t;
		while (temp!=nullptr)
		{
			i++;
			res += temp->average;
			temp = temp->nexttime;
		}
		return res / i;
	}
}
void Bus_stop::Model() {
	int time_cicle = 60 * 24;
	int time = 0;
	while (time_cicle>0)
	{
		if (!(time_cicle%this->time_people_come))
		{
			this->Add();
			
		}
		if (!(time_cicle % this->bus_come)) {
			if (Sum_of_pasenger()<=this->max_on_bus_stop)
			{
				this->Push_to_time(time);
				time = 0;
			}
			else {
			
			}
			this->Pop();
		}
		time++;
		time_cicle--;
	}
	if (this->average_time()) {
		
		std::cout << "The average time of waiting is : "<< this->average_time()<<std::endl;
	}
	else
	{
		std::cout << "The time of bus is optimise!\n";
	}
}