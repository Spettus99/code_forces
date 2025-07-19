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
n casinos numbered 1 to n. Have k coins
Obtain maximum number of coins. Can do casino as long as l < x < r and after visiting
you obtain real_i coins

Graph problem, only make jumps where you incrase coins. Put all casinos onto a 
priority queue, if real coins are higher then but not in bounds pop off and hold.
If in bounds pop off and update bounds. If real coins are lower just remove.
*/

void solve() {
    int n, coins;
    cin>> n >> coins;
    vector<vector<int>> casino(n);
    cin.ignore();
    priority_queue<pair<int, int>> rankings;
    for(int i = 0; i < n; i++){
        casino[i] = vector<int>(3);
        for(int j = 0; j < 3; j++){
            cin>>casino[i][j];
        }
        rankings.push({casino[i][2], i});
        cin.ignore();
    }
    int result = coins;
    pair<int, int> curr;
    vector<pair<int, int>> putback;
    while(!rankings.empty()){
        curr = rankings.top();
        rankings.pop();
        if(curr.first < coins) {
            continue;
        }
        if(coins >= casino[curr.second][0] && coins <= casino[curr.second][1]) {
            coins = max(coins, casino[curr.second][2]);
            for(auto p : putback){
                rankings.push(p);
            }
            putback.clear();
        }else {
            putback.push_back(curr);
        }
    }
    cout<<coins<<endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}