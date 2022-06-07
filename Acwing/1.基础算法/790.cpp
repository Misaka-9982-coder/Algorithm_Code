#include<iostream>
using namespace std;

int main() {
    double x; cin >> x;
    double l = -10000, r = 10000;
    while(r - l > 1e-8) {
        double mid = (l + r) / 2;
        if(mid * mid * mid) r = mid;
        else l = mid;
    }
    printf("%lf", l);
    return 0;
}