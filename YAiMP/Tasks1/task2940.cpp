#include <iostream>
using namespace std;


int f(int v, int t) {
    int ans = 0;
    if (v > 0) 
        ans = (v * t) % 109;
    else 
        ans = 109 + ((v * t) % 109);

    return ans;
}


int main() {
    int v, t;
    cin >> v;
    cin >> t;

    cout << f(v, t);


    return 0;
}
