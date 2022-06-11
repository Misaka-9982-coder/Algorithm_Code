#include<iostream>
using namespace std;

bool is_prime(int x) {
    if(x < 2) return false;
    for(int i = 2; i <= x / i; i ++ ) {
        if(x % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n; cin >> n;
    while(n -- ) {
        int m; cin >> m;
        if(is_prime(m)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}