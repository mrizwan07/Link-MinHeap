#include <iostream>
#include "Stack.h" 
using namespace std;

template <class T>
class LinkMinHeap;

template <class T>
class BTNode
{
	friend class LinkMinHeap<T>;
	T info;
	BTNode<T>* left;
	BTNode<T>* right;
public:
	BTNode(T val)
	{
		info = val;
		left = right = nullptr;
	}
};

template <class T>
class LinkMinHeap
{
	BTNode<T>* root;
	int count;
	void removeNode(BTNode<T>* p)
	{
		if (!p)
		{
			return;
		}
		if (p->left)
		{
			removeNode(p->left);
		}
		if (p->right)
		{
			removeNode(p->right);
		}
		delete p;
	}
	void lvr(BTNode<T>* p)
	{
		if (p->left)
		{
			lvr(p->left);
		}
		if (p)
		{
			cout << p->info << ',';
		}
		if (p->right)
		{
			lvr(p->right);
		}
	}
	void swap(BTNode<T>* t1, BTNode<T>* t2, Stack<T> a2)
	{
		if (!(a2.isEmpty()))
		{
			a2.topValue(); // This line doesn't seem to do anything, please revise
		}
	}
public:
	LinkMinHeap()
	{
		root = nullptr;
		count = 0;
	}
	~LinkMinHeap()
	{
		removeNode(root);
	}	void insert(T val)
	{
		if (root == nullptr)
		{
			root = new BTNode(val);
			return;
		}
		if (root->left == nullptr && val > root->info)
		{
			root->left= new BTNode(val);
			count++;
			return;
		}
		else if(root->left == nullptr && val <= root->info)
		{ 
			BTNode<T> * temp = new BTNode(val);
			temp->left = root;
			temp->right = root->right;
			root = temp;
			count++;
			return;
		}
		if (root->right == nullptr && val > root->info)
		{
			root->right = new BTNode(val);
			count++;
			return;
		}
		else if (root->left == nullptr&& val <= root->info)
		{

			BTNode<T>* temp = new BTNode(val);
			temp->right = root;
			temp->left = root->left;
			root = temp;
			count++;
			return;
		}
		BTNode<T>* t1=root;
		Stack< BTNode*> a1;
		Stack<int> s1;
		while (count != 1)
		{
			s1.push(count % 2);
			count = count / 2;
		}
		while (!(s1.isEmpty()))
		{
			if (s1.topValue() == 1)
			{
				t1 = t1->right;
				a1.push(t1);
				s1.pop();
			}
			if (s1.topValue() == 0)
			{
				t1 = t1->left;
				a1.push(t1);
				s1.pop();
			}
		}            
		if(t1->left==nullptr)
			t1->left= new BTNode(val);
		else if (t1->right == nullptr)
			t1->right = new BTNode(val);
		Stack< BTNode *> a2;
		while (!(a1.isEmpty()))
		{
			a2.push(a1.topValue());
			a1.pop();
		}
		while (a2.topValue()!=root)
		{
			if (t1->info < (a2.topValue()->info))
				swap(t1, a2.topValue(), a2);
			t1 = a2.topValue();
			a2.pop();

		}
		if (t1->info < root->info)
			swap(t1, a2.topValue(), a2);
		else return;
	}
	T removeMin()
	{

	}
	T getMin()
	{
		if (root != nullptr)
		{
			return root->info;
		}
		else
			return T();
	}
	bool isEmpty()
	{
		return root == nullptr;
	}
	void inOrder()
	{
		lvr(root);
	}
};

int main() {

	LinkMinHeap<int> obj;
	cout << "Min Heap Created" << endl;

	int option, val;

	do {
		cout << "What operation do you want to perform? " <<
			" Select Option number. Enter 0 to exit." << endl;
		cout << "1. Insert Key/Node" << endl;
		cout << "2. Delete Minimum Key/Node" << endl;
		cout << "3. Delete Key/Node" << endl;
		cout << "4. Get Min" << endl;
		cout << "5. To print InOrder" << endl;
		cout << "6. Bool is empty or not " << endl;
		cout << "0. Exit Program" << endl;

		cin >> option;

		switch (option) {
		case 0:
			break;
		case 1:
			cout << "INSERT Operation -" << endl;
			cout << "Enter VALUE to INSERT in HEAP: ";
			cin >> val;
			obj.insert(val);
			cout << endl;
			break;
		case 2:
			cout << "DELETE Operation -" << endl;
			// Your delete operation logic goes here
			break;
		case 3:
			cout << "DELETE Operation -" << endl;
			// Your delete operation logic goes here
			break;
		case 4:
			cout << "GET Min value : " << obj.getMin();
			cout << endl;
			break;
		case 5:
			cout << "InOrder Traversal: ";
			obj.inOrder();
			cout << endl;
			break;
		case 6:
			cout << "Heap " << (obj.isEmpty() ? "is empty" : "is not empty") << endl;
			break;
		default:
			cout << "Enter Proper Option number " << endl;
		}

	} while (option != 0);

	return 0;
}