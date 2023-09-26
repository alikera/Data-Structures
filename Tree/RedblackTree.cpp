#include <iostream>
using namespace std;

class Node
{
public:
	Node(int _value)
	{
		value = _value;
		parent = NULL;
		right = NULL;
		left = NULL;
		color = 'r';
	}
	int value;
	char color;
	Node *parent;
	Node *right;
	Node *left;
};

class RedBlackTree
{
public:
	RedBlackTree(Node* _root) { root = _root; }
	void insert(int value);
	void find(int key);

private:
	Node* regular_insert(Node *root, Node *node);
	void fix_insertion(Node *&root, Node *&node);
	void rotate_left(Node *&root, Node *&node);
	void rotate_right(Node *&root, Node *&node);
	Node* search(Node* root, int key);

	Node *root;

};

void RedBlackTree::insert(int value)
{
	Node *node = new Node(value);
	root = regular_insert(root, node);
	root->color = 'b';
	fix_insertion(root, node);
}

Node* RedBlackTree::regular_insert(Node* root, Node *node)
{
	if (root == NULL)
		return node;

	if (node->value < root->value)
	{
		root->left = regular_insert(root->left, node);
		root->left->parent = root;
	}
	else if (node->value > root->value)
	{
		root->right = regular_insert(root->right, node);
		root->right->parent = root;
	}
	return root;
}

void RedBlackTree::fix_insertion(Node *&root, Node *&node)
{
	Node *parent = node->parent;
	Node *grand_parent, *uncle;
	while (node != root && node->color != 'b' && parent->color != 'b')
	{
		grand_parent = parent->parent;
		if (parent == grand_parent->right)
		{
			uncle = grand_parent->left;
			if (uncle != NULL && uncle->color == 'r')
			{
				parent->color = 'b';
				uncle->color = 'b';
				grand_parent->color = 'r';
				node = grand_parent;
			}
			else
			{
				if (node == parent->left)
				{
					rotate_right(root, parent);
					node = parent;
					parent = node->parent;
				}
				rotate_left(root, grand_parent);
				char temp = grand_parent->color;
				grand_parent->color = parent->color;
				parent->color = temp;
				node = parent;
			}
		}
		else
		{
			uncle = grand_parent->right;
			if (uncle != NULL && uncle->color == 'r')
			{
				parent->color = 'b';
				uncle->color = 'b';
				grand_parent->color = 'r';
				node = grand_parent;
			}
			else
			{
				if (node == parent->right)
				{
					rotate_left(root, parent);
					node = parent;
					parent = node->parent;
				}
				rotate_right(root, grand_parent);
				char temp = grand_parent->color;
				grand_parent->color = parent->color;
				parent->color = temp;
				node = parent;
			}
		}
	}
	root->color = 'b';
}

void RedBlackTree::rotate_right(Node *&root, Node *&node)
{

	Node *node_L = node->left;
	node->left = node_L->right;

	if (node->left != NULL)
		node->left->parent = node;

	node_L->parent = node->parent;

	if (node->parent == NULL)
		root = node_L;
	else if (node == node->parent->left)
		node->parent->left = node_L;
	else
		node->parent->right = node_L;

	node_L->right = node;
	node->parent = node_L;
}

void RedBlackTree::rotate_left(Node *&root, Node *&node)
{

	Node *node_R = node->right;
	node->right = node_R->left;

	if (node->right != NULL)
		node->right->parent = node;

	node_R->parent = node->parent;

	if (node->parent == NULL)
		root = node_R;
	else if (node == node->parent->left)
		node->parent->left = node_R;
	else
		node->parent->right = node_R;

	node_R->left = node;
	node->parent = node_R;
}

void RedBlackTree::find(int key)
{
	if (search(root, key) != NULL)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

Node* RedBlackTree::search(Node* root, int key)
{
	if (root == NULL || root->value == key)
		return root;

	if (root->value > key)
		return search(root->left, key);
	return search(root->right, key);

}

int main()
{
	Node* root = new Node(NULL);
	root = NULL;
	RedBlackTree tree = RedBlackTree(root);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int t, n;
		cin >> t >> n;
		if (t == 1)
			tree.insert(n);
		else
			tree.find(n);
	}
}