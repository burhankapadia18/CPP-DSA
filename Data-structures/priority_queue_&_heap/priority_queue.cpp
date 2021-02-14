#include<bits/stdc++.h>
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/Users/burhankapdawala/Desktop/C++14/input.txt","r",stdin);
        freopen("/Users/burhankapdawala/Desktop/C++14/output.txt","w",stdout);
    #endif
}

template <typename E, typename C> 
class ListPriorityQueue 
{
    list<E> L;                      // priority queue contents
    C isLess;                       // less-than comparator 
    public:
    int size() const                // number of elements
    {
        return L.size();
    }
    bool empty() const              // is the queue empty?
    {
        return L.empty();
    }
    void insert(const E& e)         // insert element
    {
        typename list<E>::iterator p;
        p = L.begin();
        while(p!=L.end() && !isless(e,*p))
            p++;
        L.insert(p,e);              // insert e before p
    }
    const E& min() const            // minimum element
    {
        return L.front();
    }
    void removeMin()                // remove minimum
    {
        L.pop_front();
    }
};

int main(int argc, char const *argv[])
{
    clock_t begin  = clock();
    file_i_o();

    // write your code here
    

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted in: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}