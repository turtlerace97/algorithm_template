
# DFS 스패닝 트리를 이용해 간선 검사

다음과 같은 그래프에서 하나의 정점을 잡고 DFS 를 수행하게 되면 DFS 스패닝 트리가 생깁니다. 

<img width="80%" src="https://user-images.githubusercontent.com/76829382/211544151-8b30f6ad-094c-4f6b-845e-8b0daed5211f.jpg"/>

dfs 스패닝 트리를 구성하기 전에, 정점의 상태를 다음과 같이 3가지로 정의해보면,

- 정점의 상태
    - UNVISITED
    - VISITED
    - EXPLORED

dfs 스패닝 트리에서 간선의 상태는 다음과 같이 정의할 수 있습니다. 

- 간선의 상태
    - 트리간선
        - EXPLORED → UNVISITED
        - dfs 탐색 순서
    - 역방향간선
        - EXPLORED → EXPLORED
        - cycle의 일부
    - 순뱡향간선
        - EXPLORED → VISITED

![KakaoTalk_20230110_194448615_01.jpg](DFS%20%E1%84%89%E1%85%B3%E1%84%91%E1%85%A2%E1%84%82%E1%85%B5%E1%86%BC%20%E1%84%90%E1%85%B3%E1%84%85%E1%85%B5%E1%84%85%E1%85%B3%E1%86%AF%20%E1%84%8B%E1%85%B5%E1%84%8B%E1%85%AD%E1%86%BC%E1%84%92%E1%85%A2%20%E1%84%80%E1%85%A1%E1%86%AB%E1%84%89%E1%85%A5%E1%86%AB%20%E1%84%80%E1%85%A5%E1%86%B7%E1%84%89%E1%85%A1%203d187d5e614b48e591d51c130d522c2d/KakaoTalk_20230110_194448615_01.jpg)

위 그림에서 노란색 간선은 트리간선, 주황색은 역방향 간선, 초록색은 순방향 간선입니다. 

이렇게 간선의 상태를 정의 하게 되면 BCC, SCC의 문제를 풀 수 있습니다. 

간선의 상태를 체크하는 코드 

```cpp
#define UNVISITED 0
#define VISITED 1
#define EXPLORED 2 

const int VSIZE = 1e5 + 1;

vector<int> adj[VSIZE];

int dfs_num[VSIZE];
int dfs_par[VSIZE];

void graphCheck(int v)
{
	dfs_num[v] = EXPLORED;
	for (auto nv : adj[v])
	{
		if (dfs_num[nv] == UNVISITED)
		{
			dfs_par[nv] = v;
			graphCheck(nv);
		}
		else if (dfs_num[nv] == EXPLORED)
		{
			if (nv == dfs_par[v]) continue;
			cout << "Back Edge : " << v << "->" << nv << "\n";
		}
		else if (dfs_num[nv] == VISITED)
		{
			cout << "Forward Edge : " << v << "->" << nv << "\n";
		}
	}
}
```
