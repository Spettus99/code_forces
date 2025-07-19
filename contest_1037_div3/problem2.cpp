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
a to n numbers and a num k.
a_i describes weather on ith day, if rains then 1 o.t 0
Hike to peak takes k ddays, and weather must be 0. Once at top, take atleast one day rest.
Greedy solution sliding window
*/

void solve() {
    int n, k;
    cin>> n >> k;
    cin.ignore();
    vector<int> weather(n);
    for(int i = 0; i < n; i++){
        cin>>weather[i];
    }
    int result = 0;
    bool hike;
    for(int i = 0; i <= n - k;) {
        hike = true;
        for(int j = 0; j < k; j++) {
            if(weather[i + j]) {
                hike = false;
                break;
            }
        }
        if(hike) {
            result++;
            i += k + 1;
        } else {
            i++;
        }
    }
    cout<<result<<endl;
}
/*
1
5 1
0 1 0 0 0
*/
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t << ": ";
        solve();
    }
}