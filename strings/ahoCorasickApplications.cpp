/*Find all strings from a given set in a text
Given a set of strings and a text. We have to print all occurrences of all strings 
from the set in the given text in O(len+ans), where len is the length of the text and ans
is the size of the answer.

We construct an automaton for this set of strings. We will now process the text letter by letter, 
transitioning during the different states. Initially we are at the root of the trie.
 If we are at any time at state v, and the next letter is c, then we transition to the next state with go(v,c), 
thereby either increasing the length of the current match substring by 1, or decreasing it by following a suffix link.

How can we find out for a state v, if there are any matches with strings for the set? First,
 it is clear that if we stand on a leaf vertex, then the string corresponding to the vertex ends 
at this position in the text. However this is by no means the only possible case of achieving a match:
 if we can reach one or more leaf vertices by moving along the suffix links, then there will
 be also a match corresponding to each found leaf vertex. A simple example demonstrating this 
situation can be creating using the set of strings {dabce,abc,bc} and the text dabc.

Thus if we store in each leaf vertex the index of the string corresponding to it (or the list of 
indices if duplicate strings appear in the set), then we can find in O(n) time the indices of all 
strings which match the current state, by simply following the suffix links from the current vertex
 to the root. However this is not the most efficient solution, since this gives us O(n len) 
complexity in total. However this can be optimized by computing and storing the nearest leaf vertex
 that is reachable using suffix links (this is sometimes called the exit link). This value we can 
compute lazily in linear time. Thus for each vertex we can advance in O(1) time to the next marked
 vertex in the suffix link path, i.e. to the next match. Thus for each match we spend O(1) time, 
and therefore we reach the complexity O(len+ans).

If you only want to count the occurrences and not find the indices themselves, you can calculate 
the number of marked vertices in the suffix link path for each vertex v. This can be calculated 
in O(n) time in total. Thus we can sum up all matches in O(len).

Finding the lexicographical smallest string of a given length that doesn't match any given strings
A set of strings and a length L is given. We have to find a string of length L, which does not
 contain any of the string, and derive the lexicographical smallest of such strings.

We can construct the automaton for the set of strings. Let's remember, that the vertices from which
 we can reach a leaf vertex are the states, at which we have a match with a string from the set. 
Since in this task we have to avoid matches, we are not allowed to enter such states. On the other
 hand we can enter all other vertices. Thus we delete all "bad" vertices from the machine, and in
 the remaining graph of the automaton we find the lexicographical smallest path of length L. This
 task can be solved in O(L) for example by depth first search.

Finding the shortest string containing all given strings
Here we use the same ideas. For each vertex we store a mask that denotes the strings 
which match at this state. Then the problem can be reformulated as follows: initially being in
 the state (v=root, mask=0), we want to reach the state (v, mask=2n-1), where n is the number 
of strings in the set. When we transition from one state to another using a letter, we update 
the mask accordingly. By running a breath first search we can find a path to the state (v, mask=2n-1)
with the smallest length.

Finding the lexicographical smallest string of length L containing k strings
As in the previous problem, we calculate for each vertex the number of matches that
 correspond to it (that is the number of marked vertices reachable using suffix links). 
We reformulate the problem: the current state is determined by a triple of numbers (v, len, cnt), 
and we want to reach from the state (root, 0, 0) the state (v, L, k), where v can be any vertex.
 Thus we can find such a path using depth first search (and if the search looks at the edges in 
their natural order, then the found path will automatically be the lexicographical smallest). */

