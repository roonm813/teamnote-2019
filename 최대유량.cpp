#include <iostream>
#include <vector>
#include <queue>

// ������ �ִ� ����
#define MAX 100
#define INF 1000000

using namespace std;

int n = 6, result;
int c[MAX][MAX], f[MAX][MAX];
// �� ����(x->y�� ��, d[y] = x) 
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
				// �뷮�� ���Ұ� �湮���� ���� ����� 
				if(c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x;	// ��� ���
					if(y == end) break; // ��� ã��  
				}
			}
		}
		// ���̻� ������ ��ΰ� ������ Ż�� 
		if(d[end] == -1) break;
		int flow = INF;	// ������ ����(�ּҰ�)�� ã�� ���� 
		// �Ųٷ� �ּ� ���� Ž�� 
		for(int i=end; i!=start; i=d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		} 
		// �ּ� ������ŭ �߰�
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

