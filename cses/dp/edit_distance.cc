#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

#define p(j) cout << j << endl
#define ll long long
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define desc greater<int>()
#define vi vector<int>
#define MI numeric_limits<int>::max()
#define minn(a, b, c) min(a, min(b, c))

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);


int main(){
    string a, b; 
    cin >> a >> b; 
    a = " " + a; 
    b = " " + b; 
    int n = a.size(); 
    int m = b.size(); 
    vector<vi> dp(n+1, vi(m+1)); 
    // let dp[i, j] be the edit distance from a[1:i] to b[1:j]
    loop(i, 0, n+1) dp[i][0] = i; // base case
    loop(j, 0, m+1) dp[0][j] = j; 
    loop(i, 1, n+1){ // recurrence
        loop(j, 1, m+1){
            bool same = !(a[i] == b[j]); // 0 if same, 1 if not
            dp[i][j] = minn(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + same);
        }
    }
    p(dp[n][m]); // final case
    return 1; 
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