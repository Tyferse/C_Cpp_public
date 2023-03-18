#include <iostream>
using namespace std;


int main (){
    long double n;
    cin >> n;

    n = n - (long long)n;
    cout << (long long)(n * 10);
    
    
    return 0;
}
