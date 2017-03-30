/*
Author: Ayman Salah

Category: Geometry
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <hash_map>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
using namespace std;

#define PI 3.14159265359
#define all(v) v.begin(),v.end()
#define sortva(v) sort(all(v))
#define sortvd(v) sort(v.rbegin(),v.rend())
#define sortaa(a,n) sort(a,a+n)
#define sortad(a,n) sort(a,a+n),reverse(a,a+n)
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1,v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1,v2,v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1,v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define sfstr(v) scanf("%s", v);
#define sz(v) v.size()
#define ndl puts("")
#define SS stringstream
typedef long long ll;
typedef unsigned long long ull;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct point {
	int x, y;
};

struct router {
	int x, y, r;
};


int dist_sqr(point p, router r) {
	return (p.x - r.x)*(p.x - r.x) + (p.y - r.y)*(p.y - r.y);
}

int main() {
	PLAY();

	int t;
	cin >> t;
	int test = 1;
	while (t--) {
		cout << "Case " << test++ << ":\n";
		int n, m;
		cin >> n >> m;
		vector<router> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].x >> v[i].y >> v[i].r;
		for (int i = 0; i < m; i++) {
			point p;
			cin >> p.x >> p.y;
			bool ok = false;
			for (int j = 0; j < n && !ok; j++) {
				int d = dist_sqr(p, v[j]);
				if (v[j].r * v[j].r >= d) ok = true;
			}
			cout << (ok ? "Yes" : "No") << endl;
		}
	}
	
	return 0;
}