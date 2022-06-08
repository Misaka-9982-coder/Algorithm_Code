#include <iostream>
using namespace std;

const int N = 50010;
int n, m;
int p[N], d[N];

int find(int x) {
    if (p[x] != x) {
        int t = find(p[x]);
        //路径压缩，将该点的父节点更新为祖宗节点，并将距离更新
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    int res = 0;
    while (m -- ) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);

        if (x > n || y > n) res ++ ;
        else {
            int px = find(x), py = find(y);
            //t = 1，x和y应该为同类
            if (t == 1) {
                //当x和y到根节点的距离之差不为0时为假话
                if (px == py && (d[x] - d[y]) % 3) res ++ ;
                else if (px != py) { //合并两个集合
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            } else { //t = 2，x和y之间应该为吃与被吃的关系
                //如果是吃与被吃的关系，那么两点到根节点的距离之差的绝对值应该为1
                if (px == py && (d[x] - d[y] - 1) % 3) res ++ ;
                else if (px != py) { //合并集合
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    printf("%d\n", res);

    return 0;
}