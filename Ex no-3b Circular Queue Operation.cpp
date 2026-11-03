#include <iostream>
using namespace std;

class Queue
{
private:
    int QueueData[100], size, front, rear, count;

public:
    Queue()
    {
        size = 0;
        front = 0;
        rear = 0;
        count = 0;
    }

    void setsize(int n)
    {
        size = n;
    }

    void Enque(int);
    int Deque(void);
    void view(void);
};

void Queue::Enque(int x)
{
    if (count == size)
    {
        cout << "\n\t\tQueue is overflow...";
    }
    else
    {
        QueueData[rear] = x;
        cout << "\n\t\t" << x << " is added.\n";

        rear = (rear + 1) % size;
        count++;
    }
}

int Queue::Deque(void)
{
    int x;

    if (count == 0)
    {
        cout << "\n\t\tQueue is underflow...";
        return -9999;
    }
    else
    {
        x = QueueData[front];

        front = (front + 1) % size;
        count--;

        return x;
    }
}

void Queue::view()
{
    if (count == 0)
    {
        cout << "\n\t\tQueue is Empty...";
    }
    else
    {
        cout << "\n\t\tData in Queue : ";

        int i = front;

        for (int c = 0; c < count; c++)
        {
            cout << " " << QueueData[i];
            i = (i + 1) % size;
        }
    }
}

int main()
{
    int n;

    cout << "\nEnter the size of the Queue [Max=100] : ";
    cin >> n;

    if (n > 100)
        n = 100;

    if (n <= 0)
    {
        cout << "\nInvalid queue size.";
        return 0;
    }

    Queue Q;
    Q.setsize(n);

    int choice;

    do
    {
        cout << "\n\n\t\tCircular Queue Operation";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t1. Insert";
        cout << "\n\t\t2. Delete";
        cout << "\n\t\t3. View";
        cout << "\n\t\t4. Exit";

        cout << "\n\nEnter your choice : ";
        cin >> choice;

        int x;

        switch (choice)
        {
        case 1:
            cout << "\nEnter a value : ";
            cin >> x;

            Q.Enque(x);
            Q.view();
            break;

        case 2:
            x = Q.Deque();

            if (x != -9999)
                cout << "\n\n\t\t" << x << " is deleted\n";

            Q.view();
            break;

        case 3:
            Q.view();
            break;

        case 4:
            cout << "\n\n\t\tExit...";
            break;

        default:
            cout << "\n\n\t\tInvalid choice...";
        }

    } while (choice != 4);

    return 0;
}
