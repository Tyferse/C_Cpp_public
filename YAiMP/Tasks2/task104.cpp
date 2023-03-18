#include <iostream>
using namespace std;


char f(char c) {
    //65 = A, 97 = a
    if ((65 <= int(c) and int(c) <= 90) or (97 <= int(c) and int(c) <= 122)) 
        return int(c) ^ 32;
    else 
        return c;
}


int main (){
    char c;
    cin >> c;
    cout << f(c);
    
    return 0;
}
