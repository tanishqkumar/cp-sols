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
    int n, m; cin >> n >> m; 
    vi a = gl<int>(n);
    vi suff(n); // suff[2] is how many distinct from a[2:]
    vi count(1e5+1, 0);
    suff[n-1] = 1; count[a[n-1]]++; 
    for(int i = n-2; i >= 0; i--){
        suff[i] = suff[i+1]; 
        if (count[a[i]] == 0) suff[i]++;
        count[a[i]]++; 
    } 
    while(m--){
        int li; cin >> li; li--; 
        p(suff[li]);
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