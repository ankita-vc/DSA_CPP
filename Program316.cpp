#include<iostream>
using namespace std;

typedef class node   
{ 
    public:
    int data;
    struct node *next;
    struct node *prev;

    node()
    {
        data= 0;
        next= NULL;
        prev= NULL;
    }

    node(int iValue)
    {
        data= iValue;
        next= NULL;
        prev= NULL;

    }
}NODE, *PNODE;

// concept of interface
class LinkedList  // Abstract class / base class which is coomon for all LL
{
    public:
        PNODE First;
        int iCount;
        
        virtual void InsertFirst(int iNo)= 0; // abstract function/ pure virtual functions
        virtual void InsertLast(int iNo)= 0;
        virtual void InsertAtPosition(int iNo, int iPos)= 0;

        virtual void DeleteFirst()= 0;
        virtual void DeleteLast()= 0;
        virtual void DeleteAtPosition(int iPos)= 0;

        void Display()  // no change in linear and circular LL because of Count();
        {
            PNODE temp= First;
            for(int iCnt= 1; iCnt <= iCount; iCnt++)
            {
                cout<<"|"<<temp->data<<"|->";
                temp= temp->next;
            }
            cout<<"|NULL|"<<"\n";
        }

        int Count()
        {
            return iCount;
        };
};

class DoublyCL : public LinkedList
{
    private:
        PNODE First;
        PNODE Last;
        int iCount;

    public:
        DoublyCL();
        ~DoublyCL();
        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPosition(int iNo, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int iPos);
};

DoublyCL :: DoublyCL()
{}

DoublyCL :: ~DoublyCL()
{}

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

int main()
{
    DoublyCL obj;
    
    return 0;
}