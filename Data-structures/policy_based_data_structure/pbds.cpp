#include <iostream>
using namespace std;

// header files
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

/*
Declaration of container
template <
	typename key,	// key type
	typename Mapped,	// mapped-policy
	typename Cmp_fn = std::less<key>,	// key comarison functor
	typename Tag = rb_tree_tag,	// specifies which underlying data structure to use
	template <
		typename Const_Node_Iterator,
		typename Node_Iterator,
		typename Cmp_Fn_,
		typename Allocator >
	class Node_Update = null_node_update,	// a policy for updating node invariants
	typename Allocator = std::allocator<char> >
class tree;
*/

typedef tree<int, null_type, less<int>, rb_tree_tag,
			tree_order_statistics_node_update>
	ordered_set;

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

// Driver code
int main(int argc, char const *argv[])
{
	file_i_o();

	ordered_set s;
	s.insert(1); 
	s.insert(3); 
	s.insert(4); 
	s.insert(10); 
	s.insert(15);

	int idx = *(s.find_by_order(5));
	int odr = s.order_of_key(1);
	cout<<idx<<" "<<odr;

	return 0;
}