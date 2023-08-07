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
    PNODE temp= First;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        temp= First;
        First= First->next;
        delete temp;
    }
}

// This is only naked function
int main()
{
    SinglyLL obj;
    int iChoice= 0;
    int iValue= 0;
    int iPosition= 0;

    cout<<"Marvellous LinkedList Application"<<"\n";

    while(1)  // unconditional loop
    {
        cout<<"------------------------------------\n";

        cout<<"Plese enter your choice:\n";

        cout<<"------------------------------------\n";

        cout<<"1: Insert at first Position\n";
        cout<<"2' Insert at last position\n";
        cout<<"3' Insert at given position\n";

        cout<<"4' Delete from first position\n";
        cout<<"5' Insert from last position\n";
        cout<<"6' Delete from given position\n";

        cout<<"7' Display LL:\n";
        cout<<"8' Count the elements of LL:\n";

        cout<<"9' Terminate the Appliationn\n";

        cout<<"------------------------------------\n";

        cin>>iChoice;

        cout<<"------------------------------------\n";

        switch(iChoice)
        {
            case 1:
                cout<<"enetr the value that you want to insert:\n";
                cin>>iValue;
                obj.InsertFirst(iValue);
                break;

            case 2:
                cout<<"enetr the value that you want to insert:\n";
                cin>>iValue;
                obj.InsertLast(iValue);
                break;

            case 3:
                cout<<"enetr the value that you want to insert:\n";
                cin>>iValue;
                cout<<"enetr the POsition at which you want to insert the ode:\n";
                cin>>iPosition;
                obj.InsertAtPos(iValue, iPosition);
                break;  

            case 4:
                obj.DeleteFirst();
                break;

            case 5:
                obj.DeleteLast();
                break;  

            case 6:
                cout<<"enetr the Position that you want to delete:\n";
                cin>>iPosition;
                obj.DeleteAtPos(iPosition);
                break; 

            case 7:
                obj.Display();
                break;

            case 8:
                cout<<"Number of elements are:"<<obj.Count()<<"\n";
                break; 

            case 9:
                cout<<"Thank you for using Application..!\n";
                break;  

            default:
                cout<<"Invalid Choice\n";
                break;                     
        }
    }
    return 0;
}