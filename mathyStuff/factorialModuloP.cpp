//You want to calculate n!modp, without taking all the multiple factors of p into account that appear in the factorial. 
//Imaging you write down the prime factorization of n!, remove all factors p, and compute the product modulo p.
//O(p*log_p(n))
int factmod(int n, int p) {
    int res = 1;
    while (n > 1) {
        res = (res * ((n/p) % 2 ?  p-1 : 1)) % p;
        for (int i = 2; i <= n%p; ++i)
            res = (res * i) % p;
        n /= p;
    }
    return res % p;
}

