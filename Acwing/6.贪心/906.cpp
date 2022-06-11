#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 1e5 + 10;
int n;

struct Range {
    int l, r;
    bool operator< (const Range &W) const {
        return l < W.l;
    }
} ranges[N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i ++ ) {
        int l, r;
        cin >> l >> r;
        ranges[i] = {l, r};
    }

    sort(ranges, ranges + n);
    priority_queue<int, vector<int>, greater<int> > heap;
    for(int i = 0; i < n; i ++ ) {
        auto range = ranges[i];
        if(heap.empty() || heap.top() >= range.l) heap.push(range.r);
        else {
            heap.pop();
            heap.push(range.r);
        }
    }

    cout << heap.size() << endl;
    return 0;
}