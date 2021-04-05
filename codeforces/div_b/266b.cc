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
    int n, t; 
    string s; 
    cin >> n >> t >> s; 
    // overall O(nt)
    while (t--){
        loop(i, 0, n){
            if (s[i] == 'B' && s[i+1] == 'G'){
                s[i] = 'G'; 
                s[i+1] = 'B'; 
                ++i; 
            }
        }
    }
    p(s); return 0; 

    // vector<string> vs;
    // loop(i, 0, t){
    //     string dummy_s; 
    //     loop(j, 0, n){
    //         dummy_s += "0"; 
    //     }
    //     vs.pb(dummy_s); 
    // } 
    // vs[0] = s; 
    // loop(i, 0, t-1){
    //     loop(j, 0, n-1){
    //         if (vs[i][j] == 'B' && vs[i][j+1] == 'G'){
    //             vs[i+1][j] = 'G'; 
    //             vs[i+1][j+1] = 'B'; 
    //         } else {
    //             vs[i+1][j] = vs[i][j]; 
    //         }
    //     }
    // }
    // p(vs[t-1]); return 0; 

    // vi bls; 
    // loop(i, 0, n){
    //     s[i] == 'B' ? (i + t < n ? bls.pb(i + t) : bls.pb(n - 1)) : pass;
    // }
    // loop(i, 1, bls.size()){
    //     if (bls[i] == bls[i-1]) --bls[i-1]; 
    // }
    // sort(bls.begin(), bls.end()); 
    // int c = 0; 
    // string out; 
    // loop(i, 0, n){
    //         if (i == bls[c]){
    //             out.pb('B'); 
    //             ++c; 
    //         }
    //         else {
    //             out.pb('G');
    //         }
    // } 
    // p(out); return 0; 
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