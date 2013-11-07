#ifndef SET_NVI_H
#define SET_NVI_H

struct TreeNode;

class NVI
{
    virtual void insertElement(int)=0; // вставка элемента
    virtual bool findElement(int)=0; // поиск на наличие элемента

public:
    void insertNode(TreeNode*& ,int);
    bool findElement(TreeNode* ,int);

    void insertElementA(int *& ,int&,int);
    bool findElementA(int* ,int);


};

#endif

