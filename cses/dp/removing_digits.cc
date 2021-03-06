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

const int mxN=1e6; 
int dp[mxN + 1]; // stores the # steps you need to get i to zero

int main(){
    int n; 
    cin >> n; 
    loop(i, 1, n+1){
        dp[i] = 1e9; 
        int i2 = i; 
        while(i2){
            dp[i] = min(dp[i], dp[i - (i2 % 10)] + 1); // surely we need to check for i2%10 = 10 here
            i2 /= 10; 
        }
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