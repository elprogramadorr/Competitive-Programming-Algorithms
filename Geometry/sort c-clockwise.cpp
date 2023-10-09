bool up(Point a){
    return a.y > 0 || (a.y == 0 && a.x >= 0);
}
int cross(const Point &A, const Point &B) { return A.x*B.y - A.y*B.x; }
bool cmp(Point a, Point b){
    if (up(a) != up(b)) return up(a) > up(b);
        return cross(a, b) > 0;
}

// no tan bueno
struct Point{
	int x,y;
    long double A; 
};
long double PI = acos(-1);
long double angle(Point x) {
	long double a = atan2(x.y, x.x);
	if (a < 0) {
		a += 2*PI;
	}
	return a;
}
int cross(const Point &A, const Point &B) { return A.x*B.y - A.y*B.x; }
bool cmp(Point x, Point y){
	return x.A < y.A;	
}