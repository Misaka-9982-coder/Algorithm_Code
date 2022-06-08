#include<iostream>
using namespace std;

const int N = 1e5 + 10;

int m;
int stk[N], tt;

int main() {
    cin >> m;
    while(m -- ) {
        string op; cin >> op;
        int x;

        if (op == "push") {
            cin >> x;
            stk[ ++ tt] = x;
        }
        else if (op == "pop") tt -- ;
        else if (op == "empty") cout << (tt ? "NO" : "YES") << endl;
        else cout << stk[tt] << endl;
    }

    return 0;
}