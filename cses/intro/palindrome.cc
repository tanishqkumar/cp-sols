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
#define vi vector<int>

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int main(){
    string s; 
    cin >> s; 
    // counts for each letter in alphabet
    int c[26] = {}; 
    for (char ltr : s) ++c[ltr-'A']; 
    // count how many odd there are in c
    int nodds = 0; 
    loop(i, 0, 26) nodds += c[i]&1; // indicator trick
    if (nodds > 1){
        p("NO SOLUTION"); 
        return 0; 
    } 
    
    int oi = -1; // assume doesn't exist
    vi two_indeces; 
    string half_out; 
    loop(i, 0, 26){
        if (c[i] == 1) oi = i; 
        else{
            while (c[i] >= 2 && c[i] % 2 == 0){
                half_out.pb((char) 'A' + i); 
                c[i] -= 2; 
            }
        }
    } 
    cout << half_out; 
    if (oi != -1) cout << (char) ('A' + oi); 
    reverse(half_out.begin(), half_out.end()); 
    cout << half_out << endl; 
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