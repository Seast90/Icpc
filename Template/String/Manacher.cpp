/*
     s[i] 0   1   2   3   4
          a   b   a   a   b
    pa[j] 0 1 2 3 4 5 6 7 8
          1 0 2 0 1 2 1 0 1
    pa[j]: 以 j 为中心最长的回文串左侧包括 j 的长度
    */
// 两倍数组
void Manacher(char *s,int n,int *pa) {
	pa[0] = 1;
	for(int i = 1,j = 0;i < (n << 1) - 1;++i) {
		int p = i >> 1,q = i - p,r = ((j + 1) >> 1) + pa[j] - 1;
		pa[i] = r < q ? 0 : min(r - q + 1,pa[(j << 1) - i]);
		while(0 <= p - pa[i] && q + pa[i] < n && s[p - pa[i]] == s[q + pa[i]])
			pa[i]++;
		if(q + pa[i] - 1 > r) j = i;
		/*sum[i / 2 + 1]--;
		sum[i / 2 - pa[i] + 1]++;*/  // 以 i 为 开始的回文串个数 
		
		sum[(i + 1) / 2]++;
		sum[(i + 1) / 2 + pa[i]]--; // 以 i 为 结尾的回文串个数 
	}
}
-------------------------------------
/*
     s[i]     0   1   2   3   4
              a   b   a   a   b
     t[i] 0 1 2 3 4 5 6 7 8 9 A B C
          $ # a # b # a # a # b # @
   len[i]   1 2 1 4 1 2 5 2 1 2 1
    real = len[i] - 1;
all i for t: 
    i/2-1 是串中心或中心左边的字符在 s 中的下标
    L[i] 表示 i 为中心的最长回文串的左端点在 s 中的下标， R[i] 同
    L[i] = i/2 - len[i] / 2;
    R[i] = i/2-1 + (len[i]-1)/2;
*/
char s[N],T[N << 1];
int len[N << 1];
void Manacher() {
	int m = strlen(s),n = 0;
	T[n++] = '$';
	for(int i = 0;i < m;i++) {
		T[n++] = '#';
		T[n++] = s[i];
	}
	T[n++] = '#';
	T[n++] = '@';
	len[0] = 1;
	for(int i = 1,id = 0,r = 0;i < n - 1;i++) {
		if(r >= i) len[i] = min(r - i + 1,len[id * 2 - i]);
		else len[i] = 1;
		while(T[i + len[i]] == T[i - len[i]]) ++len[i];
		if(i + len[i] - 1 > r) r = i + len[i] - 1,id = i;
	}
}
