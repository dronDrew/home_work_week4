#include "Printing_server.h"
Printing_server::Printing_docum::Printing_docum(int client, int priore, int time) {
    this->client = client;
    this->priore = priore;
    this->time = time;
    this->nextdocum = nullptr;
    this->priviosdocum = nullptr;
}
Printing_server::Printing_server() {
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
        while (temp != nullptr)
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
        if (this->docum->nextdocum == nullptr) {
            if (priore < this->docum->priore) {
                Printing_docum* temp = new Printing_docum(client, priore, time);
                temp->nextdocum = this->docum;
                this->docum = temp;
            }
            else
            {
                Printing_docum* temp = new Printing_docum(client, priore, time);
                temp->priviosdocum = this->docum;
                this->docum->nextdocum = temp;
            }
        }
        else
        {
            Printing_docum* temp = this->docum;
            while (priore < temp->priore) {
                temp = temp->nextdocum;
            }
            Printing_docum* temp2 = temp->nextdocum;
            Printing_docum* newNode = new Printing_docum(client, priore, time);
            newNode->priviosdocum = temp;
            newNode->nextdocum = temp2;
            temp->nextdocum = newNode;
            temp2->priviosdocum = newNode;

        }
    }

}
void Printing_server::Show() {
    Printing_docum* temp;
    if (this->docum == nullptr) {
        std::cout << "Documents was not printing\n";
    }
    else
    {
        temp = this->docum;
        while (temp != nullptr)
        {
            std::cout << "Client : " << temp->client << std::endl;
            std::cout << "Priore : " << temp->priore << std::endl;
            std::cout << "Time   : " << temp->time << std::endl;
            temp = temp->nextdocum;
        }
    }
}
void Printing_server::Add_tostory(int client, int priore, int time) {
    if (this->deleted_docum == nullptr) {
        this->deleted_docum = new Printing_docum(client, priore, time);
    }
    else
    {
        Printing_docum* temp = this->deleted_docum;
        if (temp->nextdocum == nullptr) {
            temp->nextdocum = new Printing_docum(client, priore, time);
            temp->nextdocum->priviosdocum = temp;
            this->deleted_docum = temp;
        }
        else {
            while (temp->nextdocum != nullptr)
            {
                temp = temp->nextdocum;
            }
            temp->nextdocum = new Printing_docum(client, priore, time);
            temp->nextdocum->priviosdocum = temp;
        }
    }


}
void Printing_server::Pop() {
    if (this->docum == nullptr) {
    }
    Printing_docum* temp = this->docum;
    if (temp->nextdocum == nullptr && temp->priviosdocum == nullptr) {
        Add_tostory(temp->client, temp->priore, temp->time);
        delete temp;
        temp = nullptr;
        this->docum = temp;
    }
    else
    {
        temp = this->docum->nextdocum;
        Add_tostory(temp->priviosdocum->client, temp->priviosdocum->priore, temp->priviosdocum->time);
        delete temp->priviosdocum;
        temp->priviosdocum = nullptr;
        this->docum = temp;
    }

}
