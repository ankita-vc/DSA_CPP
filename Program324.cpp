#include<iostream>
using namespace std;

typedef class node
{
    public:
        int data;
        node *next;

        node(int value)
        {
            data= value;
            next= NULL;
        }
}NODE, *PNODE;

class Queue
{
    private:
        PNODE First;
        int iCount;

    public:
        Queue();
        void Enqueue(int iNo);
        int Dequeue();
        void Display();
        int Count();
};

Queue::Queue()
{
    First= NULL;
    iCount= 0;
}

void Queue::Enqueue(int iNo)
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

int Queue::Dequeue()
{
    int Value= 0;

    if(First == NULL)
    {
        cout<<"Queue is Empty\n";
        return -1;
    }
    else if(First->next == NULL)
    {
        delete First;
        First= NULL;
    }
    else
    {
        PNODE temp= First;

        Value= First->next->data; 
        First= First->next;
        delete temp;
    }
    iCount--;
    return Value;
}

void Queue::Display()
{
    if(First == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }

    cout<<"elements in Queue are:\n";
    PNODE temp= First; 

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        cout<<temp->data<<"\n";
        temp= temp->next;
    }
    cout<<"\n";
}

int Queue::Count()
{
    return iCount;
}

int main()
{
    int iValue= 0;
    int iChoice= 1;
    int iRet= 0;

    Queue obj;

    cout<<"---------------------------\n";
    cout<<"Dynamic Implementation of Queue\n";
    cout<<"---------------------------\n";

    while(iChoice != 0)
    {
        cout<<"---------------------------\n";

        cout<<"1: Enqueue the element in the Queue\n";
        cout<<"2: Dequeue the element from the Queue\n";
        cout<<"3: Display the elements of Queue\n";
        cout<<"4: Count the number of elements in Queue\n";
        cout<<"5: Terminate the Application\n";

        cout<<"---------------------------\n";

        cout<<"Enter the Option:\n";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter the element that you want to add in Queue:\n";
                cin>>iValue;
                obj.Enqueue(iValue);
                break;

            case 2:
                iRet= obj.Dequeue();
                if(iRet == -1)
                {
                    cout<<"Dequeued element from the Queue is:"<<iRet<<"\n";
                }
                break;

            case 3: 
                obj.Display();
                break;

            case 4:
                iRet= obj.Count();
                cout<<"The number of elements in the Queue are:"<<iRet<<"\n";
                break;
    
            case 5:
                cout<<"Thank you for using the Application\n";
                break;

            default:
                cout<<"Enter valid option\n";
                break;
        }
    }

    return 0;
}