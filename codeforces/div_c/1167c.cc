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

const int maxN = 1e5+1; 
int parent[maxN], ranks[maxN]; 

int find(int v){
    if (v == parent[v]) return v; 
    parent[v] = find(parent[v]); 
    return parent[v]; 
}

void unite(int a, int b){
    a = find(a); b = find(b); 
    if (a == b) return; 
    else if (ranks[a] >= ranks[b]){
        parent[b] = a; 
        ranks[a] += ranks[b]; 
    } else {
        parent[a] = b; 
        ranks[b] += ranks[a]; 
    }
}

int main(){
    // init
    loop(i, 0, maxN){ parent[i] = i; ranks[i] = 1; }
    int n, m; cin >> n >> m; 
    loop(j, 0, m){
        int k; cin >> k; 
        vi ins = gl<int>(k); 
        if (k <= 1) continue; // no effect on disjoint sets
        loop(i, 0, k-1)
            unite(ins[i], ins[i+1]);
    }
    vi out(n+1, 0); 
    loop(i, 1, maxN) out[parent[i]]++; // reps
    loop(i, 1, maxN) out[i] = out[find(i)]; // rest
    pv<int>(vi (out.begin()+1, out.end())); return 0;
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