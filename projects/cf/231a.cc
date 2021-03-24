#include <iostream> 
#include <math.h>

using namespace std;

#define p(x) cout << x << endl
#define ull unsigned long long 

int main(){
    int n; 
    cin >> n; 
    int counter = 0; 

    while (n--){
        int a, b, c; 
        cin >> a >> b >> c;
        if ((a + b + c) > 1) ++counter; 
    }
    cout << counter; 
    return 0; 
}