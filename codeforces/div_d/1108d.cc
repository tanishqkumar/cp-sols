#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <string>

using namespace std;

#define p(j) cout << j << endl
#define vi vector<int>
#define ll long long
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define desc greater<int>()

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int main(){
    // RBG: 012
    int n; cin >> n; 
    string s; cin >> s; 
    int cnt = 0; string out; 
    vi nums; 
    loop(i, 0, n){
        switch (s[i]){
            case 'R': {nums.pb(0); break; }
            case 'G': {nums.pb(1); break; }
            case 'B': {nums.pb(2); break; }
        }
    }
    loop(i, 1, n){
        if (nums[i] == nums[i-1]){
            ++cnt; 
            if (i == n-1 || nums[i-1] == nums[i+1]) 
                nums[i] = (nums[i]+1)%3; 
            else {
                int sum = nums[i-1]+nums[i+1]; 
                switch(sum){
                    case 1: {nums[i]=2; break; } 
                    case 2: {nums[i]=1; break; } 
                    case 3: {nums[i]=0; break; } 
                } }
        }
    } 
    loop(i, 0, nums.size()){
        switch(nums[i]){
            case 0: {out.pb('R'); break;} 
            case 1: {out.pb('G'); break;} 
            case 2: {out.pb('B'); break;} 
        }
    }
    p(cnt); p(out); 
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