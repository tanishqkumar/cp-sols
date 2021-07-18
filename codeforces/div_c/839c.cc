#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <string>
#include <set>

using namespace std;

#define p(j) cout << j << endl
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define desc greater<int>()
#define minn(a, b, c) min(min(a, b), c)

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

const int maxN = 2e5 + 1;
int vis[maxN]; 
int vis2[maxN]; 
int parent[maxN]; 

void dfs(int src, vi& path_lens, vvi& adj, int curr_len){
    vis[src] = 1; 
    // no kids, add to path_lens as end of path
    if (!adj[src].size()) { path_lens.pb(curr_len);}
    for (auto &v : adj[src]){ // had kids, recurse
        if (!vis[v])
            dfs(v, path_lens, adj, curr_len + 1);
    }
}

void find_kids_dfs(int src, vvi& adj, vi& kids){
    vis2[src] = 1; 
    if (!adj[src].size()) kids.pb(src);
    for (auto &v : adj[src]){ // had kids, recurse
        if (!vis2[v])
            find_kids_dfs(v, adj, kids);
    }
}

int main(){
    int n; cin >> n;
    vvi adj(n+1); vi kids; 
    loop(i, 0, maxN) { vis[i] = 0; vis2[i] = 0; parent[i] = 0; }
    loop(_, 0, n-1){
        int a, b; cin >> a >> b; 
        adj[a].pb(b); parent[b] = a; 
    } 
    // all init above
    // dfs(1, path_lens, adj, 0); // logic
    vector<double> dp(n);
    vi kids; find_kids_dfs(1, adj, kids); 
    loop(u, 1, n){
        vi path_lens; 
        int s = 0; 
        dfs(u, path_lens, adj, 0);
        for(auto& len : path_lens) s+=len; 
        int nkids = adj[u].size(); 
        dp[u] = s/nkids; 
    } p(dp[1]); 
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