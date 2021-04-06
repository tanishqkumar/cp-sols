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

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int main(){
    ll n; 
    cin >> n; 
    
    vector<ll> ws = gl<ll>(n); 
    ll ttl = 0; // max possible p size
    loop(i, 0, n) ttl += ws[i]; // read input
    ll ans = 0; 
    // for each subset of ws
    for (ll i = 0; i < (1 << n); ++i){
        ll s1 = 0; 
        // calculate sum_of_subset
        for (ll j = 0; j < n; ++j)
            if ((i>>j)&1)
                s1 += ws[j];
        if (s1 <= ttl / 2) ans = max(ans, s1);
    }
    p((ttl - 2 * ans));
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