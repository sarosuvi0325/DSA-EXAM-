#include<iostream>
using namespace std;
class Queue
{
	int QueueData[100],size,front,rear;
	public:
		Queue()
		{
			front=0;
			rear=0;
		}
		void Setsize(int n)
		{
			size=n;
		}
		void Enqueue(int x);
		int Dequeue(void);
		void View(void);
		
};
void Queue::Enqueue(int x)
{
	if((rear-front+1)>size)
	{
		cout<<"Overflow.........";	
	}
	else
	{
		QueueData[rear]=x;
		cout<<x<<" is inserted..\n ";
		rear++;
	}
}
int Queue::Dequeue(void)
{
	int x;
	if(front>=rear)
	{
		cout<<"Underflowwwww....\n";
		return -9999;
	}
	else
	{
		x=QueueData[front];
		front++;
		cout<<x<<"is deleted..\n";
		return x;
		
	}
}

void Queue::View(void)
{
	int i=front;
	{
		if(i==rear)
		{
			cout<<"\n Queue is empty....";
			
		}
		else
		{
		
			{
				cout<<"\n Queue Elements: ";
				
				for(int i=front;i<rear;i++)
				{
				
				cout<<" "<<QueueData[i];
			    }
			}
		}
	}
}
int main()
{
	int n,choice,x;
	cout<<"Enter the size of the queue[MAX=100]: ";
	cin>>n;
	Queue Q;
	Q.Setsize(n);
	do
	{
		cout<<"\n Queue Operation Menu...";
		cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<"\n\n\t1.Insert\n\t2.Delete\n\t3.View\n\t4.Exit";
		cout<<"\n Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter a element to insert: ";
				cin>>x;
				Q.Enqueue(x);
				Q.View();
				break;
			case 2:
				Q.Dequeue();
				Q.View();
				break;
			case 3:
				Q.View();
				break;
			case 4:
				cout<<"Exiting........";
			default:
			cout<<"INVALID CHOICE ";
			
		}
	}while(choice!=4);
	
}