#include <cmath>
#include <iostream>
using namespace std;


int main () {
    double angle;
    cin >> angle;

    int hours = (int)angle / 30;  // 1 час = 360/12 = 30 градусов
    angle -= (hours * 30);

    double seconds = angle * 120.;  // 1 секунда = 30/3600 градуса = 1/120 градуса

    int minutes = seconds / 60;  // 1 час = 60 минут => 1 минута = 30/60 = 0.5 градуса

    // число секунд может быть не целым, а значит, чтобы получить полные секунды,
    // нужно округлить их число в меньшую сторону
    int scnds = int(floor(seconds)) % 60;
    // if (seconds - int(seconds) > 0.99) 
    //     scnds = floor(seconds + 0.0001) - minutes * 60;
    // else
    //     scnds = floor(seconds) - minutes * 60;

    cout << hours << " " << minutes << " " << scnds;
    
    return 0;
}
