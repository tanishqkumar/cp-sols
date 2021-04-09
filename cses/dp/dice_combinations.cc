#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;


#define p(j) cout << j << endl
#define ll long long
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define desc greater<int>()
#define vi vector<int>

const ll M = 1e9+1; 

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int main(){
    int n; 
    cin >> n; 
    vector<ll> dp(n+1, 0); // one way to get n=0 off the bat
    dp[0] = 1; // one way to get n=1

    loop(i, 1, n+1){    
        for (ll j = 1; j <= min(6, i); ++j) dp[i] = (dp[i] + dp[i-j])%M; 
    }
    p(dp[n]); return 0; 
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