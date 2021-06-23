#include <iostream>
#include <math.h>
#include <string.h>
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

const int maxN = 100;
int dp[maxN+1][8];

int main(){
    string s; cin >> s; 
    loop(i, 0, s.size()){
        if (stoi(string() + s[i]) % 8 == 0){
            p("YES");
            p(stoi(string() + s[i])); return 0; 
        }
        loop(j, i, s.size()){
            if (i == j) continue;
            if (stoi(string() + s[i] + s[j]) % 8 == 0){
                p("YES");
                p(stoi(string() + s[i] + s[j]));
                return 0;
            }
            loop(k, j, s.size()){
                if (j == k || i == k) continue; 
                // append these 3 diff digits into a num
                int num = stoi(string() + s[i] + s[j] + s[k]); 
                if (num % 8 == 0) { p("YES"); p(num); return 0; }
            }
        }
    }
    p("NO"); return 0; 
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