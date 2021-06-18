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

int main(){
    int t; 
    cin >> t; 
    while (t--){ // for each input line
        int x; 
        cin >> x; 
        // if sum larger than sum of {1, 2...9}, impossible
        bool failed = false; 
        if (x > 45){
            cout << -1 << endl;
            failed = true; 
        } 
        if (!failed){
            int prev = 9;
            int sum_so_far = 0;
            // else possible
            vi nums = {};
            while (sum_so_far < x && prev > 0)
            {
                nums.pb(min(x - sum_so_far, prev));
                --prev;
                sum_so_far += nums[nums.size() - 1];
            }
            // output answer
            reverse(nums.begin(), nums.end());
            for (int num : nums)
            {
                cout << num;
            }
            cout << endl;
        }
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