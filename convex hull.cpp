typedef struct{
	int x, y; 
}Point;

Point *plane;
vector<Point> ch;

int ccw(Point bef, Point piv, Point aft){
	Point vt1 = {piv.x-bef.x, piv.y-bef.y};
	Point vt2 = {aft.x-piv.x, aft.y-piv.y};
	return vt1.x*vt2.y - vt2.x*vt1.y;
}
int dot_product(Point bef, Point piv, Point aft){
	Point vt1 = {piv.x-bef.x, piv.y-bef.y};
	Point vt2 = {aft.x-piv.x, aft.y-piv.y};
	return vt1.x*vt2.x + vt1.y*vt2.y;
}
void graham_scan(){
	//처음 두 점을 잡음.
	ch.push_back(plane[0]);
	ch.push_back(plane[1]);
	int idx = 2;
	
	while(idx < N){
		while(ch.size()>1){
			// degree = 0
			// ccw(last-1, last, cur) == 0 && dot_product > 0
			if(ccw(*(ch.end()-2), *(ch.end()-1), plane[idx]) == 0 
			&& dot_product(*(ch.end()-2), *(ch.end()-1), plane[idx]) > 0){
				ch.pop_back();
			}
			// CW: ccw(last-1, last, cur) < 0
			else if(ccw(*(ch.end()-2), *(ch.end()-1), plane[idx]) < 0){
				ch.pop_back();
			}
			// CCW or degree = 180
			else
				break;
		}
		// CCW
		if(ccw(*(ch.end()-2), *(ch.end()-1), plane[idx]) > 0)
			ch.push_back(plane[idx]);
		idx++;
	}
	// If Last is not CCW
	if(ccw(*(ch.end()-2), *(ch.end()-1), plane[0]) <= 0){
		ch.pop_back();
	}
}

int main(){
	
	plane = new Point[N];
	for(int i=0; i<N; i++){
	// 1. plane(point의 집합)을 입력받는다.
	// 2. point들 중, 최솟값을 pivot으로 잡는다.
	}
	// 3. sorting Points
	// 4. get convex hull
	graham_scan();

}
