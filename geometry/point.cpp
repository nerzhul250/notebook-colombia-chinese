struct pt {  // for 3D add z coordinate
	double x,y;
	pt(double x, double y):x(x),y(y){}
	pt(){}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(double t){return pt(x*t,y*t);}
	pt operator/(double t){return pt(x/t,y/t);}
	double operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	double angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	double operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(double a){return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0);
pt cw90(-1,0);
//REMEMBER U DIMP SHIT
int isEmptyTriangle(pt a, pt b, pt c) {
	for (int i = 0; i < m; i++) {
		if (thePoints[i] == a || thePoints[i] == b || thePoints[i] == c)
			continue;
		if (((thePoints[i]-a)%(b-a))*((thePoints[i]-a)%(c-a))< 0 && 
			((thePoints[i]-b)%(a-b))*((thePoints[i]-b)%(c-b))< 0 &&
			((thePoints[i]-c)%(a-c))*((thePoints[i]-c)%(b-c))< 0)
			return 0;
	}
	return 1;
}
//check if two segments intersect without doubles
typedef pair<pt,pt> seg;
bool intersect(seg sg1,seg sg2){
	ll o1=sg1.ff.orient(sg2.ff,sg2.ss);
	ll o2=sg1.ss.orient(sg2.ff,sg2.ss);
	if(o1==0 && o2==0){
		return max(min(sg1.ff.x,sg1.ss.x),min(sg2.ff.x,sg2.ss.x))<=min(max(sg1.ff.x,sg1.ss.x),max(sg2.ff.x,sg2.ss.x)) &&
			   max(min(sg1.ff.y,sg1.ss.y),min(sg2.ff.y,sg2.ss.y))<=min(max(sg1.ff.y,sg1.ss.y),max(sg2.ff.y,sg2.ss.y));
	}
	bool one=false;
	if(o1==0 || o2==0){
		one=true;
	}else{
		one=(o1<0 && o2>0)||(o2<0 && o1>0);
	}
	ll o3=sg2.ff.orient(sg1.ff,sg1.ss);
	ll o4=sg2.ss.orient(sg1.ff,sg1.ss);
	bool two=false;
	if(o3==0 || o4==0){
		two=true;
	}else{
		two=(o3<0 && o4>0)||(o4<0 && o3>0);
	}
	return one && two;
}
