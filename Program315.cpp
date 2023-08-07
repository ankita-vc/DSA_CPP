#include<iostream>
using namespace std;

typedef class node   // **** for automatic initialization of characteristics
{ 
    public:
    int data;
    struct node *next;
    struct node *prev;

    node()  // no need to add default constructor but it is good practice to add d. cons when we define parametrised constructor
    {
        data= 0;
        next= NULL;
        prev= NULL;
    }

    node(int iValue)  // here the charcteristics get intialized
    {
        data= iValue;
        next= NULL;
        prev= NULL;

    }
}NODE, *PNODE;

class DoublyCL
{
    private:
    PNODE First;
    PNODE Last;
    int iCount;

    public:
        DoublyCL();
        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPosition(int iNo, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int iPos);
        void Display();
        int Count();
        ~DoublyCL();
};

DoublyCL :: DoublyCL()
{

}

void DoublyCL :: InsertFirst(int iNo)
{}

void DoublyCL :: InsertLast(int iNo)
{
    
}

void DoublyCL :: InsertAtPosition(int iNo, int iPos)
{
    
}

void DoublyCL :: DeleteFirst()
{
    
}

void DoublyCL :: DeleteLast()
{
    
}

void DoublyCL :: DeleteAtPosition(int iPos)
{
    
}

void DoublyCL :: Display()
{
    
}

int DoublyCL :: Count()
{
    return iCount;;
}

int main()
{
    DoublyCL obj;
    
    return 0;
}