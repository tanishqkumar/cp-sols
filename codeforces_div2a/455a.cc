#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define p(x) cout << x << endl
#define ull unsigned long long
#define sort_vec(a) sort(a.begin(), a.end())
#define loop(i, n) for (int i = 0; i < n; ++i)

vector<int> getline_ints(int input_len);
void piv(vector<int> vec);

// code goes here
int main()
{
    
}






































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