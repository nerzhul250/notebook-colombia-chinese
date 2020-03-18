Double r = radius1;
Double R = radius2;
Double d = distance;
if(R < r){
    // swap
    r = radius2;
    R = radius1;
}
Double part1 = r*r*Math.acos((d*d + r*r - R*R)/(2*d*r));
Double part2 = R*R*Math.acos((d*d + R*R - r*r)/(2*d*R));
Double part3 = 0.5*Math.sqrt((-d+r+R)*(d+r-R)*(d-r+R)*(d+r+R));

Double intersectionArea = part1 + part2 - part3;

