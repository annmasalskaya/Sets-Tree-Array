#ifndef SETTREE_H
#define SETTREE_H
#include "set_nvi.h"

class TreeIterator;

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
    friend class TreeIterator;
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

    TreeIterator begin();
    TreeIterator end();
private:

    int &asterisc(void *);
    int &asteriscImpl(void *);
    void next(void *&);
    void nextImpl(void *&);
    void *beginImpl();

    TreeNode *findParent(TreeNode*);

    void insertElementVirt(int);
    bool findElementVirt(int);

    void insertNode(TreeNode*& ,int);
    bool findElement(TreeNode* ,int);
    void clearTreeNode(TreeNode*&);
    void copyTreeNode(TreeNode*& , TreeNode*);
    void outputTree(TreeNode* ,int);

    void uniteTrees(TreeNode* , TreeNode*&);
    Tree intersectTrees(Tree &,TreeNode *);
    Tree differenceTrees(Tree &,TreeNode *, TreeNode *);


};

class TreeIterator
{
public:
    friend class Tree;
    TreeIterator();
    ~TreeIterator();

    int& operator * ();
    TreeIterator operator ++ ();
    TreeIterator operator ++ (int);
    //TreeIterator operator -- ();
    //TreeIterator operator -- (int);
    bool operator == (const TreeIterator&);
    bool operator !=(const TreeIterator &);
private:
    Tree *owner;
    void* current;
    TreeIterator(Tree *, void *);
};





#endif
