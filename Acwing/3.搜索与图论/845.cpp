#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

int bfs(string start) {
	//目标状态
	string end = "12345678x";
	//利用哈希表将转换后的字符串和操作次数绑定在一起
	queue<string> q;
	//利用哈希表将转换后的字符串和操作次数绑定在一起
	unordered_map<string, int> d;

	q.push(start);
	d[start] = 0;

	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};

	while(q.size()) {
		auto t = q.front();
		q.pop();

		int distance = d[t];
		if(t == end) return distance;

		//查找x的下标并转换为二维坐标
		int k = t.find('x');
		int x = k / 3, y = k % 3;

		for(int i = 0; i < 4; i ++ ) {
			//转移后的x坐标
			int a = x + dx[i], b = y + dy[i];
			//x坐标未越界
			if(a >= 0 && a < 3 && b >= 0 && b < 3) {
				//形态变换
				swap(t[k], t[a * 3 + b]);
				//如果状态t没有被遍历过
				if(!d.count(t)) {
					d[t] = distance + 1;
					q.push(t);
				}
				//恢复原位
				swap(t[a * 3 + b], t[k]);
			}
		}
	}
	return -1;
}

int main() {
	string start;
	for(int i = 0; i < 9; i ++ ) {
		char c;
		cin >> c;
		start += c;
	}

	cout << bfs(start) << endl;

	return 0;
}