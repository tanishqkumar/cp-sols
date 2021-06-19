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
#define new_max(x, y) (((x) >= (y)) ? (x) : (y))

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int sign(int i){
    return (i > 0 ? 1 : -1);
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n; cin >> n; // <2e5
        vi a = gl<int>(n); // |a| < 1e9
        ll ttl = 0;
        for(int p1 = 0; p1 < a.size();){
            int p2 = p1; 
            ll lm = a[p1]; 
            while (sign(a[p1]) == sign(a[p2]) && p2 < a.size()){
                lm = new_max(lm, a[p2]); 
                p2++; 
            }
            p1 = p2; 
            ttl += lm; 
        }
        p(ttl); 
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