//2018.00.00 roonm813 writes.
#include <iostream>
#include <queue>
using namespace std;
int main(void){
	queue<int> myQueue;
	myQueue.push(0);
	myQueue.push(1);
	myQueue.push(2);
	myQueue.pop();
	myQueue.push(3);
	myQueue.push(4);

	cout << "front element : " << myQueue.front() <<endl;
    cout << "end element : " << myQueue.back() <<endl;
	cout << "queue size : "<< myQueue.size() <<endl;

	while(!myQueue.empty()){
        cout << myQueue.front() <<endl;
        myQueue.pop();
	}

	/*stack�� ���������� c++11���ķδ� emplace �� swap ���� */
	return 0;
}
