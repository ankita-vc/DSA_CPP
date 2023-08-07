#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

class SinglyLL
{
    private:
        PNODE First;   // Characteristics
        int iCount;    // a characteristic to reduce time coplexity

    public:
        SinglyLL();    // declaration of constructor

        void InsertFirst(int no);  // Declaration of all functions
        void InsertLast(int no);
        void InsertAtPos(int no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
        
};

// Implementation of all behaviours

/*

    Return_Value Class_Name : Function_Name(Parameters)
    {
        Function_Body;
    }

*/

// These all 

void SinglyLL :: InsertFirst(int no)
{}

void SinglyLL :: InsertLast(int no)
{}

void SinglyLL :: InsertAtPos(int no, int iPos)
{}

void SinglyLL ::  DeleteFirst()
{}

void SinglyLL ::  DeleteLast()
{}

void SinglyLL ::  DeleteAtPos(int iPos)
{}

void SinglyLL :: Display()
{}

int SinglyLL :: Count()
{
    return 0;
}

SinglyLL :: SinglyLL()
{
    cout<<"inside constuctor\n";

    First= NULL;
    iCount= 0;
}

// This is only naked function
int main()
{
    SinglyLL obj1;
    SinglyLL obj2;

  //  cout<<"Size of LL is:"<<obj1.iCount<<"\n";  Not Accesible because of abstraction

    return 0;
}