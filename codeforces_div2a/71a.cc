#include <iostream> // see /general/running-code-locally

using namespace std;

#define p(x) cout << x << endl

int main()
{
    int n; 

    string s; 
    cin >> n; 

    while (n--){
        cin >> s; 
        (s.length() > 10) ? p(s[0] << s.length() - 2 << s[s.length()-1]) : p(s); 
    }

    return 0; 

}
