#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> PII;
const int N = 3e5 + 10;
int n, m;
int a[N], s[N];
vector<int> all;
vector<PII> add, query;

int find(int x) {
    int l = 0, r = all.size() - 1;
    while(l < r) {
        int mid = l + r >> 1;
        if(all[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i ++ ) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        all.push_back(x);
    }

    for(int i = 0; i < m; i ++ ) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});

        all.push_back(l);
        all.push_back(r);
    }

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    for(auto item : add) {
        int x = find(item.first);
        a[x] += item.second;
    }

    for(int i = 1; i <= all.size(); i ++ ) s[i] = s[i - 1] + a[i];

    for(auto item : query) {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}