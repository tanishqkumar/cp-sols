#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>

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

int main(){
    int a, b; 
    cin >> a >> b; 
    // want to cut up a x b rectangle into integer squares

    // let dp[i, j] be min cuts to split an i x j rectangle into sqs
    // then let k = max(i, j)
        // so dp[i, j] = min_k'_{1:k}(dp[i, k']) = dp[j, i]
    vector<vi> dp(a+1, vi(b+1, 1e9)); 
    loop(i, 1, a+1) dp[i][1] = 1; // base cases
    loop(j, 1, b+1) dp[1][j] = 1; 
    // recurrence
    loop(i, 1, a+1){
        loop(j, 1, b+1){
            if (i > j){
                loop(kp, 1, i) dp[i][j] = min(dp[i][j], dp[kp][j]);
                dp[j][i] = dp[i][j]; 
            } else{
                loop(kp, 1, j) dp[i][j] = min(dp[i][j], dp[i][kp]);
                dp[i][j] = dp[j][i]; 
            }
            // int k = max(i, j); 
            // p("got here!"); 
        }
    }
    a > b ? p(dp[a][b]) : p(dp[b][a]); return 1; // final case
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