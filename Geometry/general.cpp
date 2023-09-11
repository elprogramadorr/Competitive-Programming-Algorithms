struct Point{
    ll x,y;
    bool operator == (Point b) { return x == b.x && y == b.y; }
    bool operator != (Point b) { return !(*this == b); }
    bool operator < (const Point &o) const { return y < o.y || (y == o.y && x < o.x); }
    bool operator > (const Point &o) const { return y > o.y || (y == o.y && x > o.x); }
};
Point operator +(const Point &A, const Point &B) { return {A.x+B.x, A.y+B.y};}
Point operator -(const Point &A, const Point &B) { return {A.x-B.x, A.y-B.y};}
Point operator *(const Point &A, const ll &K) { return {A.x*K, A.y*K};}
ll dot(const Point &A, const Point &B) { return A.x*B.x + A.y*B.y; }
ll cross(const Point &A, const Point &B) { return A.x*B.y - A.y*B.x; }
ll turn(const Point &A, const Point &B, const Point &C) { return cross(B-A,C-A); }
ll dist2(const Point &A, const Point &B) { return dot(A-B,A-B); }
 
vector<Point> convex_hull(vector<Point> p){
    sort(p.begin(), p.end());
    vector<Point> ch;
    ch.reserve(p.size()+1);
    for(int it = 0; it < 2; it++) {
        int start = ch.size();
        for(auto &a : p) {
            /// if colineal are needed, use < and remove repeated points
            while(ch.size() >= start+2 && turn(ch[ch.size()-2], ch.back(), a) < 0)
                ch.pop_back();
            ch.push_back(a);
        }
        ch.pop_back();
        reverse(p.begin(), p.end());
    }
 
    if(ch.size() == 2 && ch[0] == ch[1]) ch.pop_back();
    /// cuidado con convex hull < 3
    return ch;
}
 
double calcular_H(Point a, Point b, Point P){
    //(a,b) * H = area paralelogramo
    double area=abs(cross(P-a,b-a));
    double disAB=sqrt(dist2(a,b));
    // cout<<"area  "<<area<<endl;
    double H=area/disAB;
    return H;
}
