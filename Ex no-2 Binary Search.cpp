#include<iostream>
using namespace std;
class Binary
{
	int a[100],n,key;
	public:
		void GetData(void);
		void Sort(void);
		void Display(void);
		void BinarySearch();
		
};
void Binary::GetData()
{
	cout<<"Enter no of elements: ";
	cin>>n;
	cout<<"Enter the elements: ";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	cout<<"Enter the element to be searched: ";
	cin>>key;
}
void Binary::Sort(void)
{
	for(int i=0;i<n-1;i++)
	for(int j=i+1;j<n;j++)
	{
		if(a[i]>a[j])
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
}
void Binary::Display(void)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Element"<<i+1<<"is"<<a[i];
		
	}
}
void Binary::BinarySearch(void)
{
	int high,low,mid;
	high=n-1;low=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==key)
		{
			cout<<"\nThe key value"<<key<<"is present at location"<<mid+1;
			return;
		}
		else if(key<a[mid])
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		} 
		
		}
		cout<<"\n The key Value"<<key<<"is not present in the above list";
	}
	int main()
	
	{
	
	   Binary B;
	   B.GetData();
	   B.Sort();
	   cout<<"\n The Sorted List \n";
	   cout<<" ------------------\n";
	   B.Display();
	   B.BinarySearch();
	   return 0;
	}

