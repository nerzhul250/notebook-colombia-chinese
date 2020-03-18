//MCBM solver in O(V*E), this is how it is used if you want to solve it for the maximal independent set
#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

vi match, vis; // global variables
vi AdjList [2005];
int color[2005],V,visited[2005];
//NORMAL AUGMENTING PATH ALGORITHM V*E
int Aug(int l) { // return 1 if an augmenting path is found
    if (vis[l]) return 0; // return 0 otherwise
    vis[l] = 1;
    for (int j = 0; j < (int)AdjList[l].size(); j++) {
           int r = AdjList[l][j]; // edge weight not needed -> vector<vi> AdjList
           if (match[r] == -1 || Aug(match[r])) {
               match[r] = l; return 1; // found 1 matching
            }
    }
    return 0; // no matching
}

int main(){  
   // build unweighted bipartite graph with directed edge left->right set
   int MCBM = 0;
   match.assign(V, -1); // V is the number of vertices in bipartite graph
   for (int l = 0; l < V; l++) { // n = size of the left set
     if(color[l]==0){
         vis.assign(V, 0); // reset before each recursion
         MCBM += Aug(l);
     }
   }
   cout << V-MCBM << "\n";
   return 0;
}

