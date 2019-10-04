/*
	Date : 2019 10 04 
	Author : roonm813 
	Subject : ACM-ICPC Team Note - DFS with while loop. using Stack 
*/ 

/*	which is faster : implement DFS using recursive function calls or using stack? 
	Implementation with stack is slightly faster than with recursive function! but almost same.. 
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


void DFS(int start, Node* graphs){
	stack <int> nextVisits; 
	nextVisits.push(start); 
	graphs[start].visited = true; 

	while(!nextvisits.empty()){
		Node* here = graphs[nextVisits.top()]; 
		nextVisits.pop(); 
	
		for(int i = 0; i < here->neighbors.size(); i++){
			int next = here->neighbors.at(i); 
			if(graphs[next]->visited == false){
				nextVisits.push(next); 
				graphs[next]->visited = true; 
			}
		}
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
