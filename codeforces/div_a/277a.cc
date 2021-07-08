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
#define minn(a, b, c) min(min(a, b), c)

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int parent[100]; // rep of each connected comp
int ranks[100];

int find(int v){
    if (v == parent[v]) return v; 
    // path propagation so future queries are fast on v
    int p = find(parent[v]); 
    parent[v] = p; return p; 
}

int unite(int a, int b){
    a = find(a); b = find(b); 
    if (a == b) return 0; // already in the same component
    if (ranks[a] >= ranks[b]){
        parent[b] = a; 
        ranks[a] += ranks[b];
    } else {
        parent[a] = b; 
        ranks[b] += ranks[a]; 
    }
    return 1; 
}

int main(){
    int n, m; cin >> n >> m; 
    int ncomps = n; // reduce every time we unite() two comps
    int nnl = 0; 
    vector<vi> langs(m, vi()); // list of people that speak each lang
    // construct the disjoint set while looping through people
    loop(i, 0, n){
        int k; cin >> k;
        if (k == 0) ++nnl; 
        loop(j, 0, k){ 
            int l; cin >> l; --l; // indexing 1-off
            langs[l].pb(i); // person i speaks language l
        }
        parent[i] = i; ranks[i] = 1; // init dsu
    }
    // find ncomps by going through langs
    loop(i, 0, m){
        // for lang l, put all its speakers into the same set
        if (!langs[i].size()) continue; 
        loop(j, 0, langs[i].size()-1){
            ncomps -= unite(langs[i][j], langs[i][j + 1]);
        }
    }
    (nnl == n) ? p(ncomps) : p(ncomps-1);
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