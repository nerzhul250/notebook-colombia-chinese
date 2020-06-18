// Returns the length and the LCIS of two 
// arrays arr1[0..n-1] and arr2[0..m-1] 
int LCIS(int arr1[], int n, int arr2[], int m) { 
    // table[j] is going to store length of LCIS 
    // ending with arr2[j]. We initialize it as 0, 
    int table[m];
    fore(j,0,m) table[j] = 0; 
    // Traverse all elements of arr1[] 
    fore (i,0,n) { 
        // Initialize current length of LCIS 
        int current = 0; 
        // For each element of arr1[], traverse all 
        // elements of arr2[]. 
        fore(i,0,n) { 
            // If both the array have same elements. 
            // Note that we don't break the loop here. 
            if (arr1[i] == arr2[j])if(current + 1 > table[j])table[j] = current + 1; 
            /* Now seek for previous smaller common 
               element for current element of arr1 */
            if (arr1[i] > arr2[j]) if(table[j] > current)current = table[j]; 
        } 
    } 
    // The maximum value in table[] is out result 
    int result = 0; 
    for (int i=0; i<m; i++) 
        if (table[i] > result) 
           result = table[i];   
    return result; 
} 
