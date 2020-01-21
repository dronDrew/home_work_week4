#pragma once
#include "dependies.h"
class Printing_server
{
    class Printing_docum {
    public:
        int client;
        int priore;
        int time;
        Printing_docum* nextdocum;
        Printing_docum* priviosdocum;
        Printing_docum(int client, int priore, int time);
    };
public:
    Printing_docum* docum;
    Printing_docum* deleted_docum;
    Printing_server();
    void Add(int client, int priore, int time);
    void Add_tostory(int client, int priore, int time);
    void Pop();
    void Show_statictic();
    void Show();
};

