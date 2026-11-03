#include<iostream>
#include<iomanip>
#include<cmath>
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
	cout<<"\n Enter the numbers of elements to be stored: ";
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
class Heap:public DataArray
{
	public:
		void HeapSort();
		void Heapify(int size,int root);
		void DisplayTree(int size);
		
};
void Heap::Heapify(int size,int root) 
{
	int largest=root;
	int left=2*root+1;
	int right=2*root+2;
	
	if(left<size && a[left]>a[largest])
	largest=left;
	
	if(right<size && a[right]>a[largest])
	largest=right;
	
	if(largest!=root)
	{
		int temp=a[root];
		a[root]=a[largest];
		a[largest]=temp;
		
		Heapify(size,largest);
		
	}
}
void Heap::HeapSort() 
{
	for(int i=n/2-1;i>=0;i--)
	{
		Heapify(n,i);
		
	}
	cout<<"\n ---Initial Max-Heap Tree Structure---";
	DisplayTree(n);
	for(int i=n-1;i>0;i--)
	{
		int temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		
		cout<<"\n [Extracted "<<a[i]<<"to the sorted section]";
		
		Heapify(i,0);
		cout<<"\n Current Structure of the tree";
		DisplayTree(n);
			
	}
}
void Heap::DisplayTree(int size)
{
	if(size<=0)
	{
		cout<<"\n (Heap is empty )\n";
		return;
		
	}
	cout<<"\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	int levels=log2(size)+1;
	int index=0;
	
	for(int l=0;l<levels;l++)
	{
		int elementsInLevel=pow(2,l);
		int spacesBetween=pow(2,levels-l+1)-1;
		int leadingSpaces=spacesBetween/2;
		cout<<string(leadingSpaces *2,' ');
		for(int e=0;e<elementsInLevel && index< size;e++)
		{
			cout<<setw(2)<<a[index++];
			cout<<string(spacesBetween *2,' ');
			
		}
		cout<<"\n\n";
		
	}
	cout<<"------------------------------------------\n";
	
}
int main()
{
	Heap H;
	H.GetData();
	cout<<"\n Original Array: ";
	H.Display();
	H.HeapSort();
	cout<<"\n\t The Sorted Array";
	cout<<"\n\t ~~~~~~~~~~~~~~~~~~~~~~~~~\n\t";
	H.Display();
	//H.DisplayTree(10);
	return 0;
	
}
