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

const int maxN = 2e5+1; 
int dp[maxN][2];
const int INF = 1e9+7; 

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vi a = gl<int>(n);
        loop(i, 0, n) { // init
            dp[i][0] = INF; 
            dp[i][1] = INF;
        }
        dp[1][0] = a[0]; // BCs
        dp[0][1] = a[0]; 
        dp[1][1] = a[0] + a[1]; 
        loop(i, 2, n){
            dp[i][0] = min(dp[i-2][1], dp[i-1][1]); 
            dp[i][1] = min(dp[i-2][0] + a[i-1], dp[i-1][0]) + a[i];
            // p("min till "<< i << " is " << min(dp[i][0], dp[i][1]));
        }
        p(min(dp[n-1][0], dp[n-1][1]));
    }
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