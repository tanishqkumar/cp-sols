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
    int k, n, w; 
    cin >> k >> n >> w; 
    int sum = 0; 

    // total cost of banas he wants
    for (int i = 1; i < w+1; ++i){
        sum += i*k; 
    }

    (sum - n >= 0) ? p(sum - n) : p(0); 
    return 0; 
}