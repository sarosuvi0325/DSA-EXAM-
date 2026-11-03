#include <iostream>
using namespace std;

struct node
{
    int data;
    node* link;
};

class LinkedList
{
    node* Head;

public:
    LinkedList()
    {
        Head = NULL;
    }

    ~LinkedList()
    {
        node* temp;

        while (Head != NULL)
        {
            temp = Head;
            Head = Head->link;
            delete temp;
        }
    }

    void Append(int x);
    void AddAfter(int loc, int x);
    void AddAtBegin(int x);
    void AddAtLocation(int loc, int x);
    void Display();
    void Count();
    void Delete(int x);
};

// Add node at the end
void LinkedList::Append(int num)
{
    node* temp;
    node* r;

    r = new node;
    r->data = num;
    r->link = NULL;

    if (Head == NULL)
    {
        Head = r;
    }
    else
    {
        temp = Head;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = r;
    }
}

// Add node at beginning
void LinkedList::AddAtBegin(int num)
{
    node* r = new node;

    r->data = num;
    r->link = Head;
    Head = r;
}

// Add node after a specific location
void LinkedList::AddAfter(int loc, int num)
{
    node* temp;
    node* r;

    temp = Head;

    if (temp == NULL)
    {
        cout << "\nList is empty.";
        return;
    }

    // Move to the required location
    for (int i = 1; i < loc; i++)
    {
        if (temp == NULL)
        {
            cout << "\nThere are less than " << loc
                 << " elements in the list.";
            return;
        }

        temp = temp->link;
    }

    if (temp == NULL)
    {
        cout << "\nThere are less than " << loc
             << " elements in the list.";
        return;
    }

    r = new node;
    r->data = num;
    r->link = temp->link;

    temp->link = r;
}

// Add node at a specific location
void LinkedList::AddAtLocation(int loc, int num)
{
    if (loc <= 1)
    {
        AddAtBegin(num);
        return;
    }

    node* temp = Head;

    for (int i = 1; i < loc - 1; i++)
    {
        if (temp == NULL)
        {
            cout << "\nInvalid location.";
            return;
        }

        temp = temp->link;
    }

    if (temp == NULL)
    {
        cout << "\nInvalid location.";
        return;
    }

    node* r = new node;

    r->data = num;
    r->link = temp->link;
    temp->link = r;
}

// Display linked list
void LinkedList::Display()
{
    cout << "\n\n";

    node* temp = Head;

    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->link;
    }

    cout << "NULL\n";
}

// Count number of nodes
void LinkedList::Count()
{
    int c = 0;
    node* temp = Head;

    while (temp != NULL)
    {
        c++;
        temp = temp->link;
    }

    cout << "\nNumber of nodes = " << c << endl;
}

// Delete a specified node
void LinkedList::Delete(int num)
{
    node* temp = Head;
    node* old = NULL;

    while (temp != NULL)
    {
        if (temp->data == num)
        {
            // If deleting first node
            if (temp == Head)
            {
                Head = temp->link;
                delete temp;
                return;
            }

            // Delete node from middle/end
            old->link = temp->link;
            delete temp;
            return;
        }

        old = temp;
        temp = temp->link;
    }

    cout << "\nThe data was not found.";
}

// Main function
int main()
{
    LinkedList L;

    int choice, x, loc;

    do
    {
        cout << "\n\n\t\t\tSingle Linked List";
        cout << "\n\t\t\t~~~~~~~~~~~~~~~~~~";
        cout << "\n\t1. Create a Node";
        cout << "\n\t2. Add at beginning";
        cout << "\n\t3. Add at specific location";
        cout << "\n\t4. Add after a specific location";
        cout << "\n\t5. Display";
        cout << "\n\t6. Count number of nodes";
        cout << "\n\t7. Delete a specified node";
        cout << "\n\t8. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\nEnter a value: ";
                cin >> x;

                L.Append(x);
                L.Display();
                break;

            case 2:
                cout << "\nEnter a value: ";
                cin >> x;

                L.AddAtBegin(x);
                L.Display();
                break;

            case 3:
                cout << "\nEnter the location: ";
                cin >> loc;

                cout << "Enter a value: ";
                cin >> x;

                L.AddAtLocation(loc, x);
                L.Display();
                break;

            case 4:
                cout << "\nEnter the location: ";
                cin >> loc;

                cout << "Enter a value: ";
                cin >> x;

                L.AddAfter(loc, x);
                L.Display();
                break;

            case 5:
                L.Display();
                break;

            case 6:
                L.Count();
                break;

            case 7:
                cout << "\nEnter a value to delete: ";
                cin >> x;

                L.Delete(x);
                L.Display();
                break;

            case 8:
                cout << "\n\nYou are exiting...";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while (choice != 8);

    return 0;
}