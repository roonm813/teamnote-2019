//2018.00.00 roonm813 writes.
#include <iostream>
#include <stack>
#include <utility>
using namespace std;

void printStack(stack<int>* myStack){
    stack<int> tmpstack;
    while(!myStack->empty()){
        cout << myStack->top() << " ";
        tmpstack.push(myStack->top());
        myStack->pop();
    }
    while(!tmpstack.empty()){
        myStack->push(tmpstack.top());
        tmpstack.pop();
    }
    cout << endl;
}

void printStack(stack<pair<int, int>>* myStack){
    while(!myStack->empty()){
        cout << "(" << myStack->top().first <<" , "<< myStack->top().second << ")" << endl;
        myStack->pop();
    }
}

int main(void){
    stack <int> myStack;
    myStack.push(1); //push -> ���� ����
    myStack.push(0);
    myStack.pop(); //top�� �ִ� ���� ����
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.top(); //top�� �ִ� ���� ��ȯ
    int size = myStack.size();  //����� ��ȯ�ϴ� �Լ�

    cout << "stack size : "<< size <<endl;

    while(!myStack.empty()){
        cout << myStack.top() << endl;
        myStack.pop();
    }

    /*stack swap added in c++11, swap test*/
    stack<int> StackEven;
    for(int i = 1; i < 10; i++)
        StackEven.push(i*2);
    stack<int> StackOdd;
    for(int i = 1; i < 10; i++)
        StackOdd.push(i*2-1);
    cout << "before swap :"<<endl;
    cout << "stack Even : "; printStack(&StackEven);
    cout << "stack Odd : " ; printStack(&StackOdd);

    StackEven.swap(StackOdd);
    cout << "after swap : " << endl;
    cout << "stack Even : "; printStack(&StackEven);
    cout << "stack Odd : "; printStack(&StackOdd);

    /*stack emplace added in c++11, emplace test*/
    stack <pair<int, int>> stackPairs;
    for(int i = 0; i <5; i++){
        stackPairs.push(make_pair(i, -i));
    }
    for(int i = 0; i < 5; i++){    //������� �����ڸ� ��� ������ �� �����ϴ� �������� ����ȴ�.
        stackPairs.emplace(i, -i); //���������� constructor ȣ�� -> �ӵ� ���
    }
    printStack(&stackPairs);

	return 0;
}
