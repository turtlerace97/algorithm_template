

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

#define UNVISITED 0
#define EXPLORED 1

const int VERTEX = 1e4 + 1;
vector<int> adj[VERTEX];

int dfs_num[VERTEX];
int dfs_low[VERTEX];
int dfs_par[VERTEX];
bool articulation_vertex[VERTEX];

int cnt; // dfs 방문 순서 

int dfsRoot;
int rootChildren;

// 절단점 : dfs_low[u] >= dfs_num[v] ( v : cur, u : nxt )
// 절단선 : dfs_low[u] > dfs_num[v] ( v : cur, u : nxt )


void CutVertex(int v)
{
	dfs_low[v] = dfs_num[v] = cnt++;
	for (auto nv : adj[v])
	{
		if (dfs_num[nv] == UNVISITED)
		{
			dfs_par[nv] = v;
			if (v == dfsRoot) rootChildren++;

			CutVertex(nv);
			if (dfs_low[nv] >= dfs_num[v]) articulation_vertex[v] = true;
			dfs_low[v] = min(dfs_low[v], dfs_low[nv]);
		}
		else if (nv != dfs_par[v])
		{
			dfs_low[v] = min(dfs_low[v], dfs_num[nv]);
		}
	}

}


