#include<iostream>
using namespace std;
class Sequential
{
	int a[100],n,key;
	public:
		void GetData(void);
		void SequentialSearch(void);
		
};
void Sequential::GetData(void)
{
	cout<<"Enter no of elements: ";
	cin>>n;
	cout<<"Enter elements: ";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	cout<<"Enter the key value to be searched in the above list: ";
	cin>>key;
};
void Sequential::SequentialSearch(void)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			cout<<"The key value "<<key<<" is present at location "<<i+1;
			return;
			
		}
	}
	cout<<"The key value"<<key<<"is not present in the above list";
	
}
int main()
{
	Sequential S;
	S.GetData();
	S.SequentialSearch();
	return 0;
	
}
