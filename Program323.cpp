#include<iostream>
using namespace std;

typedef class node
{
    public:
    int data;
    node *next;


    node(int value)  // constructor
    {
        data= value;
        next= NULL;
    }

}NODE, *PNODE;

class Stack
{
    private:
        PNODE First;
        int iCount;

    public:
        Stack();
        void Push(int iNo);
        int Pop();
        void Display();
        int Count();
};

Stack :: Stack()
{
    First= NULL;
    iCount= 0;
}

void Stack::Push(int iNo)  // InsertLast
{
    PNODE newn= new NODE(iNo);

        if(First == NULL)
        {
            First= newn;
        }
        else
        {
            PNODE temp= First;
        
            while(temp->next != NULL)
            {
                temp= temp->next;
            }
            temp->next= newn;
        }
        iCount++;
}

int Stack::Pop()  // DeleteLast 
{
    int Value= 0;

    if(iCount == 0)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value= First->data;
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
        Value= temp->next->data;
        delete temp->next;
        temp->next= NULL;
    }
    iCount--;
    return Value;
}

void Stack::Display()
{
    if(First == NULL)
    {
        cout<<"Nothing to Display as Stack is empty\n";
        return;
    }

    cout<<"Elements of Stack are:\n";

    PNODE temp= First;
    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        cout<<temp->data<<"\n";
        temp= temp->next;
    }
    cout<<"\n";
}

int Stack::Count()
{
    return iCount;
}

int main()
{
    int iRet= 0;
    int iChoice= 1; 
    int iValue= 0;

    Stack obj;

    cout<<"---------------------------------------------\n";
    cout<<"Dynamic Implementation of Stack\n";
    cout<<"---------------------------------------------\n";

    while(iChoice != 0)
    {
        cout<<"---------------------------------------------\n";

        cout<<"1: Push the element in the Stack\n";
        cout<<"2: Pop the element from the Stack\n";
        cout<<"3: Display the elements of the Stack\n";
        cout<<"4: Count the number of elements of the Stack\n";
        cout<<"5: Terminate the Application\n";

        cout<<"---------------------------------------------\n";

        cout<<"Enter the option:\n";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"enter the element that you want to Push in the Stack:\n";
                cin>>iValue;
                obj.Push(iValue);
                break;

            case 2: 
                iRet= obj.Pop();
                if(iRet == -1)
                {
                    cout<<"Poped element from the Stack is:"<<iRet<<"\n";
                }
                break;

            case 3:
                obj.Display();
                break;

            case 4:
                iRet= obj.Count();
                cout<<"Number of elements in the Stack are:"<<iRet<<"\n";
                break;

            case 5:
                cout<<"Thank you for using Application\n";
                break;

            default:
                cout<<"Enter valid Option\n";
                break;
        }
    }

    return 0;
}