#include <iostream>
using namespace std;


int main() {
    int a1 = 0, a2 = 0, i = 0, sum = 0;
    char c, k;

    c = getchar();
    i = int(c) - 48;

    while(c >= 48 && c <= 57){
    
        a1 *= 10;
        a1 += i;

        c = cin.get();
        i = int(c) - 48;
    
    }

    sum += a1;
    a1 = 0;

    while(c != '\n'){

        k = c;
    
        c = getchar();
        i = int(c) - 48;
    
        while(c >= 48 && c <= 57){
      
            a1 *= 10;
            a1 += i;

            c = getchar();
            i = int(c) - 48;
        }   

        if(k == '+') {
      
            sum += a1;
            a1 = 0;

        } 
        if(k == '-'){
            sum -= a1;
            a1 = 0;
        }
    }

    cout << sum;

    return 0;
}
