#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define p(j) cout << j << endl
#define ull unsigned long long
#define sort_vec(a) sort(a.begin(), a.end())
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back

vector<int> getline_ints(int input_len);
void piv(vector<int> vec);
template <typename T>; 

bool works(double d, vector<double> a)
{
    bool works = true; 
    // fail if some part unreachable
    loop(i, 0, a.size()) if (a[i] + d < a[i+1] - d) works = false; 
    return works;
}

int main(){
    int n, l; 
    cin >> n >> l; 
    vector<int> a = getline_ints(n); 

    // get array of distances to init d=max_dist
    vector<double> dist; 
    loop(i, 0, n){
        // if first lamp or last lamp double dist to end
        if (i == 0) dist.pb(2*a[i]); 
        if (i == n-1) dist.pb(2*(l-a[i])); 
        dist.pb(a[i+1]-a[i]); // add distance to next lamp
    }
    sort_vec(dist);
    double d = dist[(dist.size() - 1)/2]; // init to largest radius

    // while (!works(d, a) || works(d - (1e-9), a))
}






































// helper
vector<T> getline_ints(int input_len)
{
    vector<T> nums;
    for (int l = 0; l < input_len; l++)
    {
        T el;
        cin >> el;
        nums.push_back(el);
    }
    return nums;
}

void piv(vector<int> vec)
{
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;
}