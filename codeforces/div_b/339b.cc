#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <string>

using namespace std;

#define p(j) cout << j << endl
#define ull unsigned long long
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define desc greater<int>()
#define vi vector<int>
#define pass (void)0

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int main()
{
    ull n, m; 
    cin >> n >> m;
    deque<ull> tasks;
    loop(i, 0, m){
        ull task; 
        cin >> task; 
        tasks.push_back(task); 
    } 
    ull ntasks = tasks.size(); 
    ull t = 0, curh = 1; 

    loop(i, 0, ntasks){
        // take off a task and add to t accordingly based on curh and tasks[i]
        ull hno = tasks.front();
        tasks.pop_front(); 
        // update t according to how far we have to travel
        if (hno < curh){
             t += n - (curh - hno);
        } else {
             t += (hno - curh);
        }
        curh = hno; 
    }
    p(t); return 0; 
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