#include <iostream>
#include <vector>
#include <queue>

// 정점의 최대 개수
#define MAX 100
#define INF 1000000

using namespace std;

int n = 6, result;
int c[MAX][MAX], f[MAX][MAX];
// 길 저장(x->y일 때, d[y] = x) 
int d[MAX];
vector<int> a[MAX];

void maxFlow(int start, int end) {
	while(1) {
		fill(d, d+MAX, -1);
		queue<int> q;
		q.push(start);
		while(!q.empty()) {
			int x = q.front();
			q.pop();
			for(int i=0; i<a[x].size(); ++i) {
				int y = a[x][i];
				// 용량이 남았고 방문하지 않은 노드임 
				if(c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x;	// 경로 기억
					if(y == end) break; // 경로 찾음  
				}
			}
		}
		// 더이상 가능한 경로가 없으면 탈출 
		if(d[end] == -1) break;
		int flow = INF;	// 가능한 유량(최소값)을 찾기 위해 
		// 거꾸로 최소 유량 탐색 
		for(int i=end; i!=start; i=d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		} 
		// 최소 유량만큼 추가
		for(int i=end; i!=start; i=d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		result += flow;
	}
} 

int main(void) {
	a[1].push_back(2);
	a[2].push_back(1);
	c[1][2] = 8;
	//...
	
	maxFlow(1,2);
	printf("%d", result);
	return 0;
}

