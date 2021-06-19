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
#define ull unsigned long long
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define desc greater<int>()

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);
 
int main(){
    int t;
    cin >> t;
    while (t--){
        string s; cin >> s; 
        // need cl contiguous bunch of Ls
        int cl = 0; 
        int tl = 0; 
        loop(i, 0, s.size()){
            if (s[i] == 'L') cl++; 
            else { tl = max(tl, cl); cl = 0; }
        }
        tl = max(cl, tl); 
        p(tl+1); 
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