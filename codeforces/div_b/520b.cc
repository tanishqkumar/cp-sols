#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;

int main(){

    int n, m, cnt = 0;

    cin >> n >> m;

    while (n < m)
    {
        if (m % 2)
            m++;
        else
            m = m / 2;
        cnt++;
    }

    cnt = cnt + n - m;

    cout << cnt << "\n";
    return 0; 
} 


// #include <iostream>
// #include <math.h>
// #include <algorithm>
// #include <vector>
// #include <iomanip>
// #include <queue>

// using namespace std;

// #define p(j) cout << j << endl
// #define ull unsigned long long
// #define loop(i, b, n) for (int i = b; i < n; ++i)
// #define pb push_back
// #define desc greater<int>()

// template <typename T>
// vector<T> gl(int input_len);
// template <typename T>
// void pv(vector<T> vec);

// int main()
// {
//     int n, m; 
//     cin >> n >> m; 
//     // redx2 and blue-1
//         // need to keep number positive
//     // makes sense to use bfs on directed tree because each number has two options that arise from it
//     queue<int> q; 
//     int counter; // how many q elements we've traversed; use this to compute final distance 
//     q.push(n); // init source


// }













































// // helpers
// template <typename T>
// vector<T> gl(int n)
// {
//     vector<T> nums;
//     for (int i = 0; i < n; i++)
//     {
//         T el;
//         cin >> el;
//         nums.pb(el);
//     }
//     return nums;
// }

// template <typename T>
// void pv(vector<T> vec)
// {
//     for (int i = 0; i < vec.size(); ++i)
//         cout << vec[i] << " ";
//     cout << endl;
// }