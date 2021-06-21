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

const int MAXN = 1e5; 

int main()
{
    int n; cin >> n;
    vi adj[n]; 
    // construct the graph
    loop(i, 1, n){
        int a, b; cin >> a >> b;
        adj[--a].pb(i);
        adj[--b].pb(i);
    }
    int at = 0; 
    vi ans(n-1, -1);
    loop(i, 0, n){
        if (adj[i].size() >= 3){
            loop(j, 0, 3) ans[adj[i][j]-1] = j; 
            at = 3; break; 
        }
    }
    loop(i, 0, n-1) if (ans[i] == -1) ans[i] = at++;
    // loop(i, 0, n) pv<int>(adj[i]); 
    loop(i, 0, n-1) p(ans[i]);
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