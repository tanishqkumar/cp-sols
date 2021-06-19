#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>

using namespace std;

#define p(j) cout << j << endl
#define ll long long
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define desc greater<int>()
#define pi pair<int, int>
#define mp make_pair
#define vi vector<int>
#define MI numeric_limits<int>::max()

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

const int MAXN = 2*1e5;
int t[4 * MAXN]; // seg tree

void build(vi& a, int v, int tl, int tr){
    if (tl == tr)
        t[v] = a[tl];
    else{
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val){
    if (tl == tr)
        t[v] = new_val;
    else{
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r){
    if (l > r) return INT32_MAX;
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr)/2;
    return min(query(2 * v, tl, tm, l, min(tm, r)), query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
}

int main(){
    int n, q; cin >> n >> q;
    vi arr = gl<int>(n);
    build(arr, 1, 0, n - 1);
    for (int i = 0; i < q; i++){
        vi in = gl<int>(3); 
        if (in[0] == 1) update(1, 0, n - 1, in[1] - 1, in[2]); 
        else{
            in[1] == in[2] ? p(query(1, 0, n - 1, in[1] - 1, in[2] - 1)) : p(query(1, 0, n - 1, in[1] - 1, in[2] - 2));
        }
    }
    return 1;
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

