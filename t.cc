#include <iostream> // see /general/running-code-locally
using namespace std;
#define ll long long; 

#define vi vector<int>; 
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define d(x) cout << "the var is: " << x << endl; 

#define pi pair<int>; 
#define f first
#define s second
#define mp make_pair

// void setIO(string name = "") {
// 	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
// 	if (sz(name)) {
// 		freopen((name+".in").c_str(), "r", stdin); // see /general/io
// 		freopen((name+".out").c_str(), "w", stdout);
// 	}
// }

int main() {
	// setIO("prob");
	long long n; 
	cin >> n; 
	while (n != 1){
		cout << n << " "; 
		if (n % 2 == 0) n /= 2; 
		else n = 3*n + 1; 
	}
	return n; 
}