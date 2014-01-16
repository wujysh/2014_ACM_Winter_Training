#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 1000000000;
const int MAXN = 20000, MAXM = 500000;

struct Edge {
	int v, f, next;
} e[MAXM * 2 + 10];
int n, src, sink, cnt;
int head[MAXN + 10];

void addEdge(int u, int v, int c) {
	e[++cnt].v = v;
	e[cnt].f = c;
	e[cnt].next = head[u];
	head[u] = cnt;
	e[++cnt].v = u;
	e[cnt].f = 0;
	e[cnt].next = head[v];
	head[v] = cnt;
}

void init() {
	memset(head, 0, sizeof(head));
	cnt = 1;
	// addEdge

}

queue <int> q;
bool vis[MAXN + 10];
int dist[MAXN + 10];

void bfs() {
	memset(dist, 0, sizeof(dist));
	while (!q.empty()) q.pop();
	vis[src] = true;
	q.push(src);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].next) {
			if (e[i].f && !vis[e[i].v]) {
				q.push(e[i].v);
				dist[e[i].v] = dist[u] + 1;
				vis[e[i].v] = true;
			}
		}
	}
}

int dfs(int u, int delta) {
	if (u == sink) {
		return delta;
	} else {
		int ret = 0;
		for (int i = head[u]; delta && i; i = e[i].next) {
			if (e[i].f && dist[e[i].v] == dist[u] + 1) {
				int dd = dfs(e[i].v, min(e[i].f, delta));
				e[i].f -= dd;
				e[i ^ 1].f += dd;
				delta -= dd;
				ret += dd;
			}
		}
		return ret;
	}
}

int maxflow() {
	int ret = 0;
	while (true) {
		memset(vis, 0, sizeof(vis));
		bfs();
		if (!vis[sink]) return ret;
		ret += dfs(src, INF);
	}
}