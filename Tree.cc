#include<iostream>
#include<stack>
#include<queue>

using namespace std; 

struct TreeNode {
	char val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class BinTree
{
public:
	int index; 
	BinTree() { index = 0; };  // num of nodes 
	void setRoot(TreeNode *r) { root = r; };
	TreeNode *getRoot() { return root; };

	void BuildTree(TreeNode* &r, char data[]); 
	void preOrder(TreeNode *node); 
	void inOrder(TreeNode *node); 
	void postOrder(TreeNode *node); 
	void preOrder_nr(TreeNode *node); 
	void inOrder_nr(TreeNode *node); 
	void postOrder_nr(TreeNode *node);

	// DFS, BFS 
	void dfs_nr(TreeNode *node); 
	void bfs_nr(TreeNode *node); 

	// max depth, min depth
	// max width
	int maxDepth(TreeNode *node); 
	int minDepth(TreeNode *node); 
	int maxWidth(TreeNode *node); 

	// search, insert, delete; 
private:	
	TreeNode* root; 
};


void BinTree::BuildTree(TreeNode* &r, char data[])
{
	char value = data[index++];
	if (value == '#')
		r = NULL;
	else
	{
		r = (TreeNode*)malloc(sizeof(TreeNode));
		r->val = value;
		BuildTree(r->left, data);
		BuildTree(r->right, data);
	}
	root = r;   // keep the root 
}

// pre order with recursion 
void BinTree::preOrder(TreeNode *node)
{
	if (!node)
		return;
	cout << node->val << " ";
	preOrder(node->left);
	preOrder(node->right);

};
void BinTree::inOrder(TreeNode *node)
{
	if (!node)
		return;
	inOrder(node->left);
	cout << node->val << " ";
	inOrder(node->right);
}; 
void BinTree::postOrder(TreeNode *node)
{
	if (!node)
		return;
	postOrder(node->left);
	postOrder(node->right);
	cout << node->val << " ";  // do work 
}

void BinTree::preOrder_nr(TreeNode *node)
{
	if (!node)
		return;
	stack<TreeNode*> st;
	st.push(node);
	while (!st.empty())
	{
		TreeNode *tmp = st.top();
		// do work
		cout << tmp->val << " ";
		st.pop();
		if (tmp->right)
			st.push(tmp->right);
		if (tmp->left)
			st.push(tmp->left);
	}

}
void BinTree::inOrder_nr(TreeNode *node)
{
	if (!node)
		return;
	stack<TreeNode *> st;
	TreeNode *tmp = node->left;
	st.push(node);
	while (tmp || !st.empty())
	{
		while (tmp)
		{
			st.push(tmp);
			tmp = tmp->left;
		}
		tmp = st.top();
		st.pop();
		cout << tmp->val << " ";
		tmp = tmp->right;
	}
} 
void BinTree::postOrder_nr(TreeNode *node)
{
	stack<TreeNode*> st;
	TreeNode *tmp = node;
	TreeNode *previsited = NULL;
	while (tmp || !st.empty())
	{
		while (tmp)
		{
			st.push(tmp);
			tmp = tmp->left;
		}
		tmp = st.top();
		if (tmp->left == NULL || tmp->right == previsited)
		{
			cout << tmp->val << " ";
			previsited = tmp;
			st.pop();
			tmp = NULL;
		}
		else
			tmp = tmp->right;
	}
}; 

void BinTree::dfs_nr(TreeNode *node)
{
	stack<TreeNode *> node_stack;
	node_stack.push(node);
	TreeNode *tmp;
	while (!node_stack.empty())
	{
		tmp = node_stack.top();
		cout << tmp->val << " ";   // do work 
		node_stack.pop();
		if (tmp->left)
			node_stack.push(tmp->right); // !!! push right child First
		if (tmp->right)
			node_stack.push(tmp->left);	//  push left child in stack later 
	}
}
void BinTree::bfs_nr(TreeNode *node)
{
	queue<TreeNode *> node_queue;
	node_queue.push(node);
	TreeNode *tmp;
	while (!node_queue.empty())
	{
		tmp = node_queue.front();
		node_queue.pop();
		cout << tmp->val << " ";    // do work 
		if (tmp->left)
			node_queue.push(tmp->left);		// push left child in queue first 
		if (tmp->right)
			node_queue.push(tmp->right);	// push right child  in queue later 
	}
}

int BinTree::maxDepth(TreeNode *node)
{
	if (!node)
		return 0; 
	int left = maxDepth(node->left); 
	int right = maxDepth(node->right); 
	if (left > right)
		return left + 1;
	else
		return right + 1; 
}
int BinTree::minDepth(TreeNode *node)
{
	if (!node)
		return 0; 
	int left = minDepth(node->left); 
	int right = minDepth(node->right); 
	if (left < right)
		return left + 1;
	else
		return right + 1; 
}; 
int BinTree::maxWidth(TreeNode *node)
{
	if (!node)
		return 0;

	int width_pre = 0;//记录上一层的宽度  
	int width_tmp = 0;
	int width_now = 0;//记录当前层的宽度  
	int width = 1;//二叉树的宽度  

	queue<TreeNode *> myQueue;
	myQueue.push(node);//将根节点入队列 

	width_pre = 1;
	TreeNode *pCur = NULL;

	while (!myQueue.empty()) 
	{
		width_tmp = width_pre;
		while (width_tmp != 0)
		{
			pCur = myQueue.front();//取出队列头元素  
			myQueue.pop();//将队列头元素出队  
			if (pCur->left != NULL)
				myQueue.push(pCur->left);
			if (pCur->right != NULL)
				myQueue.push(pCur->right);
			width_tmp--;
		}
		width_now = myQueue.size();
		width = width_now > width ? width_now : width;
		width_pre = width_now;
	}
	return width;
}; 

int main()
{
	char a[] = { 'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F','#', '#', 'G', '#', '#' };
	TreeNode *root;
	BinTree *bintree = new BinTree();
	bintree->BuildTree(root, a);

	// traverse 
	cout << "Pre Order Traverse: " << endl;
	bintree->preOrder(root);
	cout << endl;
	cout << "In Order Traverse: " << endl;
	bintree->inOrder(root);
	cout << endl;
	cout << "Post Order Traverse: " << endl;
	bintree->postOrder(root);
	cout << endl;

	// dfs, bfs 
	cout << endl;
	cout << "DFS traverse: " << endl;
	bintree->dfs_nr(root);
	cout << endl;
	cout << "BFS traverse: " << endl;
	bintree->bfs_nr(root);
	cout << endl;

	// max depth 
	int max_depth = bintree->maxDepth(root->left); 
	cout << "Max Depth: " << max_depth << endl; 
	int max_width = bintree->maxWidth(root->left); 
	cout << "Max Width: " << max_width << endl; 

	// insert 

	system("pause"); 
}