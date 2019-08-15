int legander(int x){  // 判定是否二次剩余
	int a=pows(x,(p-1)/2);
	if(a+1==p) return -1;
	return a;
}
