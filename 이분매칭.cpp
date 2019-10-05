#include <iostream>
#include <vector>
#define MAX 101

using namespace std;
// r: ���, c: ��Ʈ�� 
vector<int> a[MAX];
// d[i]=a[n] -> i�� ��Ʈ���� a[n]�� ����
int d[MAX];	 
// ��Ī�� �����ߴ��� ����(�Ź� false�� setting)
bool c[MAX];

// ��Ī ���� ���� ��ȯ 
bool dfs(int x) {
	// ����� ��� ��忡 ���ؼ� ��Ī �õ�
	for(int i=0; i<a[x].size(); ++i) {
		int t = a[x][i];
		// �̹� ó���� ���� skip
		if(c[t]) continue;
		c[t] = true;
		// ����ְų� ���� ��忡 ��� �� �� �ִ� ���
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
	
	int count = 0;	// ��Ī�� �̷���� ����  
	for(int i=1; i<=3; ++i) {
		fill(c, c+MAX, false);
		if(dfs(i)) ++count;
	}
	
	printf("��Ī ���� ����: %d\n", count);
	for(int i=0; i<MAX; ++i) {
		if(d[i] != 0) {
			printf("%d -> %d\n", d[i], i);
		}
	}
}
