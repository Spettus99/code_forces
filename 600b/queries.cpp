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
Two arrays, and a and b. For each element in bi, find the number of elements in array a
that are less than or equal to value bi
Input
5 4
1 3 5 7 9
6 4 2 8
Output
3 2 1 4

Pretty simple algorithm, just sort array a, then iterate over array b, performing binary search 
bisect right

1 2 2 4
*/

void solve() {
    int a_length;
    cin >> a_length;
    int b_length;
    cin >> b_length;
    vector<int> a(a_length);
    for(int i = 0; i < a_length; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> result(b_length);
    int curr;
    for (int i = 0; i < b_length; i++) {
        cin>>curr;
        result[i] = upper_bound(a.begin(), a.end(), curr) - a.begin();
    }


    for(auto m : result){
        cout<<m<<" ";
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