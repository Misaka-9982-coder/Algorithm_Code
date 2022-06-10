#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 510;

int n, m;
int g[N][N];
int dist[N];//用于存储每个点到起点的最短距离
bool st[N];
//用于在更新最短距离时
//判断当前的点的最短距离是否确定 是否需要更新

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;//一号点到一号点的距离为0

    //迭代n次，每次可以确定一个点到起点的最短路
    for(int i = 0; i < n; i ++ ) {

         //t存储当前访问的点
        int t = - 1;

        //该步骤即寻找还未确定最短路的点中路径最短的点
        for(int j = 1; j <= n; j ++ ) {
            if(!st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }

        st[t] = true;

        //依次更新每个点所到相邻的点路径值
        for(int j = 1; j <= n; j ++ ) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }

    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main() {
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);

    while(m --) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    
    int t = dijkstra();
    cout << t << endl;

    return 0;
}