#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], ne[N], e[N], idx;
int q[N], d[N];//q表队列，d表入度

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool topSort() {
	int hh = 0, tt = -1;
	for(int i = 1; i <= n; i ++ )
		//入度为0，入队
		if(!d[i]) {
			q[ ++ tt] = i;
        }
	
	//若队列不为空
	while(hh <= tt) {
		//弹出队首元素
		int t = q[hh ++ ];
        
		for(int i = h[t]; i != -1; i = ne[i]) {	
			//与h[t]元素相关联的元素入度均减一
			int j = e[i];
			d[j] --;
			if(d[j] == 0) q[ ++ tt] = j;
		}
	}

	return tt == n - 1;
}

int main() {
	cin >> n >> m;

	memset(h, -1, sizeof h);

	for(int i = 0; i < m; i ++ ) {
		int a, b;
		cin >> a >> b;
		add(a, b);
		d[b] ++ ;
	}

	if(topSort()) {
		for(int i = 0; i < n; i ++ ) printf("%d ", q[i]);
		puts("");
	}
	else cout << -1 << endl;

	return 0;
}