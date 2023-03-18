#include <iostream>
#include <string>
using namespace std;


string f(int year) {
    string ans = "NO";
    if (year % 400 == 0)
        ans = "YES";
    else if (year % 4 == 0 and year % 100 != 0)
        ans = "YES";

    return ans;
}


int main() {
    int year;
    cin >> year;

    cout << f(year);


    return 0;
}
