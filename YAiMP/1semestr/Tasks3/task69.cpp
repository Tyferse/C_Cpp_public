#include <iostream>
using namespace std;


int main (){
    int n, tmp;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    for (int i = 0; i < n / 2; i++) {
        tmp = array[i];
        array[i] = array[n - 1 - i];
        array[n - 1 - i] = tmp;
    }

    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    
    return 0;
}
