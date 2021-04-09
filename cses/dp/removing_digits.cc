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

const int M = 1e9 + 1;

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int main(){
    int n; 
    cin >> n; 
    vi dp(10, 0); // stores the # steps you need to get i to zero
    
    loop(i, 1, 10) dp[i] = 1; // anything from 0-9 needs only 1 step
    if (n < 10) {
        p(dp[n]);
        return 0; 
    }

    loop(i, 10, n+1){
        vi digits; 
        int tmp = i; 
        do {
            digits.pb(tmp%10); 
            tmp /= 10; 
        } while(tmp > 0);
        pv<int>(digits); 
        int min = 1e9; 
        // dp[i] = min_digits_in_i(dp[i-d])+1
        for(int digit : digits){
            if (dp[i-digit] + 1< min) min = dp[i-digit]+1; 
        }
        dp[i] = min; 
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