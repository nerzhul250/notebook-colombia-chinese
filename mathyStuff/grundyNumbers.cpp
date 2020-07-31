const int stateNum=x;//it should be small
T dp[stateNum];
int get_grundy(T state){
	if(isLosing(state))return 0;
	if(dp[state]!=-1)return dp[state];
	set<int> grundies;
	for each move in state:
		newGame=state.move;
		grundi=0;
		for each nstate in newGame:
			grundi^=get_grundy(nstate);
		grundies.insert(grundi);
	int ngrundy=0;
	while(grundies.count(ngrundy))ngrundy++;
	return dp[state]=ngrundy;
}
