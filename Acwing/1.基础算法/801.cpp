#include<iostream>
using namespace std;

int lowBit(int x) {
    return x & -x;
}

int main() {
    int n; cin >> n;
    while(n -- ) {
        int x; cin >> x;
        int res = 0;
        while(x) {
            x -= lowBit(x);
            res ++ ;
        }
        cout << res << " ";
    }
    return 0;
}