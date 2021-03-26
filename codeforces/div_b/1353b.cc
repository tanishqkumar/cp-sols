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


int main(){
    int n; 
    cin >> n; 
    vector<int> s = gl<int>(n); // s[i] = # kids in group i
    int ntaxis = 0; 
    sort(s.begin(), s.end()); // last is the fatties

    int l = s.size()-1; 
    int f = 0; 
    while (f != l){
        if (s[f] + s[l] <= 4){
            ++f;
            --l;
        } else --l; 
        ntaxis++; 
    }

    p(ntaxis); return 0; 
}





































// helpers
template <typename T>
vector<T> gl(int n)
{
    vector<T> nums;
    for (int i = 0; i < n; i++){
        T el;
        cin >> el;
        nums.pb(el);
    }
    return nums;
}

template <typename T>
void pv(vector<T> vec){
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;
}