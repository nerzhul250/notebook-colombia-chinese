//Given a bitmask m, you want to efficiently iterate through all its submasks, 
//that is, masks s in which only bits that were included in mask m are set.
//O(3^n)
for (int m=0; m<(1<<n); ++m)
    for (int s=m; s; s=(s-1)&m)
 ... s and m ...

