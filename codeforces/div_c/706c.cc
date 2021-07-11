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
#define all(x) x.begin(), x.end()

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

const int maxN = 1e5 + 1; 
// dp[i, j] is cost of sorting 0:i strings, with the i-th reversed == j
int dp[maxN][2];

bool isLex(string a, string b){
    return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}

string rev(string s){ // doesn't touch s
    string ns = s; 
    reverse(all(ns)); return ns; 
}

int main(){
    int n; cin >> n;
    vi costs = gl<int>(n);
    vector<string> vs; 
    loop(i, 0, n) {string s; cin >> s; vs.pb(s);}
    // BC: dp[0][0] = 0 and dp[0][1] = costs[0]
    dp[0][0] = 0; dp[0][1] = costs[0]; 
    loop(i, 1, n){ // RR
        if (dp[i-1][0] == -1 && dp[i-1][1] == -1)
            {dp[i][0] = -1; dp[i][1] = -1;}
        else if (dp[i-1][0] != -1 && dp[i-1][1] == -1){
            dp[i][0] = isLex(vs[i-1], vs[i]) ? dp[i-1][0] : -1; 
            dp[i][1] = isLex(vs[i-1], rev(vs[i])) ? dp[i-1][0] + costs[i] : -1; 
        } else if (dp[i-1][1] != -1 && dp[i-1][0] == -1){
            dp[i][0] = isLex(rev(vs[i-1]), vs[i]) ? dp[i-1][1] : -1; 
            dp[i][1] = isLex(rev(vs[i-1]), rev(vs[i])) ? dp[i-1][1] + costs[i] : -1; 
        } else{
            // both are possible
            int a = -1; int b = -1; 
            if (isLex(vs[i-1], vs[i])) a = dp[i-1][0]; 
            else if (isLex(rev(vs[i-1]), vs[i])) a = dp[i-1][1]; 
            dp[i][0] = a;    
            if (isLex(vs[i-1], rev(vs[i]))) b = dp[i-1][0] + costs[i]; 
            else if (isLex(rev(vs[i-1]), rev(vs[i]))) b = dp[i-1][1] + costs[i]; 
            dp[i][1] = b;    
        }
    }
    // ANS: min(dp[n-1][0], dp[n-1][1])
    (dp[n - 1][0] == -1 || dp[n - 1][1] == -1) ? 
            p(max(dp[n - 1][0], dp[n - 1][1])) : p(min(dp[n-1][0], dp[n-1][1]));
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