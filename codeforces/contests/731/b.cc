#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <string>
#include <set>

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

int main()
{
    int t;
    cin >> t;
    while (t--){
        vi count(26, 0); 
        string s; cin >> s;
        if (s.size() == 1){
            (s == "a") ? p("YES") : p("NO"); continue; 
        }
        bool bad = false; 
        loop(i, 0, s.size()) count[s[i] - 'a']++;
        // if any repeats or missing letters, NO
        loop(i, 0, 25){
            if (count[i] > 1 || count[i] == 0 && count[i+1] == 1 | count[25] > 1)
                bad = true; 
        }
        // split around a and reverse backwards portion
        bool forward = false; 
        loop(i, 0, s.size()-1){ // guaranteed at least size 2
            if (s[i] == 'a') forward = true; 
            if (forward){
                if ((s[i] - 'a') >= (s[i+1] - 'a')) bad = true; 
            } else {
                if ((s[i] - 'a') <= (s[i + 1] - 'a'))
                    bad = true;
            }
        } p((bad ? "NO" : "YES")); 
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