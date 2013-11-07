#ifndef SETTREE_H
#define SETTREE_H
#include "set_nvi.h"

class Tree: public NVI
{
  struct TreeNode
    {
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int dt)
        {
            data = dt;
            left= right= 0;
        }

    }*root;

public:

    Tree();
    ~Tree();
    Tree (const Tree &);
    Tree &operator=(const Tree&);
    Tree operator+(const Tree&);
    Tree operator*(const Tree &);
    Tree operator-(const Tree &);

    void insertElement(int);
    bool findElement(int);
    void clearTreeNode();
    void outputTree(int);

 protected:

     // вспомогательные функции
    void insertNode(TreeNode*& ,int);
    bool findElement(TreeNode* ,int);
    void clearTreeNode(TreeNode*&);
    void copyTreeNode(TreeNode*& , TreeNode*);
    void outputTree(TreeNode* ,int);

    void uniteTrees(TreeNode* , TreeNode*&);
    Tree intersectTrees(Tree &,TreeNode *);
    Tree differenceTrees(Tree &,TreeNode *, TreeNode *);


};




#endif
