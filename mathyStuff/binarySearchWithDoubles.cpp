int it=100;
double d1=0,d2=-D;
while(it--){
    double dmid=(d1+d2)/2;
    theArea=simpson_integration(0,W,dmid);
    if(theArea>A){
        d2=dmid;
    }else{
        d1=dmid;
    }
}

