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

ll fact(ll n){
    return (n == 0 ? 1 : n * fact(n - 1));
}

ll nCr(ll n, ll r){
    return fact(n)/(fact(n-r) * fact(r));
}

int main(){
    string s1, s2; cin >> s1; cin >> s2; 
    int pgap = 0; int mgap = 0; int nq = 0; 
    loop(i, 0, s1.size()){
        pgap += (s1[i] == '+'); 
        mgap += (s1[i] == '-'); 
    } loop(i, 0, s2.size()){
        pgap -= (s2[i] == '+'); 
        mgap -= (s2[i] == '-'); 
        nq += (s2[i] == '?'); 
    }
    pgap = max(pgap, 0); mgap = max(mgap, 0); 
    int tgap = pgap + mgap; 
    if (pgap == 0 && mgap == 0){
        p((double)1);
    } else if (tgap > nq){
        p((double)0);
    }else{
        cout << setprecision(9) << (double)nCr(nq, pgap) / (1 << nq) << endl;
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