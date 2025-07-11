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
Input
4
1 3 2 0
Output
2

Each day there are:
ai equals 0, if on the i-th day of vacations the gym is closed and the contest is not carried out;
ai equals 1, if on the i-th day of vacations the gym is closed, but the contest is carried out;
ai equals 2, if on the i-th day of vacations the gym is open and the contest is not carried out;
ai equals 3, if on the i-th day of vacations the gym is open and the contest is carried out.

Can either write, do sport, or rest. Minimize reset days given the invariant
that he cannot do an activity two days in a row

Top down, memoization approach.
Store current number of rest days for each day.
Then recurse down from the final day, by selecting all possible options.
*/

// Previous, will be 0 for rest, 1 for write, and 2 for gym.

// dp[day][last_activity] = minimum rest days from day 'day' to end
// last_activity: 0 = rest, 1 = contest, 2 = gym
int dp[101][3];
vector<int> vacationOptions;
int days;

int memo_dp(int day, int lastActivity){
    if(day == days) {
        return 0;
    }

    // If already computed, return memoized result
    if (dp[day][lastActivity] != -1) {
        return dp[day][lastActivity];
    }

    int result = 1 + memo_dp(day + 1, 0);

    if ((vacationOptions[day] == 1 || vacationOptions[day] == 3) && lastActivity != 1) {
        result = min(result, memo_dp(day + 1, 1));
    }
    if((vacationOptions[day] == 2 || vacationOptions[day] == 3) && lastActivity != 2) { 
        result = min(result, memo_dp(day + 1, 2));
    }

    return dp[day][lastActivity] = result;
}

void solve() {
    cin >> days;

    vacationOptions.resize(days);

    for (int i = 0; i < days; i++) {
        cin >> vacationOptions[i];
    }

    // Initialize DP table
    memset(dp, -1, sizeof(dp));
    
    cout << memo_dp(0, 0) << endl;
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