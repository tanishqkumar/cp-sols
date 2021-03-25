#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define p(x) cout << x << endl
#define ull unsigned long long
#define sort_vec(a) sort(a.begin(), a.end())
#define loop(i, b, n) for (ull i = b; i < n; ++i)

vector<ull> getline_ulls(ull input_len);
void piv(vector<ull> vec);

// code goes here
int main()
{
    ull n; 
    cin >> n; // len(a)
    ull max_el = 10e5; 
    vector<ull> a = getline_ulls(n); 
    vector<ull> dp(max_el+1, 0); // dp[0] = 0 set here
    vector<ull> count(max_el+1, 0); 

    // precalc count is O(n)
    loop(i, 0, n) ++count[a[i]];
    dp[1] = count[1];

    loop(i, 2, max_el+1){
        dp[i] = max(dp[i - 1], dp[i - 2] + (count[i] * i));
    } 

    p(dp[max_el]); 
    return 0; 
}






































// helper
vector<ull> getline_ulls(ull input_len)
{
    vector<ull> nums;
    for (ull l = 0; l < input_len; l++)
    {
        ull el;
        cin >> el;
        nums.push_back(el);
    }
    return nums;
}

void piv(vector<ull> vec)
{
    for (ull i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;
}