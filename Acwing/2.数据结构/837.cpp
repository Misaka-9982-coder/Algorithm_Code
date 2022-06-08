#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int p[N], Size[N];

int find(int x) {
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) {
        p[i] = i;
        Size[i] = 1;
    }

    while(m -- ) {
        char op[5];
        int a, b;
        cin >> op;

        if(op[0] == 'C') {
            cin >> a >> b;
            if(find(a) == find(b)) continue;

            Size[find(b)] += Size[find(a)];
            p[find(a)] = find(b);
        } else if (op[1] = '1') {
            cin >> a >> b;
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        } else {
            cin >> a;
            cout << Size[find(a)] << endl;
        }
    }

    return 0;
}