#include <bits/stdc++.h>
using namespace std;
int N, M;
int vis[1005];
int truoc[1005];
vector<vector<int>> ke;
void bfs(int u)
{
	vis[u] = 1;
	queue<int> q;
	q.push(u);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (int i = 0; i < ke[t].size(); i++)
		{
			if (vis[ke[t][i]] == 0)
			{
				vis[ke[t][i]] = 1;
				truoc[ke[t][i]] = t;
				q.push(ke[t][i]);
			}
		}
	}
}
int main()
{
	int t, u, x, y, v;
	cin >> t;
	while (t--)
	{
		ke.clear();
		cin >> N >> M >> u >> v;
		ke.resize(N + 1);
		for (int i = 1; i <= N; i++)
			vis[i] = 0;
		for (int i = 1; i <= N; i++)
			truoc[i] = 0;
		truoc[u] = u;
		for (int i = 1; i <= M; i++)
		{
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		bfs(u);
		if (truoc[v] == 0)
			cout << -1 << endl;
		else
		{
			int tmp[1005], i = 0;
			tmp[i++] = v;
			while (truoc[v] != u)
			{
				tmp[i++] = truoc[v];
				v = truoc[v];
			}
			tmp[i++] = u;
			for (int j = i - 1; j >= 0; j--)
				cout << tmp[j] << " ";
			cout << endl;
		}
	}
	return 0;
}
