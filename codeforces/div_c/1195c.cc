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
#define maxx(a, b, c) max(max(a, b), c)

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int main(){
    ll n; cin >> n; 
    vector<ll> h1 = gl<ll>(n);
    vector<ll> h2 = gl<ll>(n);
    vector<vector<ll>> dp(n, vector<ll>(3, 0));
    // dp[j, i] represents max height if you take i \in 0,1,2 from col j
    // final ans is max(dp[n-1, i]) and bc dp[0, i] is first col choices
    // rr: dp[j, 0] = max_i(dp[j-1, i])
    // dp[j, 1] = max(dp[j-1, 0], dp[j-1, 2]) + h1[j]
    // dp[j, 2] = max(dp[j-1,0], dp[j-1, 1]) + h2[j]
    dp[0] = {0, h1[0], h2[0]};
    loop(j, 1, n){
        dp[j][0] = maxx(dp[j - 1][0], dp[j - 1][1], dp[j - 1][2]);
        dp[j][1] = max(dp[j-1][0], dp[j-1][2]) + h1[j]; 
        dp[j][2] = max(dp[j-1][0], dp[j-1][1]) + h2[j]; 
    }
    p(maxx(dp[n-1][0], dp[n-1][1], dp[n-1][2]));
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