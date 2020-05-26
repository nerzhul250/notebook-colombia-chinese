/*It is a set in c++, but it has extended functions*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree < int ,  null_type ,  less<int> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set


/*
int : It is the type of the data that we want to insert (KEY).It can be integer, float or pair of int etc.
null_type : It is the mapped policy. It is null here to use it as a set.If we want to get map but not the set, as the second argument type must be used mapped type.
less : It is the basis for comparison of two functions.
rb_tree_tag : type of tree used. It is generally Red black trees because it takes log(n) time for insertion and deletion while other take linear time such as splay_tree.
tree_order_statistics_node__update : It is included in tree_policy.hpp and contains various operations for updating the node variants of a tree-based container, so we can keep track of metadata like the number of nodes in a subtree
FUNCTIONS
find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.To find the first element k must be zero.
Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
*(s.find_by_order(2)) : 3rd element in the set i.e. 6
*(s.find_by_order(4)) : 5th element in the set i.e. 88
order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.
*/
