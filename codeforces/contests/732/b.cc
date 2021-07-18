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
#define make_pair mp
#define pii pair<int, int>

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int main(){
    int t;
    cin >> t;
    while (t--){
        int n; cin >> n;
        vi a = gl<int>(n);
        vi odds; vi evens; vi anew; 
        loop(i, 0, n) i & 1 ? odds.pb(a[i]) : evens.pb(a[i]);
        sort(all(odds)); sort(all(evens)); 
        int i = 0; 
        loop(i, 0, n/2){
            anew.pb(evens[i]); anew.pb(odds[i]);
        } sort(all(a));
        n&1?anew.pb(evens[evens.size()-1]):anew.pb(odds[odds.size()-1]);
        bool bad = false; 
        loop(i, 0, n) if (anew[i] != a[i]) bad = true; 
        bad ? p("NO") : p("YES"); 
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