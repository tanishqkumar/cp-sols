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
#define MI numeric_limits<int>::max()

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

const int sz = 1e5;
int dp[sz + 1]; // stores the # steps you need to get i to zero
// TODO
int main(){
    int n, x; 
    cin >> n >> x; 
    vi prices = gl<int>(n);
    vi pages = gl<int>(n);

    // dp[i] = max #pages you can buy with $i
    loop(i, 0, x+1){
        dp[i] = 0; 
        loop(j, 0, n){
            if (prices[j] <= i){
                dp[i] = max(dp[i], dp[i-prices[j]] + pages[j]); 
            }
        }
        p(dp[i]);   
    }
    // for all books j: dp[i] = max(dp[i], dp[i-prices[j]] + pages[j])
    p(dp[x]); return 0; 
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