/*
    拉链法
*/

#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 3;
int h[N], e[N], ne[N], idx;

void insert(int x) {
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx ++ ;
}

bool find(int x) {
    int k = (x % N + N) % N;
    for(int i = h[k]; ~i; i = ne[i]) {
        if(e[i] == x) {
            return true;
        }
    }

    return false;
}

int main() {
    int n; cin >> n;
    memset(h, -1, sizeof h);

    while(n -- ) {
        char op[2]; int x;
        cin >> op >> x;

        if(*op == 'I') insert(x);
        else {
            if(find(x)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}


/*
 * 开放寻址法

#include<iostream>
#include<string>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;
int h[N];

int find(int x) {
    int t = (x % N + N) % N;
    while(h[t] != null && h[t] != x) {
        t ++ ;
        if(t == N) t = 0;
    }

    return t;
}

int main() {
    memset(h, 0x3f, sizeof h);

    int n; cin >> n;
    while(n -- ) {
        char op[2];
        int x; cin >> x;
        if(*op == 'I') h[find(x)] = x;
        else {
            if(h[find(x)] == null) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }

    return 0;
}

*/