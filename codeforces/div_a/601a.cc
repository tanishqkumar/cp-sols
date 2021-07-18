#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>

using namespace std;

#define p(j) cout << j << endl
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define mp make_pair
#define desc greater<int>()
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define INF 1e9+7

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);


queue<int> q; // 

// take in src, return dist to dest
int bfs(vector<pii>& rails, int src, int dest, bool rail){

}

int main(){ 
    int n, m; cin >> n >> m;
    vector<pii> rails; bool fastrail = false; 
    loop(i,0,m){
        int a, b; cin >> a>> b; 
        if (a == 1 && b == n) fastrail = true; 
        rails.pb(mp(a, b));
    }
    int minrail = INF; int minbus = INF; 
    fastrail ? minrail = 1 : minbus = 1; 
    if (fastrail){
        // find shortest time for bus via bfs
        minbus = bfs(rails, 1, n, !fastrail);
    } else{
        // find shortest time for rail
        minrail = bfs(rails, 1, n, true);
    }
    (minrail == INF || minbus == INF) ? p("-1") : p(max(minrail, minbus));
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