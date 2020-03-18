/*First occurrence position
Given a text T and multiple queries. For each query string P we want to find the position of
the first occurrence of P in the string T (the position of the beginning of P).

We again construct a suffix automaton. Additionally we precompute the position firstpos 
for all states in the automaton, 
i.e. for each state v we want to find the position firstpos[v] of the end of the first occurrence. 
In other words, 
we want to find in advance the minimal element of each set endpos (since obviously cannot maintain all 
sets endpos explicitly).

To maintain these positions firstpos we extend the function sa_extend(). When we create a new state cur, we set:
firstpos(cur)=len(cur)-1
And when we clone a vertex q as clone, we set:
firstpos(clone)=firstpos(q)
(since the only other option for a value would be firstpos(cur) which is definitely too big)

Thus the answer for a query is simply firstpos(t)-length(P)+1, where t is the state corresponding to the string P.
 Answering a query again takes only O(length(P)) time.

All occurrence positions
This time we have to display all positions of the occurrences in the string T.

Again we construct a suffix automaton for the text T. 
Similar as in the previous task we compute the position firstpos for all states.

Clearly firstpos(t) is part of the answer, if t is the state corresponding to a query string P.
So we took into account the state of the automaton containing P. What other states do we need to 
take into account? All states that correspond to strings for which P is a suffix.
In other words we need to find all the states that can reach the state t via suffix links.

Therefore to solve the problem we need to save for each state a list of suffix references leading to it. 
The answer to the query then will then contain all firstpos for each state that we can find on a DFS / BFS 
starting from the state t using only the suffix references.

This workaround will work in time O(answer(P)), because we will not visit a state twice 
(because only one suffix link leaves each state, so there cannot be two different paths leading to the same state).

We only must take into account that two different states can have the same firstpos value. 
This happens if one state was obtained by cloning another. However, this doesn't ruin the complexity,
 since each state can only have at most one clone.

Moreover, we can also get rid of the duplicate positions, if we don't output the positions
from the cloned states. In fact a state, that a cloned state can reach, is also reachable from the original state. 
Thus if we remember the flag is_cloned for each state, we can simply ignore the cloned states and only output 
firstpos for all other states.

