#include "setTree.h"
#include <iostream>
using namespace std;

Tree::Tree():
    root(0)
{}

Tree::~Tree()
{
    clearTreeNode(root);
}

Tree::Tree (const Tree &original)
{
    if (original.root)
    {
        root=new TreeNode(original.root->data);
        copyTreeNode(root, original.root);
    }
    else root=0;
}

////////////////////////////////////////////////// перегруженные операторы

Tree &Tree::operator=(const Tree &original)
{
    if(this==&original)
        return *this;
    clearTreeNode(root);
    copyTreeNode(root,original.root);
    return *this;
}


Tree Tree::operator+(const Tree &original)
{
    if(this!= &original)
    {
        Tree temp(original);
        uniteTrees(root,temp.root);
        return temp;
    }
    else
        return *this;
}

Tree Tree::operator*(const Tree &original)
{
    if(this!= &original)
    {
        Tree temp;
        intersectTrees(temp,original.root);
        return temp;
    }
    else
        return *this;
}

Tree Tree::operator-(const Tree &original)
{
    Tree temp;
    if(!this && original.root)
    {
        clearTreeNode(temp.root);
        *this=temp;
    }
    else  if(this && !original.root)
        return *this;
    if(this!= &original)
    {
        differenceTrees(temp,root,original.root);
        return temp;
    }
    else
        return *this;
}


/////////////////////////////////////////////////////


void Tree::insertElement(int value)
{
    insertNode(root,value);
}

bool Tree::findElement(int value)
{
    if(findElement(root,value)) return true;
    else return false;
}

void Tree::clearTreeNode()
{
    clearTreeNode(root);
}


//////////////////////////////////////////// вспомогательные функции (функции - утилиты)

void Tree::insertNode(TreeNode *&ptr,int value)
{
    if (ptr== 0)
        ptr= new TreeNode(value);

    else if (value > ptr->data)
        insertNode(ptr->right,value);

    else if (value < ptr->data)
        insertNode(ptr->left,value);

}

bool Tree::findElement(TreeNode *ptr,int value)
{
    if (!ptr) return false;
    else if (ptr->data==value) return true;
    else if (value<ptr->data) return findElement(ptr->left,value);
    else return findElement(ptr->right, value);
}


void Tree::clearTreeNode(TreeNode *&ptr)
{
    if(ptr)
    {
        clearTreeNode(ptr->left);
        clearTreeNode(ptr->right);
        delete ptr;
        ptr=0;
    }
}

void Tree::copyTreeNode(TreeNode *&newTreeNode, TreeNode *original)
{
    if(original==0)
        newTreeNode = 0;

    if (original)
    {
        newTreeNode= new TreeNode(original->data);
        if(original->left)
            copyTreeNode(newTreeNode->left,original->left);
        else
            newTreeNode->left =0;

        if(original->right)
            copyTreeNode(newTreeNode->right,original->right);
        else
            newTreeNode->right =0;
    }
}

void Tree::uniteTrees(TreeNode *other, TreeNode *&result)
{

    if( other)
    {
        insertNode(result,other->data);
        if(other->right)
            uniteTrees(other->right,result);
        if(other->left)
            uniteTrees(other->left, result);
    }
}

Tree Tree::intersectTrees(Tree &tree,TreeNode *ptr)
{
    if(ptr)
    {
        intersectTrees(tree,ptr->left);
        if( findElement(root,ptr->data))
            insertNode(tree.root,ptr->data);   // так как делался обход дерева, то
        intersectTrees(tree,ptr->right);  //  в итоге объединения получается остортированное дерево
    }
    return tree;

}
Tree Tree::differenceTrees(Tree &tree, TreeNode *other,TreeNode *ptr)
{
    if(other)
    {
        differenceTrees(tree,other->left,ptr);
        if(!findElement(ptr,other->data))
            insertNode(tree.root, other->data);
        differenceTrees(tree,other->right,ptr);
    }
    return tree;
}

void Tree::outputTree(int level)
{
   outputTree(root,level);

}
void Tree::outputTree(TreeNode *ptr,int level)
{

    if(ptr)
    {
        outputTree(ptr->left,level+1);
        for(int i=0; i<level; i++)
            cout<<"---";
        cout<<ptr->data<<endl;
        outputTree(ptr->right,level+1);
    }

}
