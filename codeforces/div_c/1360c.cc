#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;

#define p(j) cout << j << endl
#define vi vector<int>
#define ull unsigned long long
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define desc greater<int>()

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int parityImbalance(vi& a){
    int numEven = 0; int numOdd = 0;
    loop(i, 0, a.size()) a[i] & 1 ? numOdd++ : numEven++;
    numOdd &= 1; numEven &= 1; 
    // cout << "numOdd: " << numOdd << " and numEven: " << numEven << endl; 
    return (numOdd + numEven)/2; // can only be 1 or 0
}

int numAdjPairs(vi& a){
    int numAdjPairs = 0; 
    loop(i, 0, a.size()){
        loop(j, 0, a.size()){
            if (i != j && (a[i] - a[j] == 1))
                numAdjPairs++;
        }
    }
    return numAdjPairs; 
}

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vi a = gl<int>(n); 
        // cout << "PI: " << parityImbalance(a) << " and NAP: " << numAdjPairs(a) << endl; 
        parityImbalance(a) <= numAdjPairs(a) ? 
                p("YES") : p("NO");
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