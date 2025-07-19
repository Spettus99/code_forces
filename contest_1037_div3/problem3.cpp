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
n towers, from 1 to n. Tower i has height h_i. 
Start t = 0, start on index k and water level is 1.alignas
Every second water + 1. Can teleport between towers but takes
|h_i - h_j| seconds

reach maximum height.
It seems like a shortest path solution where we are trying to also optimize for not falling into
water. 

Put options into a priority queue based on height, if strictly less than current pop.
If can't be reached atm, then put on hold, otherwise make the switch. If at max height
then done
*/

void solve() {
    int n, k;
    cin>> n >> k;
    k--;
    cin.ignore();
    priority_queue<pair<int, int>> heights;
    unordered_map<int, vector<int>> heightMap;
    int currHeight = 0;
    int maxHeight = 0;
    for(int i = 0; i < n; i++){
        int h;
        cin>>h;
        if(i == k){
            currHeight = h;
        }
        heights.push({h, i});
        maxHeight = max(maxHeight, h);
        heightMap[h].push_back(i);
    }
    set<int> maxTower;
    for(auto t : heightMap[maxHeight]){
        maxTower.insert(t);
    }
    //Already there
    if(maxTower.find(k) != maxTower.end()) {
        cout<<"YES"<<endl;
        return;
    }
    pair<int, int> currTower;
    vector<pair<int,int>> putBack;
    int water = 1;
    int currentIdx = k;
    while(!heights.empty()) {
        //cout<<"currentIdx: "<<currentIdx<<" currentHeight "<<currHeight<<" currWater "<<water<<endl;
        currTower = heights.top();
        //cout<<"Tower H: "<<currTower.first<<" Tower idx: "<<currTower.second<<endl;
        heights.pop();
        if(currTower.first <= currHeight) {
            continue;
        }
        int transferTime = abs(currHeight - currTower.first);
        int ttP = (currHeight - water) + 1;
        if(transferTime <= ttP) {
            currentIdx = currTower.second;
            currHeight = currTower.first;
            water += transferTime;
            for(auto p : putBack){
                heights.push(p);
            }
            putBack.clear();
        } else {
            putBack.push_back(currTower);
        }
        if(maxTower.find(currentIdx) != maxTower.end()) {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
/*
1
5 3
3 2 1 4 5
*/
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