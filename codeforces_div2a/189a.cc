#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define p(j) cout << j << endl
#define ull unsigned long long
#define sort_vec(a) sort(a.begin(), a.end())
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back

vector<int> getline_ints(int input_len);
void piv(vector<int> vec);

int main()
{
    int n, a, b, c; 
    cin >> n >> a >> b >> c; 

    // nxn table set to 0
    vector<int> dp(n+1, 0); 

    loop(j, 1, n+1){
        if ((j < a) && (j < b) && (j < c)) dp[j] = -1000; 
        else dp[j] = max(dp[j - a], max(dp[j - b], dp[j - c])) + 1;
        piv(dp); 
    }

    p(dp[n]); return 0; 
    // if we have dp[i, j] as the max cuts from [1:j] with the given abc
        // then dp[i, j] = max over k=abc of (dp[j-k] + 1)
    // final is dp[1, n] and bc is dp[0, 0] = 0 
}






































// helper
vector<int> getline_ulls(int input_len)
{
    vector<int> nums;
    for (int l = 0; l < input_len; l++)
    {
        int el;
        cin >> el;
        nums.push_back(el);
    }
    return nums;
}

void piv(vector<int> vec)
{
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;
}