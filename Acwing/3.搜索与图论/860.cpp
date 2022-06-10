#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

//返回是否可以成功将u染色为c
bool dfs(int u, int c) {
    //修改当前颜色
    color[u] = c;

    //尝试染链接边的颜色
    for(int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];

        //如果color[j]没有染过色
        if(!color[j])
            if(!dfs(j, 3 - c)) return false;    //如果不能将j成功染色
        else if(color[j] == c) return false;    //如果染过颜色且和u相同
    }

    return true;
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);

    while(m -- ) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    bool flag = true;
    for(int i = 1; i <= n; i ++ )
        //如果未染色
        if(!color[i]) {
            //如果dfs返回false 说明出现矛盾
            if(!dfs(i, 1)) {
                flag = false;
                break;
            }
        }

    if(flag) puts("Yes");
    else puts("No");

    return 0;
}