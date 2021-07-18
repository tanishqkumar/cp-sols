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
#define vvi vector<vi>
#define ll long long
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define desc greater<int>()
#define minn(a, b, c) min(min(a, b), c)

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<char>> mat;
        loop(i, 0, n)
        {
            vector<char> l = gl<char>(n);
            mat.pb(l);
        }
        bool bad = false;
        loop(i, 0, n - 1)
        {
            loop(j, 0, n - 1)
            {
                if (mat[i][j] == '1' && !(mat[i + 1][j] == '1' || mat[i][j + 1] == '1'))
                    bad = true;
            }
        }
        bad ? p("NO") : p("YES");
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