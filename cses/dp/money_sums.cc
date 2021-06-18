#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
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

int main(){
	int n; 
	cin >> n;
	vi x = gl<int>(n); 
	vector<bool> dp(1e5+1, 0); // dp[i] is whether we can make i from x[]
	dp[0] = 1; // base case -- we can always make 0 using nothing
	for(int xj : x) // for some fixed xj, which of [1:1e5] can we make using rest
		// for(int i = 1; i < 1e5+1; ++i)
		for(int i = 1e5+1; i; --i)
			if (i >= xj) dp[i] = dp[i] | dp[i-xj]; 
	vi ans; // all the nums from 1:1e5 that we can make
	loop(a, 1, 1e5+1)
		if (dp[a]) ans.pb(a); 
	p(ans.size()); 
	pv<int>(ans); 
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
