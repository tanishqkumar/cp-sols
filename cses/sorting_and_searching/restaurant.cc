#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>

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


int main(){
    int n; 
    cin >> n; 
    vi a(10, 0); 
    vi b(10, 0); 
    loop(i, 0, n) cin >> a[i] >> b[i]; 
    sort(a.begin(), a.end()); // eg. 2, 3, 5
    sort(b.begin(), b.end()); // eg. 4, 8, 9

    int ppl = 0; 
    int max_ppl = 0; 
    loop(t, 1, 10){
        // one sweep through A and B
        if (a[t] == t) ++ppl; 
        if (b[t] == t) --ppl; 
        p(ppl); 
        max_ppl = max(max_ppl, ppl); 
    }
    p(max_ppl); return 0; 
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