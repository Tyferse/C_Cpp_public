#include <iostream>
using namespace std;


int main() {
    // int i, n;
    // cin >> n;
    // i = 1;
    // while (i <= n) {
    //     cout << i << " ";
    //     i = i + 1;
    // } 


    // int min, now;
    // cin >> now;
    // min = now;
    // while (now != 0) {
    //     if (now < min) 
    //         min = now;
        
    //     cin >> now;
    // }

    // cout << min; 


    // int sum = 0, now;
    // cin >> now;
    // while (now != 0) {
    //     sum = sum + now;
    //     cin >> now;
    // }

    // cout << sum;


    // int part1, part2;
    // cin >> part1 >> part2;
    // int sum1 = 0, sum2 = 0;
    // while (part1 != 0) {
    //     sum1 = sum1 + part1 % 10;
    //     part1 = part1 / 10;
    // }

    // while (part2 != 0) {
    //     sum2 = sum2 + part2 % 10;
    //     part2 = part2 / 10;
    // }

    // if (sum1 == sum2) {
    //     cout << "Lucky ticket";
    // } 

    // else {
    //     cout << "unlucky :(";
    // }


    // int i;
    // i = 1;
    // while (i <= 100) {
    //     cout << i << " ";
    // } 


    // int n, i;
    // i = 1;
    // while (1) {
    //     cout << i;
    //     i = i + 1;
    //     if (i > 100)
    //         break;
    // }

    int now;
    now = -1;
    while (now != 0) {
        cin >> now;
        if (now <= 0)
            continue;

        cout << now << " ";
    } 

    
    return 0;
}
