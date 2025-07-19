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
#include <memory>
#include <stack>
#include <deque>
#include <cstring>
#include <utility>
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
Input
3
andrew 3
andrew 2
mike 5

Output
andrew

Return who scores the most points, it is scored in chronological order of rounds.
If tied, return who gets there first. 

Just do multiple passes. First pass establish everyones score, then determine
if anyone tied for first. If so, replay the game to determine who arrives there first.
*/

void solve() {
    int rounds;
    cin >>rounds;

    unordered_map<string, int> people;
    string p;
    int score;
    vector<pair<int,string>> game;
    for(int i = 0; i < rounds; i++){
        cin>>p;
        cin>>score;
        game.push_back({score, p});
        people[p] += score;
    }
    int currMax = 0;
    for(auto [key, value] : people) {
        currMax = max(currMax, value);
    }
    unordered_set<string> winners;
    for(auto [key, value] : people) {
        if(value == currMax){
            winners.insert(key);
        }
    }
    if(winners.size()==1){
        cout<<*winners.begin()<<endl;
        return;
    }

    unordered_map<string, int> replay;
    // Replay the game to determine who gets there first.
    for(int i = 0; i < rounds; i++){
        string p1 = game[i].second;
        if(winners.find(p1) == winners.end()){
            continue;
        }
        int s1 = game[i].first;
        replay[p1] += s1;
        if(replay[p1] >= currMax) {
            cout<<p1<<endl;
            return;
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