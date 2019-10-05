#include <iostream>
#include <vector>
#define MAX 101

using namespace std;
// r: 사람, c: 노트북 
vector<int> a[MAX];
// d[i]=a[n] -> i번 노트북을 a[n]이 점유
int d[MAX];	 
// 매칭에 성공했는지 여부(매번 false로 setting)
bool c[MAX];

// 매칭 성공 여부 반환 
bool dfs(int x) {
	// 연결된 모든 노드에 대해서 매칭 시도
	for(int i=0; i<a[x].size(); ++i) {
		int t = a[x][i];
		// 이미 처리한 노드는 skip
		if(c[t]) continue;
		c[t] = true;
		// 비어있거나 점유 노드에 대신 들어갈 수 있는 경우
		if(d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main(void) {
	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(2);
	
	int count = 0;	// 매칭이 이루어진 개수  
	for(int i=1; i<=3; ++i) {
		fill(c, c+MAX, false);
		if(dfs(i)) ++count;
	}
	
	printf("매칭 성공 개수: %d\n", count);
	for(int i=0; i<MAX; ++i) {
		if(d[i] != 0) {
			printf("%d -> %d\n", d[i], i);
		}
	}
}
