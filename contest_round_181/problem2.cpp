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
Robot on cartesion plane. Given some k,
can move robot (0 - k) inclusive both down or left.
Costs 1 if pair has been used, o.t 0.

Could also be a greedy solution, find some k s.t
we maximize the distance traveled from us to origin, using some
multiple.

K can be very large though. Perhaps this is better as the jump problem.

Get the ratio from (a / k == 0 and b / k == 0)
Then maximize these values and take those steps

*/

ll gcd(ll a, ll b) {
    while (b) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
/*
3
3 5 15
5 10 5
25 25 2
*/
void solve() {
    ll a, b, k;
    cin>>a;
    cin>>b;
    cin>>k;

    ll temp = gcd(a, b);
    // Will be an int
    if(a / temp <= k && b / temp <= k){
        // Can move following just one dir vector
        cout<<1<<endl;
    } else{
        cout<<2<<endl;
    }
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