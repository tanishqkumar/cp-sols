#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <string>

using namespace std;

#define p(j) cout << j << endl
#define ull unsigned long long
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define desc greater<int>()
#define vi vector<int>
#define pass (void)0

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        for (int i = 0; i < n; ++i)
        {
            cout << char('a' + i % b);
        }
        cout << endl;
    }

    return 0;

    // int t; 
    // cin >> t; 
    
    // vi na, aa, ba; 
    // loop(i, 0, t){
    //     int x, y, z; 
    //     cin >> x >> y >> z; 
    //     na.pb(x); aa.pb(y); ba.pb(z); 
    // }

    // loop(i, 0, t){ 
    //     int n = na[i]; 
    //     int a = aa[i]; 
    //     int b = ba[i]; 
    //     loop(j, 0, n){
    //         cout << "j is: " << j % b << endl; 
    //         cout << char('a' + j % b) << " ";
    //     } 
    //     cout << endl; 
    // }
    // return 0; 
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