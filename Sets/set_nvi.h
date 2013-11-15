#ifndef SET_NVI_H
#define SET_NVI_H

struct TreeNode;

class NVI
{
protected:
    virtual void insertElementVirt(int)=0;
    virtual bool findElementVirt(int)=0;
public:

    void insertElement(int); // вставка элемента
    bool findElement(int); // поиск на наличие элемента

};

#endif

