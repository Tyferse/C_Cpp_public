#include <iostream>
using namespace std;


int main (){
    int n;
    cin >> n;

    bool primes[n + 1] = {};
    for (int i = 0; i < n + 1; i++) {
        primes[i] = true;
    }

    for (int i = 2; i < n + 1; i++) {
        for (int j = 2*i; j < n + 1; j+=i) {
            primes[j] = false;
        }
    }

    for (int i = 2; i < n + 1; i++) {
        if (primes[i]) 
            cout << i << " ";
    }

    
    return 0;
}
