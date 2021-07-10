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

int main(){ 
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        string a, b; cin >> a >> b; 
        vi have(27, 0); vi need(27, 0); 
        loop(i, 0, n) have[a[i]-'a']++; 
        loop(i, 0, n) need[b[i]-'a']++; 
        bool bad = false; 
        loop(i, 0, 26){
            if (have[i] < need[i] || (have[i] -= need[i]) % k)
                bad = true; 
            have[i+1]+=have[i];
        } cout << (bad ? "No" : "Yes") << endl;
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