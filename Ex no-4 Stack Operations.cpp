//Stack Operations
#include<iostream>
using namespace std;
class Stack
{
	private:
		int StackData[100],size,top;
	public:
		stack(){top=-1;}
		void SetSize(int n){size=n;}
		void Push(int x);
		int Pop(void);
		void Display(void);
};
void Stack::Push(int x)
{
	if(top>=size-1)
	{
		cout<<"\n\t\t Stack is over flow..";
	}
		
		else
			{
				top++;
				StackData[top]=x;
				cout<<"\n\t\t"<<x<<"is pushed\n\n\n";
			}
		}
		int Stack::Pop()
		{
			int x;
			if(top<=-1)
			{
				cout<<"\n\t\tStack is under flow";
				return-9999;
			}
			else
			{
				x=StackData[top];
				top--;
				return x;
			}
		}
		void Stack::Display(void)
		{
			if(top>=0)
			{
				cout<<"\n The elements in Stack";
				cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~";
				for(int i=top;i>=0;i--)
				cout<<"\n\nData"<<i+1<<"="<<StackData[i];
				cout<<"\n\n\n\n Press any key to continue...";
			}
			else {
				cout<<"\n The Stack is Empty";
			}
		};
		int main()
		{
			Stack S;
			int option,n;
			cout<<"\nEnter the size of stack[Max=100]:";
			cin>>n;
			S.SetSize(n);
			do {
				cout<<"\nEnter the Size of stack[Max=100]:";
				cout<<"\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~";
				cout<<"\n\t1.Push\n\t2.pop\n\t3.Display\n\t4.Exit";
				cout<<"\n\nEnter your option:";
				cin>>option;
				int x,topvalue;
				switch(option)
				{
					case 1:
						cout<<"\nEnter a value to be pushed:";
						cin>>x;
						S.Push(x);
						S.Display();
						break;
					case 2:
						topvalue=S.Pop();
						if(topvalue!=-9999)
						cout<<"\n\t\tThe Popped element is"<<topvalue<<endl;
						S.Display();
						break;
					case 3:
						S.Display();
						break;
					case 4:
						cout<<"\n\n\t\t You are on EXIT...";
						break;
					default :
						cout<<"\n\n\t\t Enter only 1,2,3,4.";
					}
				}while (option!=4);
				return 0;
			}
			
		
	