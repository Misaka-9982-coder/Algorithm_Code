#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 1e5 + 10;

queue<int> que;
int n, m;
int h[N], e[N], ne[N], idx;
int d[N], q[N];				//队列和距离数组

//用邻接表将图存储
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int bfs() {
	//层序遍历
	que.push(1);
	memset(d, -1, sizeof d);

	d[1] = 0;
	while(!que.empty()) {
		int t = que.front();
		que.pop();
		for(int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];

			//若未被遍历过，则距离加一
			if(d[j] == -1) {
				d[j] = d[t] + 1;
				que.push(j);
			}
		}
	}
	return d[n];
}

int main() {
	cin >> n >> m;
	memset(h, -1, sizeof h);
    
	for(int i = 0; i < m; i ++ ) {
		int a, b; cin >> a >> b;
		add(a, b);
	}

	cout << bfs() << endl;
	
	return 0;
}