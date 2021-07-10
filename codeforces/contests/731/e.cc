#include <iostream>
#include <math.h>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <string>

using namespace std;

#define p(j) cout << j << endl
#define vi vector<int>
#define ll long long
#define vll vector<ll>
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define desc greater<int>()
#define all(x) x.begin(), x.end()

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int main(){
    int q; cin >> q; 
    while(q--){
        int n, k; cin >> n >> k; 
        vll a = gl<ll>(k); for (auto& ai : a) ai--; 
        vll t = gl<ll>(k);
        vll temps(n, (ll) INT_MAX);
        loop(i, 0, k) temps[a[i]] = t[i];
        if (temps.size() == 1) {pv<ll>(temps); continue; }
        loop(i, 1, n) temps[i] = min(temps[i-1]+1, temps[i]); 
        reverse(all(temps)); 
        loop(i, 1, n) temps[i] = min(temps[i-1]+1, temps[i]); 
        reverse(all(temps)); 
        pv<ll>(temps); 
    }
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