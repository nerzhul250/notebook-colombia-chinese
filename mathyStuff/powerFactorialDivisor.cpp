//You are given two numbers n and k. 
//Find the largest power of k x such that n! is divisible by k^x. Prime k

int fact_pow (int n, int k) {
    int res = 0;
    while (n) {
        n /= k;
        res += n;
    }
    return res;
}


//Composite k
//The same idea can't be applied directly. Instead we can factor k, representing it as k=k1^p1 ... km^pm. For each 
//ki, we find the number of times it is present in n! using the algorithm described above - 
//let's call this value ai. The answer for composite k will be
// min i=1..m {a_i/p_i}

