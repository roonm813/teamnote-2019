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
    myStack.push(1); //push -> 원소 저장
    myStack.push(0);
    myStack.pop(); //top에 있는 원소 삭제
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.top(); //top에 있는 원소 반환
    int size = myStack.size();  //사이즈를 반환하는 함수

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
    for(int i = 0; i < 5; i++){    //원래라면 생성자를 모두 생성한 뒤 복사하는 형식으로 진행된다.
        stackPairs.emplace(i, -i); //내부적으로 constructor 호출 -> 속도 향상
    }
    printStack(&stackPairs);

	return 0;
}
