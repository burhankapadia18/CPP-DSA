#include<iostream>
#include<string>
using namespace std;
#define ll  long long int
void file_i_o()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/CPP-DSA/output.txt","w",stdout);
    #endif
}

template<typename T>
class Node {
public:
	string key;
	T value; // values will be generic
	Node<T>* next;
	Node(string key, T value) 
	{
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};
 
template<typename T>
class HashTable {
public:
	int cs; // current size
	int ts; // total size
	Node<T> **arr;
	HashTable(int ts = 2) 
	{ // constructor
		this->cs = 0;
		this->ts = ts;
		arr = new Node<T>*[this->ts];
		for(int i = 0; i < this->ts; i++) {
			this->arr[i] = NULL;
		}
	}
	void display() 
	{
		for(int i = 0; i < this->ts; i++) {
			Node<T> *temp = this->arr[i];
			cout<<i<<":";
			if(temp == NULL) {
				cout<<endl;
				continue;
			}
			while(temp!= NULL) {
				cout<<"("<<temp->key<<","<<temp->value<<")->";
				temp = temp->next;
			}
			cout<<endl;
		}
	}
	int hashFunc(string key) 
	{	// this returns the bucket index
		ll sum = 0;
		ll factor = 1;
		for(int i = 0; i < key.size(); i++) {
			sum = (sum%this->ts) + ((int)key[i]*factor)%this->ts;
			sum = sum % this->ts;
			factor = ((factor%this->ts) * (37%this->ts))%this->ts;
		}
		return (int)sum;
	}
	void rehash() 
	{
		int old_size = this->ts;
		this->ts = 2*old_size;
		Node<T>** old_table = this->arr;
		this->arr = new Node<T>*[this->ts];
		for(int i = 0; i < this->ts; i++) 
			this->arr[i] = NULL;
		for(int i = 0; i < old_size; i++) 
		{
			Node<T> *temp = old_table[i];
			while(temp != NULL) 
			{
				insert(temp->key, temp->value);
				temp = temp->next;
			}
		}
	}
	void insert(string key, T value) 
	{
		int bi = hashFunc(key);
		T result = search(key);
		if(result != NULL) 
		{
			Node<T>* temp = this->arr[bi];
			while(temp != NULL) 
			{
				if(temp->key == key) {
					temp->value = value;
				}
				temp = temp->next;
			}
			return;
		}
		Node<T>* new_node = new Node<T>(key, value);
		if(this->arr[bi] == NULL) 
			this->arr[bi] = new_node;
		else 
		{	// collision 
			new_node->next = this->arr[bi];
			this->arr[bi] = new_node;
		}
		this->cs++;
		double loadfactor = (double)(this->cs) / (this->ts);
		if(loadfactor > 0.5) {
			rehash();
		}
	}
	T search(string key) 
	{
		int idx = hashFunc(key);
		Node<T> *temp = this->arr[idx];
		while(temp != NULL) 
		{
			if(temp->key == key) 
				return temp->value;
			temp = temp->next;
		}
		return NULL;
	}
};

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();

    // write your code here
    int n;
	cin>>n;
	HashTable<int> *hash = new HashTable<int>();
	while(n--) {
		string key;
		int value;
		cin>>key>>value;
		hash->insert(key, value);
	}
	hash->display();

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}