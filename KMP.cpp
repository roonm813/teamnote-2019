/*
 	Date : 2019 10 05 
	Author : roonm813 
	Subject : ACM-ICPC Team Note - Knuth Morris Pratt algorithm 
	Time Complecity : O(|pattern| + |arr|)
 */

void getPI(int* pi, const string& pattern){
	int patternSize = pattern.size(); 

	int begin = 1; 
	int matched = 0; 

	while(begin + matched < patternSize){
		if(pattern[ begin + matched ] == pattern [ matched ]){
			matched++; 
			// matched된 갯수를 적어 다음에 matched된 갯수만큼 jump할 수 있도록 한다. 
			pi[ begin + matched - 1 ] = matched; 
		}
		else{
			if(matched == 0)
				begin++; 
			else{
				//pi table을 이용해서 다음 begin을 찾는다. 
				begin += matched - pi[matched -1]; 
				matched = pi[matched-1]; 
			}
		}
	}

}



vector<int> KMP(const string& arr, const string& pattern){
	int arrSize = arr.size(); 
	int patternSize = pattern.size(); 
	vector<int> result; 

	int* pi = new int[patternSize](); 
       	getPI(pi, pattern); 

	int begin = 0; //arr에서 비교 시작 위치를 나타냄. 
	int matched = 0; //begin에서 시작하여 현재 match된 글자 갯수 
	while( begin <= arrSize - patternSize ){
		//pattern과 array가 일치하는 경우 
		if( matched < patternSize && arr[ begin + matched ] == pattern[ mateched ] ){
			matched++; 
			// 모두 일치하는 경우 답에 추가. 
			if( matched == m ) 
				ret.push_back(begin); 
		}  
		else{
			//match가 0인 경우 다음 칸에서 바로 비교 시작
			if(matched == 0) 
				begin++; 
			else{
				//main part of KMP, use pi array for jump
				begin += matched - pi[matched - 1]; 
				matched = pi[matched - 1]; 
			}
		}	
	}
	return ret; 
}
