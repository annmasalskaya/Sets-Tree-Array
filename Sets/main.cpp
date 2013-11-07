#include "setArray.h"
#include "setTree.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{

    SetArray a(2), b(2);
    cin >> a;
    cout<<" #1 :"<< a<<endl;
    cin >> b;
    cout<<" #2 :"<< b<<endl;
    a.insertElement(5);
    //a.findElement(7);
    cout<<" #1 после вставки:"<< a<<endl;
    cout<<endl;
    cout<<"a+b: "<<a+b<<endl;
    cout<<"========================";
    Tree tree1;
    ifstream fin("input");
    short value;
    fin>>value;
    while(!fin.eof())
    {
        tree1.insertElement(value) ;
        fin>>value;
    }
    cout<<"The tree 1 : "<<endl;
    tree1.outputTree(0);
    cout<<endl<<endl;
    cout<<"The tree 2 : "<<endl;
    Tree tree2;
    for( int i=3; i<7; i++)
    {
        tree2.insertElement(i);
    }
    cout<<endl;

    tree2.outputTree(0);
    cout<<endl;
    cout<<"Объединение деревьев 1 и 2:"<<endl;
    cout<<"___________________________"<<endl;
    (tree1+tree2).outputTree(0);
    cout<<endl<<endl;
    cout<<"Объединение деревьев 2 и 1:"<<endl;
    cout<<"___________________________"<<endl;
    (tree2+tree1).outputTree(0);
    cout<<endl<<endl;
    cout<<"Пересечение деревьев 1 и 2 : "<<endl;
    cout<<"___________________________"<<endl;
    (tree1*tree2).outputTree(0);
    cout<<endl;
    cout<<"Разность 1 -2 : "<<endl;
    cout<<"___________________________"<<endl;
    (tree1-tree2).outputTree(0);
    cout<<"Разность 2 -1 : "<<endl;
    cout<<"___________________________"<<endl;
    (tree2-tree1).outputTree(0);


    return 0;
}
