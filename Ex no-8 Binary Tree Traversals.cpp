 #include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val) : data(val), left(nullptr), right(nullptr)
    {
    }
};

class BinaryTree
{
    Node *root;

public:

    BinaryTree()
    {
        root = nullptr;
    }

    Node* insert(Node *node, int val)
    {
        if (node == nullptr)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);

        return node;
    }

    void buildTree()
    {
        int n, val;

        cout << "Enter the number of nodes: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter value: ";
            cin >> val;

            root = insert(root, val);
        }
    }

    void preOrder(Node *node)
    {
        if (node == nullptr)
            return;

        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(Node *node)
    {
        if (node == nullptr)
            return;

        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void postOrder(Node *node)
    {
        if (node == nullptr)
            return;

        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

    void displayTraversals()
    {
        cout << "\nPre-order Traversal: ";
        preOrder(root);

        cout << "\nIn-order Traversal: ";
        inOrder(root);

        cout << "\nPost-order Traversal: ";
        postOrder(root);

        cout << endl;
    }
};

int main()
{
    BinaryTree T;

    T.buildTree();
    T.displayTraversals();

    return 0;
}
