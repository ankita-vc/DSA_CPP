#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE;

class SinglyLL
{
    private:
        PNODE First;   // Characteristics
        int iCount;    // a characteristic to reduce time coplexity

    public:
        SinglyLL();    // declaration of constructor
        ~SinglyLL();

        void InsertFirst(int no);  // Declaration of all functions
        void InsertLast(int no);
        void InsertAtPos(int no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
        
};

void SinglyLL :: InsertFirst(int no)
{
    PNODE newn= NULL;
    newn= new NODE;  // newn=(PNODE)malloc(sizeof(NODE));
    newn->data= no;
    newn->next= NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next= First;
        First= newn;
    }
    iCount++;
}

void SinglyLL :: InsertLast(int no)
{
    PNODE newn= NULL;
    newn= new NODE;  // newn=(PNODE)malloc(sizeof(NODE));
    newn->data= no;
    newn->next= NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        PNODE temp = First;

        while(temp->next != NULL)
        {
            temp= temp->next;
        }
        temp->next= newn;
    }
    iCount++;
}

void SinglyLL :: InsertAtPos(int no, int iPos)
{
    PNODE newn= NULL;
    newn= new NODE;
    newn->data= no;
    newn->next= NULL;

    if((iPos < 1) && (iPos > iCount+1))
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE temp= First;
        int iCnt= 0;

        for(iCnt= 1; iCnt < iPos-1; iCnt++)
        {
            temp= temp->next;
        }
        newn->next= temp->next;
        temp->next= newn;
        iCount++;
    }
}

void SinglyLL ::  DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;  // delete is operator not a function so no need of brackets 
        First= NULL;
    }
    else
    {
        PNODE temp = First;

        First= First->next;
        delete temp;
    }
    iCount--;   // only applicable for else if and else
}

void SinglyLL ::  DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;  
        First= NULL;
    }
    else
    {
        PNODE temp= First;

        while(temp->next->next != NULL)
        {
            temp= temp->next;
        }
        delete temp->next;
        temp->next= NULL;
    }
    iCount--;
}

void SinglyLL ::  DeleteAtPos(int iPos)
{
    if((iPos < 1) && (iPos > iCount))
    {
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp= First;
        PNODE tempX= NULL;

        for(int iCnt= 1; iCnt < iPos-1; iCnt++)
        {
            temp= temp->next;
        }
        tempX= temp->next;
        temp->next= temp->next->next;
        delete tempX;
        iCount--;
    }
}

void SinglyLL :: Display()
{
    PNODE temp= First;

    cout<<"elements f LL are:"<<"\n";

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|"<<"->";
        temp= temp->next;
    }
    cout<<"NULL"<<"\n";
}

int SinglyLL :: Count()
{
    return iCount;
}

SinglyLL :: SinglyLL()
{
    cout<<"inside constuctor\n";

    First= NULL;
    iCount= 0;
}

SinglyLL :: ~SinglyLL()
{
    cout<<"inside destuctor\n";
}

// This is only naked function
int main()
{
    int iRet= 0;

    SinglyLL obj1;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.Display();
    iRet= obj1.Count();
    cout<<"number of nodes are:"<<iRet<<"\n";

    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.Display();
    iRet= obj1.Count();
    cout<<"number of nodes are:"<<iRet<<"\n";

    obj1.InsertAtPos(55, 4);
    obj1.Display();
    iRet= obj1.Count();
    cout<<"number of nodes are:"<<iRet<<"\n";

    obj1.DeleteAtPos(4);
    obj1.Display();
    iRet= obj1.Count();
    cout<<"number of nodes are:"<<iRet<<"\n";

    obj1.DeleteFirst();
    obj1.Display();
    iRet= obj1.Count();
    cout<<"number of nodes are:"<<iRet<<"\n";

    obj1.DeleteLast();
    obj1.Display();
    iRet= obj1.Count();
    cout<<"number of nodes are:"<<iRet<<"\n";

    return 0;
}