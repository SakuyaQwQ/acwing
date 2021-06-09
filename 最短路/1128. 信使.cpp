
/*
单源最短路模板题
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> edges;
vector<int> vis;

struct cmp {
    auto operator()(const pair<int, int>& e1, const pair<int, int>& e2)const {
        return e1.second > e2.second;
    }
};

int main() {
    cin >> n >> m;
    edges.resize(n + 1);
    vis.resize(n + 1, 0x3f3f3f3f);
    for (int i = 0; i < m; ++i) {
        int x, y, k;
        cin >> x >> y >> k;
        edges[x].emplace_back(y, k);
        edges[y].emplace_back(x, k);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    q.emplace(1, 0);
    while (!q.empty()) {
        auto [now, cost] = q.top();
        q.pop();
        if (vis[now] == 0x3f3f3f3f) {
            vis[now] = cost;
            for (auto& [to, val] : edges[now]) {
                if (vis[to] == 0x3f3f3f3f) {
                    q.emplace(to, val + cost);
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res = max(res, vis[i]);
        if (vis[i] == 0x3f3f3f3f) {
            res = -1;
            break;
        }
    }
    cout << res << endl;
}
