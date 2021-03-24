#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define p(x) cout << x << endl
#define ull unsigned long long
#define sort_vec(a) sort(a.begin(), a.end())
#define loop(i, k, n) for(int i = k; i < n; ++i)

// helper
vector<int> getline_ints(int input_len)
{
    vector<int> nums;
    for (int l = 0; l < input_len; l++)
    {
        int el;
        cin >> el;
        nums.push_back(el);
    }
    return nums;
}

void piv(vector<int> vec)
{
    for (auto &i : vec)
        cout << i << " ";
    cout << endl;
}

int main()
{
    int k, l, m, n, d; 
    cin >> k >> l >> m >> n >> d;
    int harmed = 0; 

    loop(i, 1, d+1) {
        if (!(i % k) || !(i % l) || !(i % m) || !(i % n))
            ++harmed;
    }

    p(harmed); 

    return 0; 

}