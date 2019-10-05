//2018.00.00 roonm813 writes.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printV(vector<int>* v){
    for(int i = 0; i < v->size(); i++)
        cout << (*v).at(i) << " ";
    cout << endl<<endl;
}

int main(void){
	vector<int> v;
	v.reserve(8); // vector size 8로 예약
	cout << "capacitiy : "<< v.capacity() << endl;
	cout << "max size : " << v.max_size() <<endl<<endl;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(100);
	v.pop_back();
    v.push_back(60);
	v.push_back(70);
	v.push_back(80);
	v.push_back(90);
	v.push_back(100);

	cout << "over capacitiy! what happen? "<< endl;
	cout << "capacitiy : "<< v.capacity() << endl <<endl;

	/* 값에 접근 하는 2가지 방법 */
	cout << "vector size : " << v.size() << endl;
	for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";// []연산자로 값에 접근 가능 , []는 사이즈를 체크하지 않는다.
    cout << endl;

    v.resize(9); //resize 하는 방법
    for(int i = 0; i <v.size(); i++)
        cout << v.at(i) << " ";//at function으로 접근 가능 size를 체크해서 에러 return
    cout << endl<<endl;

    /*fornt back element*/
    cout << "front element : " << v.front() <<endl;
    cout << "back element : " << v.back() << endl;

    /*empty*/
    if(v.empty())
        cout << "vector is empty" << endl;
    else
        cout << "vector is NOT empty" << endl;

    /*sort* , compare함수 , boll compare(type a, type b)*/
    sort(v.begin(), v.end(), greater<int>());
    printV(&v);

    /*insert and assign*/
    vector<int> destV;
    v.insert(v.begin()+2, -1); //(position iterator, value)
    v.insert(v.begin()+4, 3, -2); //(position iterator, size, value)
    destV.assign(v.begin()+6, v.end());
    printV(&v);
    printV(&destV);
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    destV.assign(array, array+10); //assign from array is possible
    printV(&destV);

    /*erase and clear*/
    destV.erase(destV.begin()); //erase first element
    destV.erase(destV.begin()+3, destV.begin()+6); //erase 3, 4, 5 th index element
    printV(&destV);
    destV.clear();
    if(destV.empty())
        cout << "empty after clear "<<endl <<endl;

    /*using iterator and reverse interator*/
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++) //end는 벡터의 마지막 값 그 다음 값을 가르킴 그래서 rit 쓰는 것
        cout << *it << " ";
    cout <<endl;

    vector<int>:: reverse_iterator rit;
    for(rit = v.rbegin(); rit != v.rend(); rit++)
        cout << *rit << " ";
    cout << endl;

 	return 0;
}
