
/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
#define pii  pair<int, int>
#define pll pair<ll, ll>
// INT_MAX INT_MIN LLONG_MAX LLONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

const int MAXN = 1e5 + 1;

int dfs_cnt = 1;
int dfs_num[MAXN];
int dfs_low[MAXN];


vector<int> adj[MAXN];

vector<vector<pii>> BCC;
vector<pii> stk;

void CutVertex(int v,int p)
{
	dfs_num[v] = dfs_low[v] = dfs_cnt++;
	for (auto nv : adj[v])
	{
		if (nv == p) continue;
		if (dfs_num[v] > dfs_num[nv]) stk.push_back({ v,nv });

		if (dfs_num[nv])
		{
			dfs_low[v] = min(dfs_low[v], dfs_num[nv]);
		}
		else
		{
			CutVertex(nv, v);
			dfs_low[v] = min(dfs_low[v], dfs_low[nv]);
			if (dfs_low[nv] >= dfs_num[v])
			{
				BCC.emplace_back();
				while (true)
				{
					pii e = stk.back(); stk.pop_back();
					BCC.back().push_back(e);

					if (e == pii(v, nv)) break;
				}
			}
		}
	}
}
