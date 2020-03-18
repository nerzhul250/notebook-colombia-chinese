//We can write an odd composite number 
//n=p*q as the difference of two squares 
//n=a to the 2-b to the 2, o(abs(p-q))
int fermat(int n) {
    int a = ceil(sqrt(n));
    int b2 = a*a - n;
    int b = round(sqrt(b2));
    while (b * b != b2) {
        a = a + 1;
        b2 = a*a - n;
        b = round(sqrt(b2));
    }
    return a - b;
}

