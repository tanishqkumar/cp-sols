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
#define all(x) x.begin(), x.end()
#define make_pair mp
#define pii pair<int, int>
#define vvi vector<vi>

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int dp[101][101][8];

int main(){
    int n, m, k; cin >> n >> m >> k; 
    vi trees = gl<int>(n);
    vvi paint(n); vi uncolored(n, 0);
    int ngroups = 1; 
    loop(i, 0, n) { 
        vi v = gl<int>(m); paint.pb(v);
        uncolored[i] = (int)trees[i] == 0; 
        // if (i>0) ngroups += trees[i]
    }
    // TODO

    // want exactly k contiguous groups
        // replace all 0 trees with >0 trees at a cost of paint[]
    // dp[i, j, k] is cost to get trees[i:j] exactly k colorings
    // then dp[i, j, k] = 
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