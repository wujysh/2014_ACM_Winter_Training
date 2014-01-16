#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 1000000000;
const int MAXN = 20000, MAXM = 500000;
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

struct Edge {
	int v, f, next;
} e[MAXM * 2 + 10];
int n, src, sink, cnt, S, A, B, nCase;
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

void init() {
	memset(head, 0, sizeof(head));
	cnt = 1;
}

void input() {
	scanf("%d %d %d", &S, &A, &B);
	src = 0;	sink = S*A * 2 + 1;

	for (int i = 1; i <= B; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		addEdge(src, (x - 1)*A + y, 1);
	}
	for (int i = 1; i <= A; i++) {
		addEdge(i + S*A, sink, 1);
		addEdge((S - 1)*A + i + S*A, sink, 1);
	}
	for (int i = 2; i < S; i++) {
		addEdge((i - 1)*A + 1 + S*A, sink, 1);
		addEdge((i - 1)*A + A + S*A, sink, 1);
	}
	for (int i = 1; i <= S; i++) {
		for (int j = 1; j <= A; j++) {
			int a = (i - 1)*A + j + S*A, b;
			addEdge(a - S*A, a, 1);
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k], y = j + dy[k];
				if (x >= 1 && x <= S && y >= 1 && y <= A) {
					b = (x - 1)*A + y;
					addEdge(a, b, 1);
				}
			}
		}
	}
}

void output() {
	if (maxflow() == B) {
		printf("possible\n");
	} else {
		printf("not possible\n");
	}
}

int main() {
	//freopen("output.txt", "w", stdout);
	scanf("%d", &nCase);
	while (nCase--) {
		init();
		input();
		output();
	}
	return 0;
}