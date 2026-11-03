#include<iostream>
using namespace std;
class DataArray
{
	protected:
		int a[100],n;
	public:
		int Getn(void)
		{
			return n;
		}
		void GetData(void);
		void Display(void);
		
};
void DataArray::GetData(void)
{
	cout<<"\n Enter the no of elements to be sorted: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter element no."<<i+1<<":";
		cin>>a[i];
		
	}
}

void DataArray::Display(void)
{
	for(int i=0;i<n;i++)
	cout<<" "<<a[i];
	cout<<endl;
		
}
class Quick:public DataArray
{
	public:
		void QuickSort(int low,int high);
		void QuickDisplay(int l,int h);
		
};
void Quick::QuickSort(int low,int high)
{
	int left=low+1;
	int right=high;
	int temp=0;
	int pivot=a[low];
	if(low>=high)
	return;
	do
	{
		while(left<high && a[left]<pivot)left++;
		while(a[right]>pivot && right>low)right--;
		if(left<right)
		{
			temp=a[left];
			a[left]=a[right];
			a[right]=temp;
			
		}
		else break;
		
	}while(1);
	temp=a[low];
	a[low]=a[right];
	a[right]=temp;
	cout<<"Left: ";
	QuickDisplay(low,right-1);
	cout<<"Pivot: ["<<pivot<<"]";
	cout<<"Right :";
	QuickDisplay(right+1,high);
	cout<<endl;
	QuickSort(low,right-1);
	QuickSort(right+1,high);
	
}
void Quick::QuickDisplay(int l,int h)
{
	cout<<"{";
	for(int i=l;i<=h;i++)
	cout<<" "<<a[i];
	cout<<"}";
	
} 
int main()
{
	Quick Q;
	Q.GetData();
	cout<<"Orginial: ";
	Q.QuickDisplay(0,Q.Getn()-1);
	cout<<endl;
	Q.QuickSort(0,Q.Getn()-1);
	cout<<"\n\t The Sorted Array";
	cout<<"\n\t~~~~~~~~~~~~~~~~~~\n";
	Q.Display();
	return 0;
}