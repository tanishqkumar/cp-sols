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
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
#define all(a) a.begin(), a.end()

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int main(){
    int n; cin >> n; // need to make n with qsb nums
    vi digits; vi summands; 
    
    while (n) { digits.pb(n % 10); n /= 10; }
    int nneeded = *max_element(all(digits)); 
    
    loop(i, 0, nneeded){
        int s = 0; 
        // if el is nonzero, add it to digit
        loop(j, 0, digits.size()){
            if (digits[j])
                { s += pow(10, j); --digits[j]; }
        }
        summands.pb(s);
    }
    p(nneeded);
    pv<int>(summands);
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