#include <iostream>
#include <cmath>
using namespace std;


int f(int n) {
    int p, ans = n;
    
    p = n & (1 << 31);
    n = n & ~(1 << sizeof(n));
    ans = (n << 1) + p;
    
    return ans;
}


int main() {
    short int num = 94, t;
    //cin >> n >> m;

    while(num)
    {
        num=num/2;
        t=num%2;
        cout<<t;
    }
    cout<<num;

   
    //cout << ans;


    return 0;
}
