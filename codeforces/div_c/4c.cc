#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <string>
#include <map>

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

// take in [1, 9] x [1, 9] desired sq and pos within it
// int[] get_coords(int square_no, int within_sq){
//     int[] coords = {-1, -1};
//     int[] in = {square_no, within_sq};
//     switch in:
//         case {1, 1}: return {0, 0};
//         case {2, 4}: return {0, 0};



//     assert(coords[0] != -1 && coords[1] != -1);
//     return coords; // [0, 8] x [0, 8] coords
// }

// square nos go from [1, 9]
    // (1, 1) -> (2, 4) -> (3, 7)
        // (4, 2) -> (5, 5) -> (6, 8)
            // (7, 3) -> (8, 6) -> (9, 9)

int main(){
    vector<pair<int, int>> combs;
    combs.pb(make_pair(1, 1));
    combs.pb(make_pair(2, 4));
    combs.pb(make_pair(3, 7));
    combs.pb(make_pair(4, 2));
    combs.pb(make_pair(5, 5));
    combs.pb(make_pair(6, 8));
    combs.pb(make_pair(7, 3));
    combs.pb(make_pair(8, 6));
    combs.pb(make_pair(9, 9));

    int t; cin >> t; 
    while(t--){
        vector<string> sud; 
        loop(i, 0, 9){ // take input and create 9x9 board
            ll num; 
            cin >> num; 
            sud.pb(to_string(num));
        }

        for (auto& comb : combs){
            // int[] coords = get_coords(comb[0], comb[1]);
            sud[comb.first - 1][comb.second - 1] == '2' ? 
                sud[comb.first - 1][comb.second - 1] = '3' : 
                    sud[comb.first - 1][comb.second - 1] = '2';
        }
        cout << endl; 
        // for (square_nos) X (within_sq)
            // get_coords(i, j) = '2'; 

        loop(i, 0, 9) p(sud[i]); 
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