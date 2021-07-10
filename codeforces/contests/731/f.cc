#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <string>

using namespace std;

#define p(j) cout << j << endl
#define vi vector<int>
#define ll long long
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define desc greater<int>()

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int gcd(int a, int b){ // O(logn)
    return ((b == 0) ? a : gcd(b, a % b)); 
}

// implement st
const int maxN = 2e5; 
int st[maxN*2];
int n; 

// returns gcd of [l, r)
int query(int l, int r){
    int res = st[n+l];
    if (r > n)
        return gcd(query(l, n), query(0, r%n));
    for (l += n, r += n; l < r; l >>= 1, r >>= 1){
        if (l & 1)
            res = gcd(res,st[l++]);
        if (r & 1)
            res = gcd(res,st[--r]);
    }
    return res;
}

void build(){
    for(int i = n-1; i > 0; --i)
        st[i] = gcd(st[i * 2], st[i * 2 + 1]);
}

vi constructLayer(int depth){
    // let arr = [6, 12, 8, 10, 22] with depth=2
        // query(i, i+depth+2)
    vi layer(n); 
    loop(i, 0, n) layer[i] = query(i, i+depth+1); 
    return layer; 
}

bool isLayerSame(vi a){ // O(n)
    if (a.size() == 1)
        return true;
    loop(i, 0, a.size() - 1){
        if (a[i] != a[i + 1])
            return false;
    }
    return true;
}

int bs(int u, int l){
    int m = (u + l) / 2; // 1 4, 2 2
    if (u == l) return l; 
    else if (isLayerSame(constructLayer(m))) return bs(u, m);
    else return bs(m+1, l);
}

int main(){
    int t; cin >> t; 
    while(t--){
        cin >> n; 
        vi arr = gl<int>(n);
        loop(i, 0, n) {st[n+i] = arr[i];} // init the st's leaves
        build(); // can query the st for gcd after this
        // binary search on [1, n], with each search checking if all the elements of a layer are the same
        bool isAllSame = 0;
        isLayerSame(arr) ? p("0") : p(bs(1, n));
    }
    return 0;
}

// helpers
template <typename T>
vector<T> gl(int n)
{
    vector<T> nums;
    for (int i = 0; i < n; i++)
    {
        T el;
        cin >> el;
        nums.pb(el);
    }
    return nums;
}

template <typename T>
void pv(vector<T> vec)
{
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;
}