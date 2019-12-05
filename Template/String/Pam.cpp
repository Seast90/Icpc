// 国家集训队论文 2017 《回文树及其应用》 翁文涛
// https://blog.csdn.net/u013368721/article/details/42100363
// https://blog.csdn.net/qq_38995588/article/details/80644655

// N: 字符串长度 , C: 字符种类数
// t[i][c]: 每个节点 i 表示一个回文串， t[i][c] 表示在回文串 i 两边加上字符 c 形成的新的回文串
// fail[i]: 指向节点 i 的最长真后缀回文串
// cnt[i]:  节点 i 表示的本质不同的回文串的个数（建树时求出的不是完全的，最后跑一遍 count() 后才是正确的）
// flen[i]: 节点 i 的 fail 链的长度，即以节点 i 的最后一个字符为结尾的回文串个数
// len[i]:  节点 i 表示的回文串的长度
// s[i]:    第 i 次加入的字符， s[0] = -1
// last:    指向新添加一个字符后所形成的最长回文串表示的节点
// sno:     添加的字符个数
// no:      节点个数
struct Palindromic_Tree {
    int t[maxn][26], fail[maxn], cnt[maxn], flen[maxn], len[maxn], s[maxn], last, sno, no;
    int newnode (int l) {
        memset(t[no], 0, sizeof(t[no]));
        cnt[no] = flen[no] = 0;
        len[no] = l;
        return no++;
    }
    void init () {    // 初始化
        no = last = 0;
        newnode(0); newnode(-1);
        s[sno=0] = -1;
        fail[0] = 1;
    }
    int get_fail(int x) {
        while (s[sno-len[x]-1] != s[sno]) x = fail[x];
        return x;
    }
    void add(int c) {
        s[++sno] = c;
        int cur = get_fail(last);
        if (!t[cur][c]) {
            int now = newnode(len[cur] + 2);
            fail[now] = t[get_fail(fail[cur])][c];
            t[cur][c] = now;
            flen[now] = flen[fail[now]] + 1;
        }
        last = t[cur][c];
        cnt[last]++;
    }
    void count() { per(i, 0, no) cnt[fail[i]] += cnt[i]; }
}obj;
obj.add(s[i]-'a')
