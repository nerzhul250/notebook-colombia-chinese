fore(i,0,n){
	seq.clear();
	fore(j,i,n){
		if(seq.empty() || a[j]>seq.back()){
			seq.pb(a[j]);
		}else{
			auto t=lower_bound(ALL(seq),a[j]);
			*t=a[j];
		}
		len[i][j]=seq.size();
	}
}
