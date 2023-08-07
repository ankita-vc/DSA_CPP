#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

class SinglyLL
{
    public:
        PNODE First;   // Characteristics
        int iCount;    // a characteristic to reduce time coplexity
    
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

int main()
{
    SinglyLL obj1();
    
    return 0;
}