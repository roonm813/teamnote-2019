//2018.00.00 roonm813 writes.
#include <iostream>
#include <unordered_map>
#include <utility> //this include pair
using namespace std;
int main(void){
	unordered_map<int, int> uMap; //(key, value)
	uMap.insert(pair<int, int>(10, 10));    //성공적으로 insert 되었으면 true 반환
                                            //이미 key값이 있으면 false;
    uMap[20] = 20;
    uMap[30] = 30;
    uMap[40] = 40;

    cout << "size : " << uMap.size() <<endl;

    if(uMap.find(10)!=uMap.end())
        cout << "(" << uMap.find(10)->first << ", " << uMap.find(10)->second << ")" << endl;
    else
        cout <<"not found!"<<endl;


    if(uMap.find(50) != uMap.end())
        cout << "(" << uMap.find(50)->first << ", " << uMap.find(50)->second << ")" << endl;
    else
        cout <<"not found!"<<endl;

    uMap.erase(10); //delete 10;
    if(uMap.find(10)!=uMap.end())
        cout << "(" << uMap.find(10)->first << ", " << uMap.find(10)->second << ")" << endl;
    else
        cout <<"not found!"<<endl;

    uMap.clear();
    if(uMap.empty())
        cout << "map is empty "<<endl;
	return 0;
}
