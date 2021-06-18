#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

#define p(j) cout << j << endl
#define ll long long
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define desc greater<int>()
#define vi vector<int>
#define MI numeric_limits<int>::max()

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

const int sz = 1e3;
int n, m;
string in[sz];

bool e(int i, int j)
{
    return ((0 <= i < n) && (0 <= j < m) && (in[i][j] == '.'));
}

void dfs(int i, int j)
{
    in[i][j] = '#';
    if (e(i - 1, j))
        dfs(i - 1, j);
    if (e(i + 1, j))
        dfs(i + 1, j);
    if (e(i, j - 1))
        dfs(i, j - 1);
    if (e(i, j + 1))
        dfs(i, j + 1);
}

int main()
{
    cin >> n >> m;
    loop(i, 0, n) cin >> in[i]; // add lines

    int ans = 0;
    loop(i, 0, n)
        loop(j, 0, m) if (e(i, j)) dfs(i, j),
        ++ans;
    p(ans);
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