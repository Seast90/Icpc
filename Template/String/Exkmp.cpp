/*
z[i] : max length of string start from i which is also prefix of s
*/
int z[N];
string s;
void zfunction() {
	int len = s.length();
	z[0] = len;
	for(int i = 1,L = 0,R = 0;i < len;i++) {
		if(R >= i) z[i] = min(R - i + 1,z[i - L]);
		else z[i] = 0;
		while(i + z[i] < len && s[z[i]] == s[i + z[i]]) ++z[i];
		if(i + z[i] - 1 > R) R = i + z[i] - 1,L = i;
	}
}
/*
< 准备 >
    1. 字符串 s[] 与字符串 t[] ，下标从 0 开始
< 使用 >
    1. 调用 ex.exkmp(s, n, t, m) ， n 和 m 分别为 s[] 与 t[] 的长度，得
    .. lcp[i] 表示 t[] 与 s[i, n-1] 的最长公共前缀长度
    .. net[i] 表示 t[] 与 t[i, m-1] 的最长公共前缀长度
*/

int net[N], lcp[N];
struct Extend_KMP {
    void Get(char t[], int m) {
        int a = 0, p = 0;
        net[0] = m;
        rep(i, 1, m) {
            if (i >= p || i + net[i-a] >= p) {
                if (i >= p) p = i;
                while (p < m && t[p] == t[p-i]) p++;
                net[a=i] = p - i;
            } else {
                net[i] = net[i-a];
            }
        }
    }
    void exkmp(char s[], int n, char t[], int m) {
        Get(t, m);
        int a = 0, p = 0;
        rep(i, 0, n) {
            if (i >= p || i + net[i-a] >= p) {
                if (i >= p) p = i;
                while (p < n && p - i < m && s[p] == t[p-i]) p++;
                lcp[a=i] = p - i;
            } else {
                lcp[i] = net[i-a];
            }
        }
    }
} ex;
