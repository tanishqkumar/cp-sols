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

const int maxN = 1e5+1; 
ll parent[maxN];
ll cost[maxN];

ll find(ll v){
    if (v == parent[v]) return v; 
    ll p = find(parent[v]);
    p = parent[v];
    return p; 
}

void unite(ll a, ll b){
    a = find(a); b = find(b); 
    cost[a] <= cost[b] ? parent[b] = a : parent[a] = b; 
}

int main(){
    int n, m; cin >> n >> m; 
    loop(i, 0, n) { cin >> cost[i]; parent[i] = i; }
    while(m--){
        ll x, y; cin >> x >> y; 
        unite(--x, --y); 
    }
    set<ll> s;
    loop(i, 0, n) s.insert(find(i));
    ll ttl = 0;
    for(auto& el : s) { ttl += cost[el];}
    p(ttl); 
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