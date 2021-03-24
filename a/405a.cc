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

void piv(vector<int> vec){
    for (auto& i: vec) cout << i << " "; 
    cout << endl; 
}

int main()
{
    int num_cols; 
    cin >> num_cols; 

    // output will be nondecreasing
    vector<int> ints = getline_ints(num_cols); 
    sort_vec(ints); 
    piv(ints); 

    return 0; 
}