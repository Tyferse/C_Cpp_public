#include <iostream>
using namespace std;


bool has_intersection(int p[2], int x1, int y1, int x2, int y2) {
    return (y2 < p[1] && y1 >= p[1] || y1 < p[1] && y2 >= p[1]) && 
           (x2 + (p[1] - y2) / (y1 - y2) * (x1 - x2) < p[0]);
}


int main() {
    int n, point[2];
    cin >> n >> point[0] >> point[1];

    int p[n][2];
    for (int i = 0; i < n; i++) {
        cin >> p[i][0] >> p[i][1];
    }

    bool in_polygon = false;
    int j = n - 1;
    for (int i = 0; i < n; i++) {
        if (has_intersection(point, p[j][0], p[j][1], p[i][0], p[i][1]))
            in_polygon = !in_polygon;
            // Если число пересечений граней многоугольника нечётное
            // (y-координата точки находится между ординат точек грани, 
            //  и точка находится слева от грани),
            // то true, иначе точка лежит вне многоугольника.

        j = i;
    }
    
    if (in_polygon) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}
