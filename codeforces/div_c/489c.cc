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

bool can(int m, int s){
    return ((m != 0 && s <= 9*m) || (m == 0 && s == 0));
}

int main(){ // TODO 
    int m, s; cin >> m >> s; // m < 100, s < 900
    if (!can(m, s)){ p(-1 << " " << -1); return 0; }
    else{
        string str = ""; 
        vi sols;
        // str.pb the smallest i st. !can(m-1, s-i)
        while(str.size() < m && s != 0){
            for (int i = 0; i < 10; ++i){
                if (str.size() == 0 && i == 0) continue;
                else if (can(m - 1, s - i) || ((s < 10) && s == i)){
                        str += to_string(i);
                        s -= i;
                        m -= 1;
                        p("added " << i);
                        break; 
                    }
            }
        } 
        string rev = str; reverse(rev.begin(), rev.end()); 
        // while (str.size() < m) str += to_string(0);
        // if (stoi(str) == 0) p(-1 << " " << -1);
        if (str[str.size() - 1] == '0') p(str << " " << str);
        else p(str << " " << rev);
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