#include <iostream>
using namespace std;

class AdvancedSort
{
    int a[100], n;

public:

    void GetData()
    {
        cout << "Enter size of array: ";
        cin >> n;

        cout << "Enter Elements: ";
        for (int i = 0; i < n; i++)
            cin >> a[i];
    }

    void Display()
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << endl;
    }

    int Partition(int low, int high)
    {
        int pivot = a[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (a[j] < pivot)
            {
                i++;
                swap(a[i], a[j]);
            }
        }

        swap(a[i + 1], a[high]);

        return i + 1;
    }

    void QuickSort(int low, int high)
    {
        if (low < high)
        {
            int pi = Partition(low, high);

            QuickSort(low, pi - 1);
            QuickSort(pi + 1, high);
        }
    }

    void Sort()
    {
        QuickSort(0, n - 1);
    }
};

int main()
{
    AdvancedSort S;

    S.GetData();

    cout << "Before QuickSort: ";
    S.Display();

    cout << "Performing QuickSort..." << endl;
    S.Sort();

    cout << "After QuickSort: ";
    S.Display();

    return 0;
}