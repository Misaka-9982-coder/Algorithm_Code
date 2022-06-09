#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int n, ans = N;
int h[N], e[M], ne[M], idx;
bool st[N];	//记录节点是否被遍历过

//使用单链表的形式将树存储进来
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs(int u) {
	st[u] = true;
	int size = 0, sum = 0;

	//遍历节点u的子节点
	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(st[j]) continue;

		int s = dfs(j);

		//size 记录所有子节点所在块的最大值
		size = max(size, s);

		//sum 将子节点所在块的值加起来
		sum += s;
	}

	//更新size，ans
	size = max(size, n - sum - 1);
	ans = min(ans, size);

	//sum初始化为0
	//而当前这个点(根节点)也是上一层调用dfs的根节点子节点所在连通块内的一点
	return sum + 1;
}

int main() {
    cin >> n;
	memset(h, -1, sizeof h);

	for(int i = 0; i < n - 1; i ++ ) {
		int a, b; cin >> a >> b;
		add(a, b), add(b, a);
	}

	dfs(1);
    cout << ans << endl;

	return 0;
}