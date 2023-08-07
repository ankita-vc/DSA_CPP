#include<iostream>
using namespace std;

typedef class node
{
    public:
        int data;
        node *next;

        node(int iValue)
        {
            data=iValue;
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
{}

void Stack :: Push(int iNo)
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

int Stack :: Pop()
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
void Stack :: Display()
{
    if(First == NULL)
    {
        cout<<"nothing to display\n";
        return;
    }
    
    cout<<"Element of stak are:\n";

    PNODE temp= First;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        cout<<temp->data<<"\n";
        temp= temp->next;
    }
}
int Stack :: Count()
{
    return iCount;
}

int main()
{
    int iChoice = 1;
    int iValue= 0;
    int iRet= 0;

    Stack obj;
    cout<<"------------------------------------------\n";
    cout<<"Dynamic implementation  of stack\n";
    cout<<"------------------------------------------\n";

    while(iChoice != 0)
    {
        cout<<"------------------------------------------\n";
        cout<<"1: Push element into stack\n";


        cout<<"------------------------------------------\n";
        cout<<"Plese enter the option:\n";



        switch(iChoice)
        {
            case 1:
                cout<<"enetr element that you want to push\n";
                cin>>iValue;
                obj.Push(iValue);
                break;

            case 2:
                iRet= obj.Pop();
                if(iRet != -1)
                {
                    cout<<"poped element is:"<<iRet<<"\n";
                }
                break;

            case 3:
                obj.Display();
                break;

            case 4:
                iRet= obj.Count();
                cout<<"number f elements are:"<<iRet<<"\n";
                break;

            case 0:
                cout<<"thsnk you for using application\n";
                break;

            default:
                cout<<"enter valid option\n";
                break;
        } // end of switch
    } // end of while

    return 0;
} // end of main
