#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

#define p(j) cout << j << endl
#define ull unsigned long long
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define desc greater<int>()

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int main()
{
    int n; 
    cin >> n;  
    vector<int> shop_prices = gl<int>(n); 
    int ndays; 
    cin >> ndays; 
    vector<int> q = gl<int>(ndays); 

    // construct c[i] by making one scan through prices
    vector<int> c(1e5+1, 0); 
    loop(i, 0, n) c[shop_prices[i]]++; 

    // construct ps[]
    vector<ull> ps(1e5+1, 0); 
    ps[0] = c[0]; 
    loop(i, 1, 1e5+1) ps[i] = ps[i-1] + c[i]; // how many shops have this price or less
    // use to answer all q by returning ps[q_i] or n if q_i > ps.size()
    loop(i, 0, ndays){
        if (q[i] > 1e5){
            p(n);
        }  // has enough money to buy everywhere
        else p(ps[q[i]]);
    } return 0; 

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