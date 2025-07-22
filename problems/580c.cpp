/*
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
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

#define ar array
#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

/*
Traverse from root to edge, while avoiding n consecutive cats. Path is a Tree.
Find the number of edges we can reach.

Do a graph DFS, tracking where you come from so you don't go back. Pass down
the current number of consecutive cats, if maxed out give up. Bubble up if reaches an edge.
*/

using graph = vector<vector<int>>;
int n, m;
vector<int> cats;
int dfs(int curr, int prev, int cats_seen_consecutively, const graph& g) {
    if(cats_seen_consecutively > m){
        return 0;
    }
    // Is edge
    if(g[curr].size()==1 && g[curr][0] == prev) {
        return 1;
    }
    int result = 0;
    for(auto x : g[curr]){
        if(x != prev) {
            if(cats[x]) {
                result += dfs(x, curr, cats_seen_consecutively + 1, g);
            } else {
                result += dfs(x, curr, 0, g);
            }
        }
    }
    return result;
}

void solve() {
    cin>>n;
    cin>>m;
    int isCat;
    for(int i = 0; i < n; i++){
        cin>>isCat;
        cats.push_back(isCat);
    }
    graph g(n);
    int v1, v2;
    for(int i = 0; i < n -1; i++){
        cin>>v1;
        cin>>v2;
        g[v1 - 1].push_back(v2 - 1);
        g[v2 - 1].push_back(v1 - 1);
    }
    int result = dfs(0, 0, cats[0], g);
    cout<<result<<endl;
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