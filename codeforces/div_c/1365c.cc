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

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int main(){
    int n; cin >> n; 
    vi a = gl<int>(n); vi b = gl<int>(n);
    vi pos(n+1, 0); vi shifts(n, 0);
    loop(i, 1, a.size()+1) pos[a[i]] = i; 
    // go through b and see how many shifts you'd have to do to each el 
    loop(i, 0, b.size()){
        if (pos[b[i]] == i) shifts[0]++; 
        else if (pos[b[i]] > i) shifts[pos[b[i]]-i]++; 
        else shifts[n-i+pos[b[i]]]++;
    }
    p(*max_element(shifts.begin(), shifts.end())); 
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