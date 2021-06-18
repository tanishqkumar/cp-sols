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
#define pi pair<int, int>
#define mp make_pair
#define vi vector<int>
#define MI numeric_limits<int>::max()

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int main()
{
	int n, q;
	cin >> n >> q;
	vector<ll> x(n + 1, 0);
	loop(i, 0, n)
	{
		cin >> x[i + 1];
		x[i + 1] += x[i];
	}
	loop(i, 0, q)
	{
		ll a, b;
		cin >> a >> b;
		p(x[b] - x[a - 1]);
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
