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

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);


int main(){
    int t; cin >> t; 
    while (t--){
        ll a, b; cin >> a >> b;
        ll gcd = abs(b-a);
        if (gcd == 0) p("0 0"); 
        else {
            ll small = min(b, a);
            ll bel = floor(small/gcd) * gcd;
            p("bel: " << bel);
            ll ab = (floor(small/gcd)+1) * gcd;
            ll r = 1e18L; 
            if (ab == 0 || bel == 0) r = small; 
            p("ab: " << ab);
            p(gcd << " " << min(min(r, small % bel), small % ab));
        }
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