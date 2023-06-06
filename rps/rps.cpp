#include<bits/stdc++.h>
using namespace std;

const int R = 0;
const int P = 1;
const int S = 2;
// (+1)%3 are contradicting descp

typedef pair<int, int> ii;

vector<int> descp(1000); // contains descriptor of the transition
vector<vector<int>> transitions(1000, vector<int>(3));
int n, initial;

void stateInit()
{
    n++;
    descp[n] = rand()%3;
    transitions[n] = {1,1,1};
}

int stateloop = 0; // struck in loop

void dfs(set<int>& states, int curr_state)
{
    set <int> abc[3]; // map to r, p, s
    int p = descp[curr_state];

    for(int u: states) abc[descp[u]].insert(transitions[u][p]);// using R, P, S descp

    for(int i=0; i<3; i++){ // for R, P, S respectively
        
        if (abc[i].size() == 1) transitions[curr_state][i] = *abc[i].begin();

        else if (abc[i].size() > 1){
            
            bool flag = true;
            int s = descp[*abc[i].begin()]; // finding the initial state
            for(auto it = abc[i].begin(); it != abc[i].end(); it++)
            {
                if (descp[*it] != s) flag = false;
            }
            // evaluating same states

            if (flag == true) stateloop++; // goinf to the same states repeatedly

            if (flag == true && stateloop >= 7){ // checked all the states
                transitions[curr_state][i] = *abc[i].begin();
                stateloop = 0;
            } // ending the recursion

            else{
                stateInit();
                transitions[curr_state][i] = n; // making transiton from curr state to new_state.
                if (flag == false) stateloop = 0;
                dfs(abc[i], n);
            }
        }
    }
}

int reorder(int i)
{
    int r;
    if (i <= initial) r = i + 1;
    else if (i == initial + 1) r = 1;
    else r = i;

    return r;
}

void printState(int p){
    if (p == R) cout << "R "; // given the same state that always wins
    if (p == P) cout << "P ";
    if (p == S) cout << "S ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n; // the number of input descp
    char c;

    initial = n;

    set<int> states; // to have the state of the given n descp
    for(int i=1; i<=n; i++){ // considering first case as initail state

        cin >> c;
        if (c == 'R') descp[i] = R; // given the same state that always wins
        if (c == 'P') descp[i] = P;
        if (c == 'S') descp[i] = S;
        states.insert(i);

        for(int j=0; j<3; j++) cin >> transitions[i][j]; // outputting the contradicting DFS.
    }

    // n+1 is the start state
    stateInit();
    dfs(states, n);

    cout << n << endl; // the number of states
    int start = initial + 1;

    // print the start state
    printState(descp[start]);
    for(int j=0; j<3; j++) cout << reorder( transitions[start][j] ) << " ";
    cout << endl;

    // print the opposing DFA
    for(int i = 1; i <= initial; i++){ // considering first case as initail state

        int p = descp[i];
        if (p == R) cout << "P "; // given the same state that always wins
        if (p == P) cout << "S ";
        if (p == S) cout << "R ";

        for(int j=0; j<3; j++) cout << transitions[i][(j+1)%3]+1 << " "; // outputting the contradicting DFS
        cout << endl;
    }  

    for(int i = start+1; i <= n; i++){ // considering first case as initail state

        printState(descp[i]);
        for(int j=0; j<3; j++) cout << reorder( transitions[i][j] ) << " ";
        cout << endl;
    }
}