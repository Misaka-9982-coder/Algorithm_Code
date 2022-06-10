#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> PII;
const int N = 1e6 + 10;

int n, m;
int h[N], e[N], w[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while(heap.size()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;
        //如果该点已经标记过，就跳过这一轮循环
        if(st[ver]) continue;

        st[ver] = true;

        for(int i = h[ver]; ~i; i = ne[i]) {
            int j = e[i];
            if(dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                //将更新过的点插入到堆中
                heap.push({dist[j], j});
            }
        }
    }

    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);

    while(m -- ) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    int t = dijkstra();
    cout << t << endl;

    return 0;
}