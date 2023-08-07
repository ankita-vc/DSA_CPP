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


// this fubction has 6 abstract functions and 2 concrete functions
class LinkedList  
{
    public:
        PNODE First;
        int iCount;

        LinkedList()  // ***
        {
            First= NULL;
            iCount= 0;
        }

        virtual void InsertFirst(int iNo)= 0;
        virtual void InsertLast(int iNo)= 0;
        virtual void InsertAtPosition(int iNo, int iPos)= 0;

        virtual void DeleteFirst()= 0;
        virtual void DeleteLast()= 0;
        virtual void DeleteAtPosition(int iPos)= 0;

        void Display()
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
        }
};

class DoublyCL : public LinkedList
{
    private:
        PNODE Last;

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
{
    Last= NULL;
}

DoublyCL :: ~DoublyCL()
{}

void DoublyCL :: InsertFirst(int iNo)
{}

void DoublyCL :: InsertLast(int iNo)
{}

void DoublyCL :: InsertAtPosition(int iNo, int iPos)
{}

void DoublyCL :: DeleteFirst()
{}

void DoublyCL :: DeleteLast()
{}

void DoublyCL :: DeleteAtPosition(int iPos)
{}

int main()
{
    DoublyCL obj;

    obj.Display();
    cout<<"Length of LL is:"<<obj.Count()<<"\n";
    
    return 0;
}