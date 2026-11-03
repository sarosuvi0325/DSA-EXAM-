#include<iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node*link;
	
}node;
class LinkedList
{
	node * Head;
	
	public:
		LinkedList()
		{
			Head=NULL;
				
		}
		~LinkedList()
		{
			delete Head;
		}
		void Append(int x);
		void AddAfter(int loc,int x);
		void AddAtBegin(int x);
		void Display();
		void Count();
		void Delete(int x);
		
};
void LinkedList::Append(int num)
{
	node *temp, *r;
	temp=Head;
	if(Head==NULL)
	{
		temp=new node;
		temp->data=num;
		temp->link=NULL;
		Head=temp;
		
	}
	else
	{
		while(temp->link!=NULL)
		temp=temp->link;
		r=new node;
		r->data=num;
		r->link=NULL;
		temp->link=r;
	}
}
void LinkedList::AddAfter(int loc,int num)
{
	node *temp, *r;
	int i;
	temp=Head;
	if(temp==NULL)
	{
		cout<<"\n\n\t\t There are less than"<<loc<<"elementsin list.";
		return;
		
	}
	for(i=1;i<loc;i++)
	{
		if(temp==NULL)
		{
			cout<<"\n\n\t\t There are less than"<<loc<<"elements in list.";
			return;
		}
		temp=temp->link;
		
	}
	r=new node;
	r->data=num;
	r->link=temp->link;
	temp->link=r;
	
}
void LinkedList::AddAtBegin(int num)
{
	node *temp;
	temp=new node;
	temp->data=num;
	temp->link=Head;
	Head=temp;
}
void LinkedList::Display()
{
	cout<<"\n\n\n";
	node*temp=Head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"-->";
		temp=temp->link;
		
	}
	cout<<"NULL";
	
}
void LinkedList::Count()
{
	int c=0;
	node*temp=Head;
	while(temp!=NULL)
	{
		temp=temp->link;
		c++;
		
	}
	cout<<"\n\n\t\t count="<<c;
	
}
void LinkedList::Delete(int num)
{
	node *old ,*temp;
	temp=Head;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			if(temp==Head)
			{
				Head=temp->link;
				delete temp;
				return;
				
			}
			else
			{
				old->link=temp->link;
				delete temp;
				return;
				
			}
		}
		else
		{
			old=temp;
			temp=temp->link;
			
		}
	}
	cout<<"\n\n\n\t\t The data not found.";
	
}
int main()
{
	LinkedList L;
	int choice,x,loc;
	do
	{
		cout<<"\n\t\t\t Single Linked List";
		cout<<"\n\t\t\t ~~~~~~~~~~~~~~~~~~~~";
		cout<<"\n\t1.Create a Node";
		cout<<"\n\t2.Add at begining";
		cout<<"\n\t3.Add at end";
		cout<<"\n\t4.Add after a specific location";
		cout<<"\n\t5.Display";
		cout<<"\n\t6.Count no of nodes";
		cout<<"\n\t7.Delete  a specified node";
		cout<<"\n\t8.Exit";
		cout<<"\n\n\nEnter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\n Enter a value: ";
				cin>>x;
				L.Append(x);
				L.Display();
				break;
				
			case 2:
				cout<<"\nEnter a value: ";
				cin>>x;
				L.AddAtBegin(x);
				L.Display();
				break;
			case 3:
				cout<<"\nEnter a value: ";
				cin>>x;
				L.Append(x);
				L.Display();
				break;	
				
			case 4:
				cout<<"\n Enter the location:";
				cin>>loc;
				
				cout<<"\nEnter a value: ";
				cin>>x;
				L.AddAfter(loc,x);
				L.Display();
				break;
			case 5:
				L.Display();
				break;
			case 6:
				L.Count();
				L.Display();
				break;
			case 7:
				cout<<"\n Enter a value to delete: ";
				cin>>x;
				L.Delete(x);
				L.Display();
				break;
			case 8:
				cout<<"\n\n\n\t\t You have exited.........";
				break;
				
		}
	}while(choice!=8);
	return(0);
}