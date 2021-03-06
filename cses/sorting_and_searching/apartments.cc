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
    int n, m, k; 
    cin >> n >> m >> k;
    vi a = gl<int>(n); // desired apt sizes
    vi b = gl<int>(m); // actual apt sizes
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int c = 0; // # matches counter
    int j = 0; 
    loop(i, 0, n){
        while (b[j] < a[i] - k && j<m) ++j; 
        if (j < m && abs(a[i] - b[j]) <= k) ++c, ++j; // found a match between some b[j] and a[i]
    }
    p(c); return 0; 

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