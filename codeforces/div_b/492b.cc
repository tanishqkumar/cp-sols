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
vector<double> getline_doubles(int input_len); 

bool works(double d, vector<double> dist){
    bool works = true; 
    // fail if some part unreachable
    loop(i, 0, dist.size()-1) if (dist[i] + d < dist[i+1] - d) works = false; 
    return works;
}; 

int main(){

    int n, l; 
    cin >> n >> l; 
    // vector<double> a = gl<double>(n); // template gl not working!!
    vector<double> a = getline_doubles(n); 
    sort_vec(a); 
    // get array of distances to init d=max_dist
    vector<double> dist; 
    
    dist.pb(2*a[0]); // base case 

    loop(i, 0, n-1) dist.pb(a[i + 1] - a[i]); // middle cases
    dist.pb((l-a[n-1])*2); // final case 
    sort_vec(dist);
    // pv(dist); 
    double d = dist[(dist.size() - 1)]/2; // init to largest radius

    // double mrs = d; // we know the d we init'd to will succeed since it covers the largest radius
    // double mrf = 0; 
    // // while we don't have min
    // while (!(works(d, a) && !works(d - 1e-9, a))){
    //     // if it is failing outright, we need something larger
    //     if (!works(d, a)) d = (mrs + d)/2; 
    //     else d = (mrf + d)/2; // here we know we can find a smaller radius that works 
    // }

    cout << setprecision(9);
    p(d); return 0; 
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
    // p("got here!2"); 
    return nums;
}

vector<double> getline_doubles(int input_len)
{
    vector<double> nums;
    for (int l = 0; l < input_len; l++)
    {
        double el;
        cin >> el;
        nums.push_back(el);
    }
    return nums;
}

template <typename T>
void pv(vector<T> vec){
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;
}