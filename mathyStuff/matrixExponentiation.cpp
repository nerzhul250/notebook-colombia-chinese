#define SIZE 350
#define forn(x,n) for(int x = 0; x < n; ++x)
int NN;
void mul(double a[SIZE][SIZE], double b[SIZE][SIZE]){
    double res[SIZE][SIZE]={{0}};
    forn(i,NN) forn(j,NN) forn(k,NN) res[i][j]+=a[i][k]*b[k][j];
    forn(i,NN) forn(j,NN) a[i][j]=res[i][j];
}
void powmat(double a[SIZE][SIZE],int n,double res[SIZE][SIZE]){
    forn(i,NN) forn (j,NN) res[i][j]=(i==j);
    while(n){
        if(n&1)mul(res,a),n--;
        else mul(a,a),n/=2;
    }
}

