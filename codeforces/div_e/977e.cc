#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

#define p(j) cout << j << endl
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define vll vector<ll>
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define desc greater<int>()
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

const int maxN = int(2e5);
int n, m;
int parent[maxN], ranks[maxN];

// run on representative of connected comp
int dfs(int src, vvi& adj, vi& vis){
    if (!adj[src].size()) return 0; 
    for (auto& v : adj[src]){
        if (!vis[v]){
            if (adj[v].size() != 2) return 0; 
            vis[v] = 1; dfs(v, adj, vis); 
        }
    }
    return 1; 
}

int find(int a){
    if (a == parent[a]) return a; 
    int x = find(parent[a]); 
    parent[a] = x; 
    return x; 
}

int unite(int a, int b){
    a = find(a); b = find(b); 
    if (a == b) return 0; // already in same comp
    if (ranks[a] >= ranks[b]){
        parent[b] = a; ranks[a] += ranks[b]; 
    } else{
        parent[a] = b; ranks[b] += ranks[a]; 
    } return 1; // actually union'd comps
}

int main(){
    cin >> n >> m; 
    vvi adj(n+1, vi());
    // construct dsu
    loop(i, 0, n){
        parent[i] = i;
        ranks[i] = 1;
    }
    // construct graph 
    loop(i, 0, m){
        int a, b; cin >> a >> b; 
        adj[a].pb(b); adj[b].pb(a); 
        // update connected comps
        unite(a, b); 
    }
    unordered_set<int> reps;
    loop(i, 0, n) reps.insert(find(i));
    int s = 0;
    for (auto &rep : reps){
        vi v(n+1, 0);
        int ans = dfs(rep, adj, v); 
        s += ans;
    }
    p(s); return 0;
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