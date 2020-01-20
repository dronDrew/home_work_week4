#pragma once
#include "dependies.h"
class Bus_stop
{
	class People_on_busstation {
	public:
		int people;
		People_on_busstation* next_inline;
		People_on_busstation(int people);
	};
	class time {
	public: 
		int average;
		time* nexttime;
		time(int aver);
	};
public:
	Bus_stop(int average_people_come,int average_bus_com,int max_on_bus_stop);
	void Model();
	void Add(int people=1);//
	void Push_to_time(int time);
	void Pop();//
	int Sum_of_pasenger();
	int time_people_come;
	int bus_come;
	int optimal_time;
	int max_on_bus_stop;
	People_on_busstation* stand;
	time* t;
	int average_time();
};

