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
    int t;
    cin >> t;
    while (t--){
        int n; cin >> n; // n < 1e9
        ll a = 0, b = 0, c = 0;
        loop(i, 2, sqrt(n)){ // eg. found a=3
            if (n % i == 0){
                a = (int)i;
                loop(j, 2, sqrt(n / a)){
                    if ((n / a) % j == 0 && j != a){
                        b = (int)j;
                        c = (int) n/(a*b);
                    }
                    if (a != b && a != c && b != c && c > 1){
                        p("YES");
                        p(a << " " << b << " " << c);
                        goto nextt; 
                    }
                }
            }
        } 
    p("NO");
nextt:;
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