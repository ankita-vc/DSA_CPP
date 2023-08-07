#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *Next;
    struct node *prev;
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

void DoublyCL :: InsertFirst(int iNo)
{
    
}

void DoublyCL :: InsertFirst(int iNo)
{
    
}

void DoublyCL :: InsertFirst(int iNo)
{
    
}

void DoublyCL :: InsertFirst(int iNo)
{
    
}

int main()
{

    return 0;
}