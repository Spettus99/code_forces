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
Given two arrays with the same size, find the number of pairs (i, j)
s.t ai + aj > bi + bj

Want to maximize the a[i] / b[i] ratio.
Compute this for all the points and sort by the ratio.

Then for each point, BS all the points to the right that would fulfill this policy.
Find the first point such that  1 - ratio > 0.
*/

void solve() {
    int n;
    cin >> n;
    vector<ll> diff(n);
    for (int i = 0; i < n; i++) {
        cin>>diff[i];
    }
    ll sub;
    for (int i = 0; i < n; i++) {
        cin>>sub;
        diff[i] -= sub;
    }

    // -2 -1 3 4
    sort(diff.begin(), diff.end());
    ll result = 0;
    for(int i = 0; i < n - 1; i++){
        if(diff[i] <= 0){
            auto idx = upper_bound(diff.begin() + i + 1, diff.end(), (diff[i] * -1));
            result += diff.end() - idx;
        } else {
            result += (n - (i + 1));
        }
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