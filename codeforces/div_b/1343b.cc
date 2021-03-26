#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

#define p(j) cout << j << endl
#define ull unsigned long long
#define sort_vec(a) sort(a.begin(), a.end())
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back

template <typename T>
vector<T> gl(int input_len); 
template <typename T>
void pv(vector<T> vec);


int main(){
    int t; 
    cin >> t; // number of lines to read
    vector<int> nums = gl<int>(t); 
    
    // if num/2 is not a power of two, then return NO (not possible)
    for (auto& num: nums){ // O(t)
        if (num % 4 != 0)
            p("NO");
        else{
            p("YES"); 
            int each_side_count = num/2; 
            loop(i, 1, each_side_count+1){ // loops are O(t)
                cout << 2*i << " "; 
            } loop (i, 1, each_side_count+1){ 
                // if i is odd then cout << 2*i -1, eg. 1
                if (i <= each_side_count/2) cout << 2*i -1 << " "; 
                // if i is even then cout << 2* + 1
                else cout << 2*i +1 << " "; 
            } cout << endl; 
        }
    }
    return 0; // overall quadratic
}





































// helpers
template <typename T>
vector<T> gl(int n)
{
    vector<T> nums;
    for (int i = 0; i < n; i++){
        T el;
        cin >> el;
        nums.pb(el);
    }
    return nums;
}

template <typename T>
void pv(vector<T> vec){
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;
}