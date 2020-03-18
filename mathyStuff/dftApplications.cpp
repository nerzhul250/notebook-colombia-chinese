//function for multiplying two polynomials:
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

//Finally the function for multiplying two long numbers practically doesn't differ
//from the function for multiplying polynomials.
//The only thing we have to do afterwards, is to normalize the number:
    int carry = 0;
    for (int i = 0; i < n; i++)
	result[i] += carry;
	carry = result[i] / 10;
	result[i] %= 10;
   }

/*All possible sums
We are given two arrays a[] and b[]. We have to find all possible sums a[i]+b[j], 
and for each sum count how often it appears.
All possible scalar products
We are given two arrays a[] and b[] of length n. We have to compute the products of a with every cyclic shift of b.
We generate two new arrays of size 2n: We reverse a and append n zeros to it. 
And we just append b to itself. When we multiply these two arrays as polynomials,
and look at the coefficient c[n-1], c[n], c[2n-2] of the product c, we get:
c[k]=sum{i+j}=ka[i]b[j]
And since all the elements a[i]=0 for i>=n:
c[k]=sum{i=0 -> n-1}a[i]b[k-i] */


/*String matching
We are given two strings, a text T and a pattern P, consisting of lowercase letters. 
We have to compute all the occurrences of the pattern in the text.
We create a polynomial for each string (T[i] and P[I] are numbers between 0 and 25 corresponding 
to the 26 letters of the alphabet):
A(x)=a0x0+a1x1+...+an-1xn-1,n=|T|
with
ai=cos({alpha}i)+isin({alpha}i),{alpha}i=2{pi}T[i]26.
And
B(x)=b0x0+b1x1+...+bm-1xm-1,m=|P|
with
bi=cos({beta}i)-isin({beta}i),{beta}i=2{pi}P[m-i-1]26.
Notice that with the expression P[m-i-1] explicitly reverses the pattern.
The (m-1+i)th coefficients of the product of the two polynomials C(x)=A(x)*B(x) will tell us, 
if the pattern appears in the text at position i.

cm-1+i=sum {j=0 -> m-1} ai+j*bm-1-j=sum {j=0 -> m-1}(cos({alpha}i+j)+isin({alpha}i+j))*(cos({beta}j)-isin({beta}j))
with {alpha}i+j=2{pi}T[i+j]26 and {beta}j=2{pi}P[j]26
If there is a match, than T[i+j]=P[j], and therefore {alpha}i+j={beta}j. 
This gives (using the Pythagorean trigonometric identity):
cm-1+i=sum{j=0 -> m-1}(cos({alpha}i+j)+isin({alpha}i+j))*(cos({alpha}i+j)-isin({alpha}i+j))=
sum {j=0 -> m-1}cos({alpha}i+j)2+sin({alpha}i+j)2=
sum {j=0 ->m-11}=m
If there isn't a match, then at least a character is different,
which leads that one of the products ai+1*bm-1-j is not equal to 1,
which leads to the coefficient cm-1+i!=m.
String matching with wildcards
This is an extension of the previous problem. 
This time we allow that the pattern contains the wildcard character *, 
which can match every possible letter. E.g. the pattern a*c appears in the text abccaacc 
at exactly three positions, at index 0, index 4 and index 5.

We create the exact same polynomials, except that we set bi=0 if P[m-i-1]=*.
If x is the number of wildcards in P, then we will have a match of P in T at index i if cm-1+i=m-x. */
