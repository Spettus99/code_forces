/*
Input
4 5
3 1 2 1
Output
3

Input: n the number of books, and m the number of minutes. Followed by ith minutes it would take
to read the book. Determine the most amount of books one can read if read sequentially starting
at some book n. 

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

/*
Two pointer problem, move the pointer right while book totals
don't subsume mins. Once they due, decrement total while moving left pointer to the right
*/

void solve() {
    int books;
    cin >> books;
    int mins;
    cin >> mins;

    vector<int> bookMins;
    int input;
    for (int i = 0; i < books; i++) {
        cin >> input;
        bookMins.push_back(input);
    }
    int l = 0, r = 0;
    int currMins = 0;
    int result = -1;
    while (r != books) {
        currMins += bookMins[r];
        while(currMins > mins) {
            currMins -= bookMins[l];
            l++;
        }
        result = max(result, r - l + 1);
        r++;
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