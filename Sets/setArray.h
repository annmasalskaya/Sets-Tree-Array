#ifndef SETARRAY_H
#define SETARRAY_H
#include <iostream>
#include "set_nvi.h"

class ArrayIterator;

class SetArray: public NVI
{
    int *array;
    int length;
public:
    friend class ArrayIterator;

    SetArray(int);
    SetArray(const SetArray &);
    ~SetArray();

    void insertElement(int); // вставка элемента
    bool findElement(int); // поиск на наличие элемента
    int numberOfSameElem(const SetArray,int &);

    SetArray & operator = (const SetArray &);
    SetArray & operator + (const SetArray &);
    SetArray & operator - (const SetArray &);
    SetArray & operator * (const SetArray &);
    friend std::istream & operator >> (std::istream &, SetArray &);
    friend std::ostream & operator << (std::ostream &, const SetArray &);

    ArrayIterator begin();
    ArrayIterator end();

private:

    void insertElementVirt(int);
    bool findElementVirt(int);

    int& asterisc(void *);
    void next(void *&);
    void previous(void*&);
    //Implementation
    void* beginImpl();
    void* endImpl();
};

class ArrayIterator
{
public:
    friend class SetArray;
    ArrayIterator();
    ~ArrayIterator();

    int& operator * ();
    ArrayIterator operator ++ ();
    ArrayIterator operator ++ (int);
    ArrayIterator operator -- ();
    ArrayIterator operator -- (int);

    bool operator == (const ArrayIterator&);
    bool operator !=(const ArrayIterator &);
private:
    SetArray *owner;
    void* current;
    ArrayIterator(SetArray *, void *);
};


#endif
