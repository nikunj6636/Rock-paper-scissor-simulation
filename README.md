# Rock-paper-scissor-simulation
Outputs Finite state Automata to Maximise the winning possibility against an unknown initial state RPS game

Input format containing states of FSA and the corresponding transition playing rock, paper and scissor respectively:
```
n
c1 r1 p1 s1
.
.
.
cn rn pn sn
```

To output an FSA with the maximum number of wins against random initial state FSA.

# Logic Implemented:
Output FSA starts with any random state, play rock, paper and scissor there and matches the possibilities of state in the set data structure.
When definite state is known It always plays opposite to the opponent and wins the games in all rounds.
