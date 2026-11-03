#include <iostream>
using namespace std;

class DataArray
{
protected:
    int a[100], n;

public:
    void GetData(void);
    void Display(void);
};

void DataArray::GetData(void)
{
    cout << "\nEnter the number of elements to be sorted: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element no. " << i + 1 << ": ";
        cin >> a[i];
    }
}

void DataArray::Display(void)
{
    for (int i = 0; i < n; i++)
        cout << " " << a[i];

    cout << endl;
}

class Insertion : public DataArray
{
public:
    void insertionsort(void);
};

void Insertion::insertionsort(void)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;

        cout << "\nArray After iteration " << i << ": ";
        Display();
    }
}

int main()
{
    Insertion B;

    B.GetData();
    B.insertionsort();

    cout << "\n\tThe Sorted Array";
    cout << "\n\t~~~~~~~~~~~~~~~~~\n";

    B.Display();

    return 0;
}