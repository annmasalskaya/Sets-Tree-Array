#include "setArray.h"
#include<iostream>
using namespace std;

// ArrayIterator

ArrayIterator::ArrayIterator():
    owner(0), current(0)
{}

ArrayIterator::ArrayIterator(SetArray *own, void *pointer):
    owner(own), current(pointer)
{}

ArrayIterator::~ArrayIterator()
{
    owner = 0;
    current = 0;
}

int& ArrayIterator::operator*()
{
    return owner->asterisc(current);
}

ArrayIterator ArrayIterator::operator++()
{
    owner->next(current);
    return *this;
}

ArrayIterator ArrayIterator::operator++(int)
{
    ArrayIterator result(*this);
    ++(*this);
    return result;
}

ArrayIterator ArrayIterator::operator--()
{
    owner->previous(current);
    return *this;
}

ArrayIterator ArrayIterator::operator--(int)
{
    ArrayIterator result(*this);
    --(*this);
    return result;
}

bool ArrayIterator::operator==(const ArrayIterator &other)
{
    return owner == other.owner && current== other.current;
}

bool ArrayIterator::operator!=(const ArrayIterator &other)
{
    return !(*this==other);
}

//  SetArray


SetArray::SetArray(int n):
    array(0),length(n)
{
    array=new int[n];
}

SetArray::SetArray(const SetArray & original):
    array(0),length(original.length)
{
    array = new int[original.length];
    for(int i = 0; i < original.length; i++)
        array[i] = original.array[i];

}

SetArray::~SetArray()
{
    delete [] array;
    array=0;
}

void SetArray::insertElementVirt(int value)
{
    insertElement(value);
}

bool SetArray::findElementVirt(int value)
{
    if(findElement(value)) return true;
    else return false;
}

void SetArray::insertElement(int value)
{
    int *temp=new int [length];;
    for(int i = 0; i < length; i++)
        temp[i]=array[i];
    array=new int [length+1];
    for(int i = 0; i < length; i++)
        array[i]=temp[i];
    array[length]=value;
    length++;

}

bool SetArray::findElement(int value)
{
    int k=0;
    for( int i=0; i<length; i++)
        if(array[i]==value) k++;
    if(k) return true;
    else return false;
}

SetArray & SetArray::operator=(const SetArray &original)
{
    if(this==&original)
        return *this;
    delete [] array;
    length = original.length;
    array = new int[length];
    for(int i = 0; i < length; ++i)
        array[i] = original.array[i];

    return *this;
}

int SetArray::numberOfSameElem(const SetArray a,int &count)
{
    bool k= true;
    for(int i= 0; i< a.length; ++i)
    {
        for(int j = 0; j< length && k; ++j)
            if(array[j] == a.array[i])
                k = false;
        if(k)
            ++count;
        k = true;
    }
    return count;

}

SetArray &SetArray::operator+(const SetArray &original)
{
    if(this!=&original)
    {

        int count= 0;
        numberOfSameElem(original,count);

        SetArray *unionSet= new SetArray(length +count);
        for(int i = 0; i < length; ++i)
            unionSet->array[i] = array[i];

        count=0;
        bool k= true;
        for(int i = 0; i < original.length && count != unionSet->length; ++i)
        {
            for(int j = 0; j < length && k; ++j)
                if(array[j] == original.array[i])
                    k = false;
            if(k)
            {
                unionSet->array[length + count] = original.array[i];
                ++count;
            }
            k= true;
        }
        return *unionSet;
    }
    else
        return *this;
}

SetArray & SetArray::operator-(const SetArray &original)
{

    if(this != &original)
    {
        int count=0;
        numberOfSameElem(original,count);
        int temp=length+original.length;
        temp-=count;

        SetArray *differenceSet=new SetArray(count);
        if(!count)
            return *differenceSet;

        bool k = true;
        count = 0;
        for(int i = 0; i < length && count != differenceSet->length; ++i)
        {
            for(int j = 0; j < original.length && k; ++j)
                if(array[i] == original.array[j])
                    k= false;
            if(k)
            {
                differenceSet->array[count] = array[i];
                ++count;
            }
            k= true;
        }
        return *differenceSet;
    }
    else
        return *this;
}

SetArray &SetArray::operator*(const SetArray &original)
{
    if(this!= &original)
    {
        int count = 0;
        numberOfSameElem(original,count);
        SetArray *intersectionSet= new SetArray(count);
        if(!count) return *intersectionSet;
        count=0;
        bool k = true;
        for(int i= 0; i< original.length && count!= intersectionSet->length; ++i)
        {
            for(int j = 0; j < length && k; ++j)
            {
                if(array[j] == original.array[i])
                    k= false;
            }
            if(!k)
            {
                intersectionSet->array[count] = original.array[i];
                ++count;
            }
            k= true;
        }
        return *intersectionSet;
    }
    else
        return *this;
}

istream & operator >> (istream & in, SetArray &ar)
{
    for(int i = 0; i < ar.length; ++i)
        in >> ar.array[i];
    return in;
}

ostream & operator << (ostream &out, const SetArray &ar )
{
    for(int i = 0; i < ar.length; ++i)
        out << ar.array[i] << " ";
    cout<<endl;
    return out;
}
//------------------

int& SetArray::asterisc(void *ar)
{
    int* temp=(int*)ar;
    return *temp;
}

void SetArray::next(void *&ar)
{
    int* temp=(int*)ar;
    temp++;
    ar=temp;
}

void SetArray::previous(void *&ar)
{
    int* temp=(int*)ar;
    temp--;
    ar=temp;
}

ArrayIterator SetArray::begin()
{
    return ArrayIterator(this, beginImpl());
}

ArrayIterator SetArray::end()
{
    return ArrayIterator(this, endImpl());
}

void* SetArray::beginImpl()
{
    int *temp=array;
    return (void*)temp;
}

void* SetArray::endImpl()
{
    int *temp=(array+length);
    return (void*)temp;
}


