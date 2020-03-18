/*Given a certain lattice polygon with non-zero area.

We denote its area by S, the number of points with integer coordinates lying strictly inside the polygon by I and the number of points lying on polygon sides by B.

Then, the Pick's formula states:

S=I+B/2-1
In particular, if the values of I and B for a polygon are given, the area can be calculated in O(1) without even knowing the vertices.
*/
// Finds the no. of Integral points between 
// two given points. 
int getCount(Point p, Point q) 
{ 
    // If line joining p and q is parallel to 
    // x axis, then count is difference of y 
    // values 
    if (p.x==q.x) 
        return abs(p.y - q.y) - 1; 
  
    // If line joining p and q is parallel to 
    // y axis, then count is difference of x 
    // values 
    if (p.y == q.y) 
        return abs(p.x-q.x) - 1; 
  
    return gcd(abs(p.x-q.x), abs(p.y-q.y))-1; 
} 
