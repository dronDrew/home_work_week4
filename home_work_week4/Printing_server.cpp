#include "Printing_server.h"
Printing_server::Printing_docum::Printing_docum(int client, int priore, int time) {
	this->client = client;
	this->priore = priore;
	this->time = time;
	this->nextdocum = nullptr;
	this->priviosdocum = nullptr;
}
Printing_server::Printing_server(){
	this->deleted_docum = nullptr;
	this->docum = nullptr;
}
void Printing_server::Show_statictic() {
	Printing_docum* temp;
	if (this->deleted_docum == nullptr) {
		std::cout << "Documents was not printing\n";
	}
	else
	{
		temp = this->deleted_docum;
		while (temp!=nullptr)
		{
			std::cout << "Client : " << temp->client << std::endl;
			std::cout << "Priore : " << temp->priore << std::endl;
			std::cout << "Time   : " << temp->time << std::endl;
			temp = temp->nextdocum;
		}
	}
}
void Printing_server::Add(int client, int priore, int time) {
	if (this->docum == nullptr) {
		this->docum = new Printing_docum(client, priore, time);
	}
	else
	{
		Printing_docum *temp=new Printing_docum(client, priore, time);
		Printing_docum* sercher = this->docum;
		while (priore<sercher->priore)
		{
			sercher = sercher->nextdocum;
		}
		sercher = sercher->nextdocum;
		temp->nextdocum = sercher;
		temp->priviosdocum = sercher->priviosdocum;
		Printing_docum* sercher1 = ;
	}

}