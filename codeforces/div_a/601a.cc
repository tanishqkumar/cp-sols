#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <string.h>

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


queue<int> q; 
const int maxN = 401; 
int rail_edge[maxN][maxN]; 
int dist[maxN]; 
int n; 

int bfs(int rail){
    dist[1] = 0; 
    q.push(1); 

    while(!q.empty()){
        // grab an el, put its kids on the q and set their dist
        int u = q.front(); q.pop(); 
        loop(v,1,n+1){
            if (rail_edge[u][v] == rail && dist[v] == -1)
                {dist[v]=dist[u]+1; q.push(v);}
        }
    } return dist[n];
}

int main(void){
    int m; cin >> n >> m; 
    memset(dist, -1, sizeof(dist)); 
    while(m--){
        int a, b; cin >> a >> b; 
        rail_edge[a][b] = rail_edge[b][a] = 1; 
    }
    p(bfs(1-rail_edge[1][n]));
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