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

int main()
{
    int t; cin >> t; 
    while(t--){
        int xa, ya; cin >> xa >> ya; 
        int xb, yb; cin >> xb >> yb; 
        int xf, yf; cin >> xf >> yf; 
        bool xline = (xa == xb && xb == xf && min(ya, yb) <= yf && max(ya, yb) >= yf);
        bool yline = (ya == yb && yb == yf && min(xa, xb) <= xf && max(xa, xb) >= xf);
        int ans = abs(xa - xb) + abs(ya-yb); 
        if (xline || yline) ans+=2; 
        p(ans);
    }return 0;
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