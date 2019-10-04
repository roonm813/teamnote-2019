/*
	Date : 2019 10 04 
	Author : roonm813 
	Subject : ACM-ICPC Team Note - DFS with recursive call 
*/ 

class Node{
public: 
	//add field which you need
	int myNodeNumber; 
	vector<int> neighbors; 
	bool visited; 
	Node(int _myNodeNumber):myNodeNumber(_myNodeNumber), visited(false){ 
	}
}


void DFS(int here, Node* graphs){
	cout << "DFS visits" << here << endl; 
	for(int i = 0; i < graphs[N]->neighbors.size(); i++){
		int next = graphs[N]->neighbors.at(i); 
		if(graphs[N]->visited == false)
			DFS(next, graphs)
	} 
}

int main(){
	//N = number of Node  
	//Initialization graphs
	Node* graphs[N]; 
	for(int i = 0; i < N; i++){
		graphs = new Node(i); 
		//add Edge information
	}

	//DFS all
	//만약 connected graph가 아닌 경우를 대비해 visited가 아니라면 해당 node를 시작점으로 방문해야함.
	for(int i = 0; i < N; i++){
		if(graphs[N]->visited == false)
			DFS(i, graphs); 
	}

}