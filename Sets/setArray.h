#ifndef SETARRAY_H
#define SETARRAY_H
#include <iostream>
#include "set_nvi.h"


class SetArray: public NVI
{
    int *array;
    int length;
public:

    SetArray(int);
    SetArray(const SetArray &);
    ~SetArray();

    void insertElement(int); // вставка элемента
    bool findElement(int); // поиск на наличие элемента


    SetArray & operator = (const SetArray &);
    SetArray & operator + (const SetArray &);
    SetArray & operator - (const SetArray &);
    SetArray & operator * (const SetArray &);

    friend std::istream & operator >> (std::istream &, SetArray &);
    friend std::ostream & operator << (std::ostream &, const SetArray &);

    int numberOfSameElem(const SetArray,int &);

private:

    void insertElementVirt(int);
    bool findElementVirt(int);

};


#endif
