#include<iostream>
#include<queue>
using namespace std;

int max(int a, int b){
	return a>b?a:b;
}

class node {
public:
	int data;
	node *left;
	node *right;
	
	node(int info){
		data = info;
		left = right = NULL;
	}
};

class bst {
public:
	node *root;
	bst(){
		root = NULL;
	}
	node* insert(node* root,int data) {
		if(root == NULL) { 
			root = new node(data);
		} 
		else if(data <= root->data) {
			root->left = insert(root->left,data);
		}
		else {
			root->right = insert(root->right,data);
		}
		return root;
	}
	node* deleteNode(node *root, int data){
		if(root == NULL)
			return root;
		else if(data < root->data)
			root->left = deleteNode(root->left, data);
		else if(data > root->data)
			root->right = deleteNode(root->right, data);
		else {  // node founded...ready to delete
			// case:1 no child
			if(root->left == NULL && root->right == NULL){
				delete(root);
				root = NULL;
			}
			// case:2 one child
			else if(root->left == NULL){
				node *temp = root;
				root = root->right;
				delete(temp);
			}
			else if(root->right == NULL){
				node *temp = root;
				root = root->left;
				delete(temp);
			}
			// case:3 two children
			else {
				node *temp = findMin_1(root->right);
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data);
			}
			
		}
		return root;
	}
	void inorder_traversal_1(node *p){
		//recursive
		if(!p)
			return;
		inorder_traversal_1(p->left);
		cout<<p->data<<" ";
		inorder_traversal_1(p->right);
	}
	void preorder_traversal_1(node *p){
		//recursive
		if(!p)
			return;
		cout<<p->data<<" ";
		preorder_traversal_1(p->left);
		preorder_traversal_1(p->right);

	}
	void levelorder_traversal(){
		if(root == NULL)
			return;
		queue<node*> Q;
		Q.push(root);
		while(!Q.empty()){
			node *current = Q.front();
			cout<<current->data<<" ";
			if(current->left != NULL)
				Q.push(current->left);
			if(current->right != NULL)
				Q.push(current->right);
			Q.pop();
		}
	}
	node *findMin_1(node *p){
		// iterative method
		if(p == NULL)
			return NULL;
		else {
			while(p->left != NULL)
				p = p->left;
			return p;
		}
	}
	node *find(int data){
		node *ptr = root;
		while(ptr != NULL){
			if(data < ptr->data)
				ptr = ptr->left;
			else if(data > ptr->data)
				ptr = ptr->right;
			else{
				return ptr;
			}	
		}
		return NULL;
	}
	void findMin_2(node *p){
		// recurisive
		if(p == NULL){
			cout<<"tree is empty";
		}
		else if(p->left == NULL){
			cout<<"\nminimum is "<<p->data;
		}
		else 
			findMin_2(p->left);
	}
	node *findMax_1(node *root){
		// iterative method
		if(root == NULL)
			cout<<"tree is empty";
		else {
			while(root->right != NULL)
				root = root->right;
			//cout<<"\nmaximum element is "<<root->data;
		}
		return root;
	}
	void findMax_2(node *p){
		// recurisive
		if(p == NULL){
			cout<<"tree is empty";
		}
		else if(p->right == NULL){
			cout<<"\nmaximum is "<<p->data;
		}
		else 
			findMax_2(p->right);
	}
	int find_height(node *p){
		if(p == NULL)
			return -1;
		return (max(find_height(p->left),find_height(p->right))+1);
	}
	void inorder_successor(int data){
		node *current = find(data);
		if(current == NULL){
			cout<<"error!!";
			return;
		}
		// case:1  node has right subtree
		if(current->right != NULL){
			node *p = findMin_1(current->right);
			cout<<"successor of "<<data<<" is "<<p->data;
			return;
		}
		// case:2  no right subtree
		else {
			node *successor = NULL, *ancestor = root;
			while(ancestor != current){
				if(current->data < ancestor->data){
					successor = ancestor;
					ancestor = ancestor->left;
				}
				else {
					ancestor = ancestor->right;
				}
			}
			cout<<"successor of "<<data<<" is "<<successor->data;
		}
	}
	void inorder_predecessor(int data){
		node *current = find(data);
		if(current == NULL){
			cout<<"error!";
			return;
		}
		// case:1 node has left subtree
		if(current->left){
			node *p = findMax_1(current->left);
			cout<<"predecessor of "<<current->data<<" is "<<p->data;
		}
		// case:2 node has no left subtree
		else {
			node *p=NULL, *itr=root;
			while(itr != current){
				if(current->data < itr->data)
					itr = itr->left;
				else {
					p = itr;
					itr = itr->right;
				}
			}
			if(p)
				cout<<"predecessor of "<<current->data<<" is "<<p->data;
			else 
				cout<<"no inorder predecessor";
		}

		return;
	}
	void findLCA(int a, int b){
		if(root == NULL)
			return;
		node *ptr = root;
		while(1){
			if( (a < ptr->data && b > ptr->data) || (a > ptr->data && b < ptr->data) ){
				cout<<ptr->data<<endl;
				return;
			}
			if(a < ptr->data)
				ptr = ptr->left;
			else 
				ptr = ptr->right;
		}
	}
};
void deleteTree(node *root){
	if(root == NULL)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	//cout<<root->data<<" ";
	delete(root);
}

int isBST(node *node, int min, int max){
	
	// if(node == NULL) return 1;

	// if( (node->data > min) && (node->data < max)
	// 	&& isBST(node->left, min, node->data)
	// 	&& isBST(node->left, node->data, max))
	// 	return 1;
	// else 
	// 	return 0;

	//an empty tree is BST 
    if (node==NULL)  
        return 1;  
              
    //false if this node violates 
    //the min/max constraint 
    if (node->data < min || node->data > max)  
        return 0;  
      
    //otherwise check the subtrees recursively,  
    //tightening the min or max constraint
    return
		// Allow only distinct values  
        isBST(node->left, min, node->data-1) && 
		// Allow only distinct values
        isBST(node->right, node->data+1, max);  
	
}
void bst2dll(node *root){
	if(root == NULL)
		return;
	static node *prev = NULL;
	bst2dll(root->left);
	if(prev != NULL) {
		root->left = prev;
		prev->right = root;
	}
	prev = root;
	bst2dll(root->right);
}
node *buildBST(int a[], int left,int right){
	// builds a bst using a sorted array
	if(left>right)
		return NULL;
	int mid;
	node *newnode;
	if(left == right)
		newnode = new node(a[left]);
	else {
		mid = left + ((right-left)/ 2);
		newnode = new node(a[mid]);
		newnode->left = buildBST(a,left,mid-1);
		newnode->right = buildBST(a,mid+1,right);
	}
	return newnode;
}
node *bst_from_preorder(int arr[], int start, int end){

	if(start == end){
		node *root = new node(arr[start]);
		return root;
	}
	if(start > end)
		return NULL;

	node *root = new node(arr[start]);

	int L_start, L_end, R_start, R_end;
	L_start = start+1;
	R_end = end;
	for(R_start = start+1; arr[R_start]<arr[start]; R_start++);
	L_end = R_start-1;

	root->left = bst_from_preorder(arr,L_start,L_end);
	root->right = bst_from_preorder(arr,R_start,R_end);

	return root;
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/output.txt","w",stdout);
    #endif

	bst b1; 

	int n;
	cin>>n;
	int data;
	while(n--) {
		cin>>data;
		b1.root = b1.insert(b1.root,data);
	}

	b1.inorder_traversal_1(b1.root);
	bst2dll(b1.root);
	

	deleteTree(b1.root);

	return 0;
}