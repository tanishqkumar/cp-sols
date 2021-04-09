#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

#define p(j) cout << j << endl
#define ll long long
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define desc greater<int>()
#define vi vector<int>
#define MI numeric_limits<int>::max()

const int M = 1e9 + 1;

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int main(){
    int n, x; 
    cin >> n >> x; 
    vi coins = gl<int>(n); 
    vi mincoins(x+1, 1e9);

    for (int val : coins) mincoins[val] = 1; 

    loop(i, 1, x+1){
        for (int val : coins){
            if (val <= i)
                mincoins[i] = min(mincoins[i], mincoins[i - val] + 1);
        } 
    }
    mincoins[x] < 1e9 ? p(mincoins[x]) : p(-1); return 0; 
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