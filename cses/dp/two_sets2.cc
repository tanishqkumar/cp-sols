#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define p(j) cout << j << endl
#define ll long long
#define loop(i, b, n) for (int i = b; i <= n; ++i)
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
	int mod = 1e9+7; 
	cin >> n; 
	int s = n*(n+1)/2; 
	if (s&1){ // odd # can't be split in two subsets
		p("0"); return 1; 
	}  
	vi dp(s+1, 0); // dp[i] = # ways for a subset of 1...n to sum to i
	s /= 2; 
	loop(i, 1, n) // we can split into 
		x 
	p(dp[s]); 
	return 1; 
}






"money_sums.cc" 84L, 1322C
