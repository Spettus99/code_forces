/*
Input
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
Output
1 4 3 5 

find shortest path from vertex 
1 to n
if none print -1

Standard priority queue bfs

Using template found at: https://ncduy0303.github.io/Competitive-Programming/Contest%20Template/main.cpp
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <climits>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

using graph = vector<vector<pair<int,int>>>;
bool processed[MAX_N];

void solve() {
    int nodes;
    cin >> nodes;
    int edges;
    cin >> edges;

    int a, b, w;
    graph g(nodes + 1);
    for (int i = 0; i < edges; i++) {
        cin >> a;
        cin >> b;
        cin >> w;
        g[a].push_back({b, w});
        g[b].push_back({a , w});
    }

    vector<int> visited;
    for (int i = 0; i < nodes + 1; i++) {
        visited.push_back(INT_MAX);
    }
    visited[1] = 0;

    // {curr_dist, curr_node, {curr_path}}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    pair<int, int> curr;
    vector<int> parent(nodes + 1, -1);
    while (!q.empty()) {
        curr = q.top();
        q.pop();
        if (curr.second == nodes) {
            break;
        }
        if (processed[curr.second]) {
            continue;
        }
        processed[curr.second] = true;
        // Don't visit if path is longer than seen
        if (visited[curr.second] < curr.first) {
            continue;
        }
        visited[curr.second] = curr.first;
        for (auto &neigh : g[curr.second]) {
            if (!processed[neigh.first] && curr.first + neigh.second < visited[neigh.first]) {
                visited[neigh.first] = curr.first + neigh.second;
                parent[neigh.first] = curr.second;
                q.push({curr.first + neigh.second, neigh.first});
            }
        }
    }

    if (curr.second != nodes) {
        cout<<-1<<endl;
        return;
    }

    vector<int> result;
    int cursor = nodes;
    while (cursor != -1) {
        result.push_back(cursor);
        cursor = parent[cursor];
    }
    reverse(result.begin(), result.end());

    for(int i = 0; i < result.size(); i++){
        cout<<result[i];
        if (i != result.size() - 1){
            cout<<" ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}