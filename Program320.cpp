#include<iostream>
using namespace std;

typedef class node  
{ 
    public:
    int data;
    node *next;
    node *prev;

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

class LinkedList
{
    public:
        PNODE First;
        int iCount;

        LinkedList()
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
        };
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
{
    PNODE newn= new NODE(iNo);  // from node(int iValue)

    /*
    PNODE newn= new NODE;
    newn->data= iNo;
    newn->next= NULL:
    newn->prev= NULL;
    */

    if((First == NULL) && (Last == NULL))
    {
        First= newn;
        Last= newn;
    }
    else
    {
        newn->next= First;
        First->prev= newn;

        First= newn;
    }
    Last->next= First;
    First->prev= Last;
    iCount++;
}

void DoublyCL :: InsertLast(int iNo)
{
    PNODE newn= new NODE(iNo);

    /*
    PNODE newn= new NODE;
    newn->data= iNo;
    newn->next= NULL:
    newn->prev= NULL;
    */

    if((First == NULL) && (Last == NULL))
    {
        First= newn;
        Last= newn;
    }
    else
    {
        Last->next= newn;
        newn->prev= Last;
        Last= Last->next;
    }
    Last->next= First;
    First->prev= Last;
    iCount++;
}

void DoublyCL :: InsertAtPosition(int iNo, int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE newn= new NODE(iNo);
        PNODE temp= First;

        for(int iCnt= 1; iCnt < iPos-1; iCnt++)
        {
            temp= temp->next;
        }
        newn->next= temp->next;
        temp->next->prev= newn;

        temp->next= newn;
        newn->prev= temp;
        iCount++;
    }
}

void DoublyCL :: DeleteFirst()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete First;
        First= NULL;
        Last = NULL;
    }
    else
    {
        First= First->next;
        delete First->prev;  // delete Last->next;
    }
    First->prev= Last;
    Last->next= First;
    iCount--;
}

void DoublyCL :: DeleteLast()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete First;
        First= NULL;
        Last = NULL;
    }
    else
    {
        Last= Last->prev;
        delete Last->next;
    }
    First->prev= Last;
    Last->next= First;
    iCount--;
}

void DoublyCL :: DeleteAtPosition(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
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

        for(int iCnt= 1; iCnt < iPos-1; iCnt++)
        {
            temp= temp->next;
        }
        temp->next= temp->next->next;
        delete temp->next->prev;
        temp->next->prev= temp;

        iCount--;
    }
}

int main()
{
    DoublyCL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    cout<<"Length of LL is:"<<obj.Count()<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.Display();
    cout<<"Length of LL is:"<<obj.Count()<<"\n";

    obj.InsertAtPosition(55, 3);
    obj.Display();
    cout<<"Length of LL is:"<<obj.Count()<<"\n";

    obj.DeleteAtPosition(3);
    obj.Display();
    cout<<"Length of LL is:"<<obj.Count()<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();
    obj.Display();
    cout<<"Length of LL is:"<<obj.Count()<<"\n";

    return 0;
}