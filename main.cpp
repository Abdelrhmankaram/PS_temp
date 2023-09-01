#include<bits/stdc++.h>

#ifdef _MSC_VER
#define __builtin_popcount __popcnt
#define __builtin_clz __lzcnt
#endif

#define ll long long
#define all(x) x.begin(), x.end()
#define cin(vector) for(auto& i : vector) cin >> i
#define copy(x) copy(x.begin(), x.end(), ostream_iterator<ll>(cout," "))
#define ll long long
#

#define OO 0x3f3f3f3f3f3f3f3f
using namespace std;
int const mod = 1000000007;
//const double pi=3.14159265358979323846; //string pi="314159265358979323846";

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool com(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second)return a.first * a.second > b.first * b.second;
    return a.second > b.second;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> arr(m);
    for (int i = 0; i < m; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(all(arr), com);
    ll ans = 0;
    for (int i = 0; (i < m) && n; ++i) {
        if (n >= arr[i].first) {
            ans += arr[i].first * arr[i].second;
            n -= arr[i].first;
        } else {
            ans += n * arr[i].second;
            n = 0;
        }
    }
    cout <<ans;
}

/*
000101
010111
 */

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}