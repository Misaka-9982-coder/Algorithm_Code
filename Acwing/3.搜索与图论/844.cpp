#include<iostream>
#include<algorithm>
using namespace std;

#define x first
#define y second

const int N = 110;
typedef pair<int, int> PII;
int n, m, g[N][N], d[N][N];
PII q[N * N];

int bfs() {
    int hh = 0, tt = 0;
    q[0] = {0, 0};
    memset(d, -1, sizeof d);
    d[0][0] = 0;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    while(hh <= tt) {
        auto t = q[hh ++ ];
        for(int i = 0; i < 4; i ++ ) {
            int a = t.x + dx[i], b = t.y + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= m) continue;
            if(g[a][b] == 0 && d[a][b] == -1) {
                d[a][b] = d[t.x][t.y] + 1;
                q[ ++ tt] = {a, b};
            }
        }
    }

    return d[n - 1][m - 1];
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i ++ ) {
        for(int j = 0; j < m; j ++ ) {
            cin >> g[i][j];
        }
    }

    cout << bfs() << endl;
    return 0;
}