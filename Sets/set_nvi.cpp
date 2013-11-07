#include "set_nvi.h"

// для дерева

void NVI::insertNode(TreeNode*& node ,int value)
{
    insertElement(value);
}
bool NVI::findElement(TreeNode* node ,int value)
{
    bool k=findElement(value);
    return k;
}

////////////////////////////////////////////
// для массива

void NVI::insertElementA(int *&ar ,int &size,int value)
{
    insertElement(value);

}
bool NVI::findElementA(int *ar ,int value)
{
    bool k=findElement(value);
    return k;

}

