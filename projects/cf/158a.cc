#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>

using namespace std;

#define p(x) cout << x << endl
#define ull unsigned long long

// helper 
vector<int> getline_ints(int input_len) {
    vector<int> nums; 
    for (int l = 0; l < input_len; l++) {
        int el; 
        cin >> el;
        nums.push_back(el);
    }
    return nums; 
}


int main()
{
    int n, k; 
    cin >> n >> k; 

    vector<int> nums; 
    nums = getline_ints(n); 

    int advance_val, num_winners = 0; 

    advance_val = nums[k-1]; 

    for(int i = 0; i < n; ++i) if (nums[i] >= advance_val && nums[i]) ++num_winners;  

    p(num_winners); return 0; 
}