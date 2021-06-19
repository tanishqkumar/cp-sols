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
    int t, n; 
    cin >> t; 
    while(t--){
        cin >> n; 
        vi arr = gl<int>(n);
        vi count(n + 1, 0);
        loop(j, 0, arr.size()) count[arr[j]]++;
        int most_common_amount = 0; 
        int num_unique = 0; 
        loop(j, 1, n + 1){ // loop over count[]
            if(count[j] > most_common_amount){
                most_common_amount = count[j]; // how often the most common skill level is listed
            } if (count[j] != 0) num_unique++; 
        } 
        // cout << "num_unique: " << num_unique << " most_common_amount: " << most_common_amount << endl; 
        p(max(min(num_unique - 1, most_common_amount), min(num_unique, most_common_amount-1)));
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