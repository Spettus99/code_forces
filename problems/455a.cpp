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

/*
Given a sequence of n ints. Maximize points such that, deletion of ai is worth ai but also 
deletes a(i - 1) and a(i + 1)

Sort the array. Once sorted, if a number is isolated (IE no i - 1 or i + 1) then always take it.
Next for the remember of numbers that are connected. Need to decide whether to take i, or i + 1.

So if not isolated, solve the local DP problem.
Becomes the robber problem, do we take i or i + 1 where the value of the house is freq * ai.

Use unordered map to track frequencies.
n (1 ≤ n ≤ 105)
*/

set<int> choices;
unordered_map<int, int> freq;

void debug(const vector<vector<int>> &g) {
    for (auto x : g) {
        for(auto y: x) {
            cout<<y<<" ";
        }
        cout<<endl;
    }
}

long long solveSubProblem(const vector<long long>& chain) {
    if(chain.size() == 1) {
        return chain[0];
    }
    if(chain.size() == 2) {
        return max(chain[0], chain[1]);
    }
    vector<long long> dp(chain.size());
    dp[0] = chain[0];
    dp[1] = max(dp[0], chain[1]);
    for(int i = 2; i < chain.size(); i++) {
        dp[i] = max(dp[i-1], dp[i-2] + chain[i]);
    }
    return dp.back();
}

void solve() {
    int n;
    cin >> n;
    int num;
    for(int i = 0; i < n; i++){
        cin>>num;
        choices.insert(num);
        freq[num]++;
    }

    vector<vector<long long>> subproblems;
    vector<long long> chain;
    long long prevNum = *choices.begin();
    chain.push_back(prevNum * freq[prevNum]);
    auto it = choices.begin();
    it++;
    for(; it != choices.end(); ++it){
        long long currNum = *it;
        if(currNum - 1 == prevNum) {
            chain.push_back(currNum * freq[currNum]);
        } else {
            subproblems.push_back(chain);
            chain.clear();
            chain.push_back(currNum * freq[currNum]);
        }
        prevNum = currNum;
    }
    subproblems.push_back(chain);
    
    long long result = 0;
    for (auto p : subproblems) {
        result += solveSubProblem(p);
    }
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