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

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);


int main(){
    int n; cin >> n; 
    vi a = gl<int>(n);
    vector<vi> dp(n+1, vi(3, 101)); // at most 100 days, of rest
    // base case
    dp[0] = {0, 0, 0}; 
    // dp[i][j] represents min rest days if we made choice j on day i
    loop(i, 1, n+1){
        int prev = minn(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]); 
        dp[i][0] = prev+1; 
        if (a[i-1] == 1 || a[i-1] == 3) dp[i][1] = min(dp[i-1][0], dp[i-1][2]); 
        else dp[i][1] = 1<<30; 
        if (a[i-1] == 2 || a[i-1] == 3)
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        else dp[i][2] = 1<<30; 
    }
    // final answer, overall min rest days
    p(minn(dp[n][0], dp[n][1], dp[n][2])); 
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