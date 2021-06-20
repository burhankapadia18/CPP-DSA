#include<bits/stdc++.h>
using namespace std;
void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/output.txt","w",stdout);
    #endif
}

class node 
{
	public:
	int data;
	int hd;
	node *left;
	node *right;
	node(int info)
	{
		data = info;
		left = right = NULL;
	}
};

class bin_tree 
{	
	public:
	node *root;
	bin_tree()
	{
		root = NULL;
	}	
	void insert(int data)
	{
		node *newNode = new node(data), *temp;
		if(!root)
		{
			root = newNode;
			return;
		}
		queue<node*> q;
		q.push(root);
		while(!q.empty())
		{
			temp = q.front();
			q.pop();
			if(temp->left)
				q.push(temp->left);
			else {
				temp->left = newNode;
				return;
			}
			if(temp->right)
				q.push(temp->right);
			else {
				temp->right = newNode;
				return;
			}
		}
	}
	void preorder_traversal(node *p)
	{
		//recursive
		if(!p)
			return;
		cout<<p->data<<" ";
		preorder_traversal(p->left);
		preorder_traversal(p->right);

	}
	void preorder_traversal()
	{
		//iterative
		stack<node*> S;
		node *ptr = root;
		while(1)
		{
			while(ptr)
			{
				// process current node
				cout<<ptr->data<<" ";
				S.push(ptr);
				// if left subtree exists, add to stack
				ptr = ptr->left;
			}
			if(S.empty())
				break;
			ptr = S.top(); S.pop();
			// indicates completion of left subtree and current node, now go
			// to right subtree
			ptr = ptr->right;
		}
	}
	void inorder_traversal(node *p)
	{
		//recursive
		if(!p)
			return;
		inorder_traversal(p->left);
		cout<<p->data<<" ";
		inorder_traversal(p->right);
	}
	void inorder_traversal()
	{
		//iterative
		stack<node*> S;
		node *ptr = root;
		while(1)
		{
			while(ptr)
			{
				S.push(ptr);
				// goto left subtree and keep adding on stack
				ptr = ptr->left;
			}
			if(S.empty())
				break;
			ptr = S.top(); S.pop();
			// after popping, process the current node
			cout<<ptr->data<<" ";
			// indicates completion of left subtree and current node, now go
			// to right subtree
			ptr = ptr->right;
		}
	}
	void postorder_traversal(node *p)
	{
		//recursive
		if(!p)
			return;
		postorder_traversal(p->left);
		postorder_traversal(p->right);
		cout<<p->data<<" ";
	}
	void postorder_traversal()
	{
		//iterative
	}
	void levelorder_traversal()
	{
		if(root == NULL)
		{
			cout<<"empty";
			return;
		}
		node *temp;
		queue<node*> Q;
		Q.push(root);
		while(!Q.empty())
		{
			temp = Q.front();
			Q.pop();
			cout<<temp->data<<" ";
			if(temp->left)
				Q.push(temp->left);
			if(temp->right)
				Q.push(temp->right);
		}
	}
	void reverse_levelorder()
	{
		node *temp;
		queue<node*> Q;
		stack<node*> S;
		if(root == NULL)
			return;
		Q.push(root);
		while(!Q.empty())
		{
			temp = Q.front();
			Q.pop();
			if(temp->right)
				Q.push(temp->right);
			if(temp->left)
				Q.push(temp->left);
			S.push(temp);
		}
		while(!S.empty())
		{
			temp = S.top();
			cout<<temp->data<<" ";
			S.pop();
		}
	}
	void verticalorder_util(node *root, int hd, map<int, vector<int> > &m)
	{
		if(root == NULL)
			return;
		m[hd].push_back(root->data);
		verticalorder_util(root->left,hd-1,m);
		verticalorder_util(root->right,hd+1,m);
	}
	void verticalorder_traversal()
	{

		int hd = 0;
		map<int, vector<int> > m;
		verticalorder_util(root,hd,m);
		for(auto i:m)
		{
			for(auto j:i.second)
				cout<<j<<" ";
			cout<<'\n';
		}
	}
	int size(node *root)
	{
		// can be solved without recursion using levelorder
		if(root == NULL)
			return 0;
		return (size(root->left) + 1 + size(root->right));
	}
	int findMax(node *root)
	{
		int root_val, left, right, maxval = INT_MIN;
		if(root)
		{
			root_val = root->data;
			left = findMax(root->left);
			right = findMax(root->right);
			maxval = max(max(root_val,maxval), max(left,right));
		}
		return maxval;
	}
	int height(node *root)
	{
		// recursive
		if(root == NULL)
			return -1;
		
		int left_height = height(root->left);
		int right_height = height(root->right);

		return max(left_height,right_height)+1;
	}
	int height()
	{
		// using levelorder traversal
		if(root == NULL)
			return -1;
		
		int height = -1;
		node *temp;
		queue<node*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty())
		{
			temp = q.front(); q.pop();
			if(temp == NULL) 
			{
				if(!q.empty())
					q.push(NULL);
				height++;
			}
			else {
				if(temp->left)
					q.push(temp->left);
				if(temp->right)
					q.push(temp->right);
			}
		}
		return height;
	}
	node *deepestNode()
	{
		if(root == NULL)
			return NULL;
		
		node *temp;
		queue<node*> q;
		q.push(root);
		while(!q.empty())
		{
			temp = q.front();
			q.pop();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
		return temp;
	}
	void deleteElement(int data)
	{
		/*
		The deletion of a node in binary tree can be implemented as
		• Starting at root, find the node which we want to delete.
		• Find the deepest node in the tree.
		• Replace the deepest node’s data with node to be deleted.
		• Then delete the deepest node.
		*/
	}
	int leavesNum()
	{
		if(root == NULL)
			return 0;
		node *temp;
		int count = 0;
		queue<node*> q;
		q.push(root);
		while(!q.empty())
		{
			temp = q.front();
			q.pop();
			if(temp->left == NULL && temp->right == NULL)
				count++;
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
		return count;
	}
	int diameter(node *root)
	{
		if(root == NULL)
			return 0;

		int left_height = height(root->left) + 1;
		int right_height = height(root->right) + 1;
		int main_diameter = left_height + right_height + 1;

		int left_diameter = diameter(root->left);
		int right_diameter = diameter(root->right);

		return max(main_diameter, max(left_diameter,right_diameter));
	}
	void levelWithMaxSum()
	{
		if(root == NULL)
			return;
		
		queue<node*> Q;
		int maxsum=INT_MIN, currsum=0;
		int maxlev, currlev=0;
		Q.push(root);
		Q.push(NULL);
		while(!Q.empty())
		{
			node *temp = Q.front();
			Q.pop();
			if(temp == NULL)
			{
				if(currsum > maxsum){
					maxsum = currsum;
					maxlev = currlev;
				}
				currsum = 0;
				if(!Q.empty())
					Q.push(NULL);
				currlev++;
			}
			else {
				currsum += temp->data;
				if(temp->left)
					Q.push(temp->left);
				if(temp->right)
					Q.push(temp->right);
			}
		}
		cout<<maxsum<<" at "<<maxlev;
	}
	void printPathsUtil(node *root, int path[], int pathlen)
	{
		if(root == NULL)
			return;
		path[pathlen] = root->data;
		pathlen++;
		if(root->left == NULL && root->right == NULL)
		{
			for(int i=0; i<pathlen; i++)
				cout<<path[i]<<" ";
			cout<<endl;
		}
		else {
			printPathsUtil(root->left,path,pathlen);
			printPathsUtil(root->right,path,pathlen);
		}
	}
	void printPaths()
	{
		/*
		print out all its root-to-leaf paths
		*/
		int n = height();
		int a[n+1];
		printPathsUtil(root,a,0);
	}
	void mirror(node *root)
	{
		// algorithm for converting a tree to its mirror
		if(root == NULL)
			return;
		
		node *temp;
		mirror(root->left);
		mirror(root->right);

		temp = root->right;
		root->right = root->left;
		root->left = temp;
	}
	node *returnNode(int element)
	{
		if(root == NULL)
			return NULL;

		node *temp;
		queue<node*> Q;
		Q.push(root);
		while(!Q.empty())
		{
			temp = Q.front();
			Q.pop();
			if(temp->data == element)
				return temp;
			if(temp->left)
				Q.push(temp->left);
			if(temp->right)
				Q.push(temp->right);
		}
		return NULL;
	}
	node *LCA(node *root, node *a, node *b)
	{	/*
		algorithm for finding LCA (Least Common Ancestor) of two nodes 
		in a Binary Tree
		*/
		if(root == NULL)
			return NULL;

		if(root == a || root == b)
			return root;
		
		node *left = LCA(root->left,a,b);
		node *right = LCA(root->right,a,b);
		if(left != NULL && right != NULL)
			return root;
		if(left == NULL && right == NULL)
			return NULL;
		return left!=NULL?left:right;
	}
	bool printAllAncestors(node *root,node *p)
	{
		if(root == NULL)
			return 0;
		if(root->left == p || root->right == p || printAllAncestors(root->left,p) || printAllAncestors(root->right,p))
		{
			cout<<root->data<<" ";
			return 1;
		}
		return 0;
	}
	void zigzagTraversal()
	{
		if(root == NULL)
			return;
		
		node *temp;
		stack<node*> S1, S2;
		S1.push(root);
		while(!S1.empty() || !S2.empty()) 
		{
			while(!S1.empty())
			{
				temp = S1.top();
				S1.pop();
				cout<<temp->data<<" ";
				if(temp->left) S2.push(temp->left);
				if(temp->right) S2.push(temp->right);
			}
			while(!S2.empty())
			{
				temp = S2.top();
				S2.pop();
				cout<<temp->data<<" ";
				if(temp->right) S1.push(temp->right);
				if(temp->left) S1.push(temp->left);
			}
		}
	}
	void leftView()
	{	
		if(root == NULL)
			return;

		node *temp = root;
		queue<node*> Q;
		cout<<temp->data<<" ";
		Q.push(temp);
		Q.push(NULL);
		while(!Q.empty())
		{
			temp = Q.front(); Q.pop();
			if(temp == NULL)
			{
				if(!Q.empty())
				{
					temp = Q.front();
					cout<<temp->data<<" ";
					Q.push(NULL);
				}
			}
			else {
				if(temp->left) Q.push(temp->left);
				if(temp->right) Q.push(temp->right);
			}
		}
	}
	void rightView()
	{	
		if(root == NULL)
			return;

		node *temp = root;
		queue <node*> Q;
		Q.push(temp);
		Q.push(NULL);
		while(!Q.empty())
		{
			temp = Q.front(); Q.pop();
			if(temp == NULL)
			{
				if(!Q.empty())
					Q.push(NULL);
			}
			else {
				if(Q.front() == NULL)
					cout<<temp->data<<" ";
				if(temp->left) Q.push(temp->left);
				if(temp->right) Q.push(temp->right);
			}
		}
	}
	void topView()
	{
		if(root == NULL)
			return;

		int hd = 0;
		root->hd = hd;
		queue<node*> Q;
		map<int,int> m;
		node *temp = root;
		Q.push(temp);
		while(!Q.empty())
		{
			temp = Q.front(); Q.pop();
			hd = temp->hd;
			if(m.count(hd) == 0)
				m[hd] = temp->data;
			if(temp->left)
			{
				temp->left->hd = hd-1;
				Q.push(temp->left);
			}
			if(temp->right)
			{
				temp->right->hd = hd+1;
				Q.push(temp->right);
			}
		}
		for(auto i:m)
			cout<<i.second<<" ";
	}
	void bottomView()
	{	
		if(root == NULL)
			return;

		int hd = 0;
		root->hd = hd;
		queue<node*> Q;
		map<int,int> m;
		node *temp = root;
		Q.push(temp);
		while(!Q.empty())
		{
			temp = Q.front(); Q.pop();
			hd = temp->hd;
			m[hd] = temp->data;
			if(temp->left)
			{
				temp->left->hd = hd-1;
				Q.push(temp->left);
			}
			if(temp->right)
			{
				temp->right->hd = hd+1;
				Q.push(temp->right);
			}
		}
		for(auto i:m)
			cout<<i.second<<" ";
	}
	void verticalSum(node *root, int column, map<int,int> &m)
	{

		if(root == NULL)
			return;

		m[column] += root->data;

		verticalSum(root->left,column-1,m);
		verticalSum(root->right,column+1,m);
	}
	bool isbalanced(node *root) 
	{
		if(root == NULL)
			return 1;

		int left = isbalanced(root->left);
		int right = isbalanced(root->right);
		if(!left || !right)
			return 0;

		int left_height = height(root->left) + 1;
		int right_height = height(root->right) + 1;

		int diff = left_height - right_height;
		if(diff <=1 && diff >=-1)
			return 1;
		else 
			return 0; 
	}
	void diagonal_traversal_util(node *root, int d, map<int,vector<int> > &m)
	{
		if(root == NULL)
			return;

		m[d].push_back(root->data);
		diagonal_traversal_util(root->left,d+1,m);
		diagonal_traversal_util(root->right,d,m);
	}
	void diagonal_traversal()
	{
		if(root == NULL)
			return;

		map<int,vector<int> > m;
		diagonal_traversal_util(root,0,m);
		for(auto i:m)
		{
			for(auto j:i.second)
				cout<<j<<" ";
			cout<<'\n';
		}
	}
	void left_tree(node *root, vector<int> &ans)
	{	
		// function for boundary traversal
		if(root == NULL)
			return;
		
		if(root->left)
		{
			ans.push_back(root->data);
			left_tree(root->left,ans);
		}
		else if(root->right)
		{
			ans.push_back(root->data);
			left_tree(root->right,ans);
		}
	}
	void leaf(node *root, vector<int> &ans)
	{	
		// function for boundary traversal
		if(root == NULL)
			return;

		leaf(root->left,ans);
		if(root->left==NULL && root->right==NULL)
			ans.push_back(root->data);
		leaf(root->right,ans);
	}
	void right_tree(node *root, vector<int> &ans)
	{	
		// function for boundary traversal
		if(root == NULL)
			return;

		if(root->right)
		{
			right_tree(root->right,ans);
			ans.push_back(root->data);
		}
		else if(root->left)
		{
			right_tree(root->left,ans);
			ans.push_back(root->data);
		}
	}
	void boundary_traversal()
	{
		vector<int> ans;
		ans.push_back(root->data);
		left_tree(root->left,ans);
		leaf(root,ans);
		right_tree(root->right,ans);
		for(auto i:ans)
			cout<<i<<" ";
		cout<<'\n';
	}
	bool isLeaf(node *root)
	{
		// function for isSumtree
		if(!root)
			return 0;
		if(!root->left && !root->right)
			return 1;
		return 0;
	}
	bool isSumtree(node *root)
	{
		if(!root || isLeaf(root))
			return 1;

		int Lsum, Rsum;
		if(isSumtree(root->left) && isSumtree(root->right))
		{
			if(!root->left)
				Lsum = 0;
			else if(isLeaf(root->left))
				Lsum = root->left->data;
			else 
				Lsum = 2 * root->left->data;
			
			if(!root->right)
				Rsum = 0;
			else if(isLeaf(root->right))
				Rsum = root->right->data;
			else 
				Rsum = 2 * root->left->data;

			return (root->data == Lsum+Rsum);
		}
		return 0;
	}
};

void deleteTree(node *root)
{
	if(root == NULL)
		return;

	deleteTree(root->left);
	deleteTree(root->right);
	//cout<<root->data<<" ";
	delete(root);
}
bool areStructurallySameTrees(node *root1, node *root2)
{
	// Algorithm:
	// • If both trees are NULL then return true.
	// • If both trees are not NULL, then compare data and recursively check 
	//   left and right subtree structures.
	if(root1==NULL && root2==NULL)
		return 1;
	if(root1==NULL || root2==NULL)
		return 0;

	return (root1->data == root2->data && 
			areStructurallySameTrees(root1->left,root2->left) &&
			areStructurallySameTrees(root1->right,root2->right));
}
bool areMirror(node *root1, node* root2)
{
	// algorithm for checking whether they are mirrors of each other
	if(root1 == NULL && root2 == NULL)
		return 1;
	if(root1 == NULL || root2 == NULL)
		return 0;
	if(root1->data != root2->data)
		return 0;

	return areMirror(root1->left,root2->right) && 
					areMirror(root1->right,root2->left);
}

node *buildBinaryTreeUtil(int *in, int *pr, int inS, int inE, int prS, int prE)
{
	if(inS > inE)
		return NULL;

	node *root = new node(pr[prS]);
	int rootIndex = -1;
	for(int i=inS; i<=inE; i++)
		if(in[i] == root->data)
		{
			rootIndex = i;
			break;
		}

	int LinS = inS;
	int LinE = rootIndex-1;
	int RinS = rootIndex+1;
	int RinE = inE;
	int LprS = prS+1;
	int LprE = LinE-LinS+LprS;
	int RprS = LprE+1;
	int RprE = prE;

	root->left = buildBinaryTreeUtil(in,pr,LinS,LinE,LprS,LprE);
	root->right = buildBinaryTreeUtil(in,pr,RinS,RinE,RprS,RprE);
	
	return root;
}
node *builTree(int *in, int *pr, int size)
{
	return buildBinaryTreeUtil(in,pr,0,size-1,0,size-1);
}

int findIndex(string &str, int si, int ei)
{
	if(si > ei)
		return -1;

	stack<char> S;
	for(int i=si; i<=ei; i++)
	{
		if(str[i] == '(')
			S.push(str[i]);
		else if(str[i] == ')')
		{
			if(S.top() == '(')
			{	
				S.pop();
				if(S.empty())
					return i;
			}
		}
	}

	return -1;
}
node *treeFromString(string &str, int si, int ei)
{
    // Base case
    if (si > ei)
        return NULL;
 
    // new root
    node* root = new node(str[si]-'0');
    int index = -1;
 
    // if next char is '(' find the index of
    // its complement ')'
    if (si+1<=ei && str[si+1]=='(')
        index = findIndex(str, si + 1, ei);

    if (index != -1) 
	{
        root->left = treeFromString(str, si + 2, index - 1);
        root->right = treeFromString(str, index + 2, ei - 1);
    }

    return root;
}

int convert2sumTree_util(node *root)
{	
	if(!root)
		return 0;
	
	int old_val = root->data;
	root->data = convert2sumTree_util(root->left) + convert2sumTree_util(root->right);

	return root->data + old_val;
}
void convert2sumTree(node *root)
{
	int grb = convert2sumTree_util(root);
}

int main() {

	clock_t begin  = clock();
    file_i_o();

	bin_tree b1;

	// int n;
	// cin>>n;
	// int in[n], pre[n];
	// for(int i=0; i<n; i++)
	// 	cin>>in[i];
	// for(int i=0; i<n; i++)
	// 	cin>>pre[i];

	// b1.root = builTree(in,pre,n);

	string str;
	cin>>str;

	b1.root = treeFromString(str,0,str.length()-1);

	b1.levelorder_traversal();
	cout<<endl;

	// convert2sumTree(b1.root);
	// b1.levelorder_traversal();
	// cout<<endl;
	cout<<b1.isSumtree(b1.root);

	deleteTree(b1.root);

	#ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}