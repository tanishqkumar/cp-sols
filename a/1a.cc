#include <iostream> // see /general/running-code-locally
#include <math.h>

using namespace std;

#define p(x) cout << x << endl
#define ull unsigned long long 

int main(){
    long double n, m, a, temp; 
    cin >> n >> m >> a;

    cout << (ull) (ceil(n / a) * ceil(m / a));
    return 0;
}