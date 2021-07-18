#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <unordered_map>

using namespace std;

#define p(j) cout << j << endl
#define ull unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define loop(i, b, n) for (int i = b; i < n; ++i)
#define pb push_back
#define mp make_pair
#define desc greater<int>()
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

template <typename T>
vector<T> gl(int input_len);
template <typename T>
void pv(vector<T> vec);

int main(){
    int n, m; cin >> n >> m;
    unordered_map<string, int> name2num; 
    unordered_map<int, string> num2name; 
    loop(i, 0, n){
        string name; cin >> name; 
        name2num[name] = i; 
        num2name[i] = name; 
    } 
    vector<pii>excluded_pairs; 
    loop(i, 0, m){
        string a, b; cin >> a >> b;
        excluded_pairs.pb(mp(name2num[a], name2num[b]));
    }
    int max_clique_sz = 0; 
    vi max_clique; 
    loop(i, 0, 1<<n){
        vi subset;
        // for each subset of n<=16 people
        loop(j, 0, n) if (i & (1<<j)) subset.pb(j);
        
        bool clique = true; 
        // are they a clique?
        for(auto& pair: excluded_pairs){
            if (find(all(subset), pair.first) != subset.end() && 
                find(all(subset), pair.second) != subset.end()){
                    clique = false; 
                }
        }
        // if so, compare to curr_max and store bit pattern
        if (clique && (int)subset.size() > max_clique_sz){
            max_clique_sz = (int) subset.size();
            max_clique.clear(); 
            for(auto& i : subset) max_clique.pb(i);
        }
    }
    vector<string> names; 
    for(auto& i : max_clique) names.pb(num2name[i]);
    sort(all(names));
    p(names.size());
    for(auto& name : names) p(name);
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