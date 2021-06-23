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

const int maxN = 2e5;
int vis[maxN+1];  
vi adj[maxN+1];
vi a;
int catLimit;

// count how many kids from this vertex down
    // break the cat limit on the path there
int dfs(int v, int cons){
    vis[v] = 1; 
    // is there a cat at v
    (a[v] == 1) ? cons++ : cons = 0; 
    if (cons > catLimit){
        return 0;
    }
    
    int numFromHere = 0;
    loop(i, 0, adj[v].size()) if (vis[adj[v][i]] == 0) numFromHere++;

    // if v a leaf -- base case
    if (adj[v].size() == 0 || numFromHere == 0)
        return 1;

    // if v is not a leaf, dfs over its kids
    int sumKids = 0;
    loop(i, 0, adj[v].size()){
        if (vis[adj[v][i]] == 0){
            sumKids += dfs(adj[v][i], cons);
            vis[adj[v][i]] = 1; 
        }
    }
    return sumKids; 
}

int main(){
    int n, m; cin >> n >> m; // m < n < 1e5
    catLimit = m; 
    a = gl<int>(n); 
    a.insert(a.begin(), -1); // a[v] == 1 or 0 for cat at v
    // construct graph
    loop(i, 0, n-1){
        int x, y; cin >> x >> y; 
        adj[x].pb(y);
        adj[y].pb(x);
    }
    p(dfs(1, 0)); return 0; 
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