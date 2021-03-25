#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define p(j) cout << j << endl
#define ull unsigned long long
#define sort_vec(a) sort(a.begin(), a.end())
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back

vector<int> getline_ints(int input_len);
void piv(vector<int> vec);

int main()
{
    int n; 
    cin >> n; 
    vector<int> nums = getline_ints(n);
    int max_len_so_far = 1; 
    int curr_len = 0; 

    loop(i, 0, n){
        if (nums[i] >= nums[i-1]) ++curr_len; 
        else max_len_so_far = max(max_len_so_far, curr_len), curr_len = 1; 
    }
    max_len_so_far = max(max_len_so_far, curr_len); 

    p(max_len_so_far);
    return 0;
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
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;
}