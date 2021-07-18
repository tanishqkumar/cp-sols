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


int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vi a = gl<int>(n);
        vi b = gl<int>(n);
        vi xs(n, 0); 
        int suma = 0; int sumb = 0; int nops = 0; 
        for (auto& ai : a) suma+=ai; 
        for (auto& bi : b) sumb+=bi; 
        if (suma != sumb){p("-1"); continue;}
        bool any = false; 
        vector<pair<int, int>> ops; 
        loop(i, 0, n) if (a[i] > b[i]) {xs[i] = (a[i] - b[i]);}
        loop(i, 0, n){
            while (b[i] > a[i]){
                loop(j, 0, n){
                    while(xs[j] && b[i] > a[i]){
                        --xs[j]; ++a[i]; ++nops; 
                        ops.pb(make_pair(j+1, i+1));
                    }
                }
            }
        }
        if (!nops) p("0");
        else {
            p(nops); 
            for(auto& op : ops){
                p(op.first << " " << op.second); 
            }
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