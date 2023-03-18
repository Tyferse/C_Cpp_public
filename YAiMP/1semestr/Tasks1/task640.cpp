#include <iostream>
using namespace std;


int main() {
    int d1, m1;
    int d2, m2, y;
    cin >> d1 >> m1;
    cin >> d2 >> m2 >> y;

    int a = (14 - m1)/12;
    int y1 = y + 4800 - a;
    if (d1 == 29 and m1 == 2 and 
        ((m1 < m2 or (m1 == m2 and d1 < d2)) 
        or not ((y%4 == 0 and y%100 != 0) or y%400 == 0))) {
            
        int i = ((y%4 == 0 and y%100 != 0) or y%400 == 0) ? 1 : 0;
        while (not (((y + i)%4 == 0 and (y + i)%100 != 0) or (y + i)%400 == 0)) {
            i++;
        }
        y1 += i;
    }
    else 
        y1 += m1 < m2 or (m1 == m2 and d1 < d2) ? 1 : 0;

    m1 = m1 + 12*a - 3;
    int days1 = d1 + (153*m1+2)/5 + 365*y1 + y1/4 - y1/100 + y1/400;


    a = (14 - m2)/12;
    y1 = y + 4800 - a;
    m2 = m2 + 12*a - 3;
    int days2 = d2 + (153*m2+2)/5 + 365*y1 + y1/4 - y1/100 + y1/400;

    cout << days1 - days2; 


    return 0;
}
