//Binary tree traversals
#include<iostream>
using namespace std;
struct BTnode
{
	int data;
	BTnode*left,*right;
};
class BinaryTree
{
	BTnode*Root;
	void ClearTree(BTnode*node)
	{
		if(node!=NULL)
		{
			ClearTree(node->left);
			ClearTree(node->right);
			delete node;
		}
	}
	BTnode*Insert(BTnode*node,int value)
	{
		if(node==NULL)
		{
			BTnode*newNode=new BTnode();
			newNode->data=value;
			newNode->left=NULL;
			newNode->right=NULL;
			return newNode;
		}
		if(value<node->data)
		{
			node->left=Insert(node->left,value);
		} else if(value>node->data)
		{
			node->right=Insert(node->right,value);
		}
		return node;
	}
	void Inorder(BTnode*node){
	if(node!=NULL){
	Inorder(node->left);
	cout<<node->data<<" ";
	Inorder(node->right);
	}
	}
	
	void Preorder(BTnode*node){
		if(node!=NULL){
			cout<<node->data<<" ";
			Preorder(node->left);
			Preorder(node->right);
	}
	}
	void Postorder(BTnode*node){
	if(node!=NULL){
	Postorder(node->left);
	Postorder(node->right);
	cout<<node->data<<" ";
    }
	}
	
	void DisplayTree(BTnode*node,int space){
	const int COUNT=5;
	if(node==NULL)return;
	space+=COUNT;
	DisplayTree(node->right,space);
	cout<<endl;
	for(int i=COUNT;i<space;i++) cout<<" ";
	cout<<node->data<<"\n";
	
	DisplayTree(node->left,space);
	}
	public:
		BinaryTree(){
			Root=NULL;
		}
		~BinaryTree(){
			ClearTree(Root);
		}
		BTnode*GetRoot(void){
			return Root;
		}
		void SetRoot(BTnode*root){
			Root=root;
		}
		void InsertValue(int value){
			Root=Insert(Root,value);
		}
		void DisplayInorder(){
			Inorder(Root);
			cout<<endl;
		}
		void DisplayPreorder(){
			Preorder(Root);
			cout<<endl;
		}
		void DisplayPostorder(){
			Postorder(Root);
			cout<<endl;
		}
		void ShowTree(){
			DisplayTree(Root,0);
		}
	};
	
	int main()
	{
		BinaryTree bst;
		int choice,val;
		do{
			cout<<"\n---Binary Search Tree Menu---\n";
			cout<<"1.Insert Node\n";
			cout<<"2.Inorder Traversal\n";
			cout<<"3.Preorder Traversal\n";
			cout<<"4.Postorder Traversal\n";
			cout<<"5.Display Tree Structure\n";
			cout<<"6.Exit\n";
			cout<<"Enter your choice:";
			cin>>choice;
			
			switch(choice){
				case 1:
					cout<<"Enter value to insert:";
					cin>>val;
					bst.InsertValue(val);
					break;
				case 2:
					cout<<"Inorder Traversal:";
					bst.DisplayInorder();
					break;
				case 3:
					cout<<"Preorder Traversal:";
					bst.DisplayPreorder();
					break;
				case 4:
					cout<<"Postorder Traversal:";
					bst.DisplayPostorder();
					break;
				case 5:
					cout<<"Tree Structure(Sideways view):";
					bst.ShowTree();
					cout<<endl;
					break;
				case 6:
					cout<<"Exiting...\n";
					break;
					default:
						cout<<"INvalid choice!Try again.\n";
			}
		}while(choice!=6);
		return 0;
	}
		
	