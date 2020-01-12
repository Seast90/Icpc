### 32019.07.08

[BZOJ4916](https://www.lydsy.com/JudgeOnline/problem.php?id=4916) (杜教筛，phi(i)*i )

### 2019.07.09

[模板](<https://www.luogu.org/problemnew/show/P4777>)(excrt)

[模板](<https://www.luogu.org/problemnew/show/P4238>)(多项式求逆)

[模板](<https://www.luogu.org/problemnew/show/P4512>)(多项式除法)

[模板](<https://www.luogu.org/problemnew/show/P5205>)(多项式开根号)

[模板](<https://www.luogu.org/problemnew/show/P4717>)(FWT)

[BZOJ4012](<https://www.lydsy.com/JudgeOnline/problem.php?id=4012>)(树链剖分+主席树(区间修改，标记不下传))

### 2019.07.10

[BZOJ2120](<https://www.lydsy.com/JudgeOnline/problem.php?id=2120>)(树状数组套主席树 || 带修改莫队)

[BZOJ3110](<https://www.lydsy.com/JudgeOnline/problem.php?id=3110>)(线段树套线段树(区间修改，标记不下传))

### 2019.07.11

[BZOJ3333](<https://www.lydsy.com/JudgeOnline/problem.php?id=3333>)(线段树)

学习Dsu on tree

[CF 600E](<https://codeforces.com/contest/600/problem/E>)(Dsu on tree)

[CF 1009F](<https://codeforces.com/contest/1009/problem/F>)(Dsu on tree)

[CF 741D](<https://codeforces.com/contest/741/problem/D>)(Dsu on tree)

学习长链剖分

### 中间日期 数据丢失

### 2019.07.15

[CF 1194E](<https://codeforces.com/contest/1194/problem/E>)(树状数组)

[CF 1194F](<https://codeforces.com/contest/1194/problem/F>)(组合数前缀和)

学习笛卡尔树

[CF 893F](<https://codeforces.com/contest/893/problem/F>)(按深度建dfs序id主席树)

[CF 893F](<https://codeforces.com/contest/893/problem/F>)(线段树合并)

### 2019.07.16

[BZOJ2616](<https://www.lydsy.com/JudgeOnline/problem.php?id=2616>)(笛卡尔树 树型DP)

[CF 1093F](<https://codeforces.com/contest/1093/problem/F>)(DP)

### 2019.09.02

## 概率dp

- [x] https://www.lydsy.com/JudgeOnline/problem.php?id=3450

  维护连续1平方的期望，知道了期望可以通过维护差值来转移

- [x] https://www.lydsy.com/JudgeOnline/problem.php?id=4318

  维护连续1立方的期望，和之前差不多，多维护一项平方的期望

- [x] https://www.lydsy.com/JudgeOnline/problem.php?id=1426

  收集n个物品，每次随机买，每买一次价格贵1，问期望多少钱买齐

  状态要建立成有i个物品且还没买过东西，这样可以和前面无关，然后化简转移方程

- [x] https://www.lydsy.com/JudgeOnline/problem.php?id=4844

​	计算每种后缀的出现概率，然后计算每种后缀的贡献

- [ ] <https://codeforces.com/contest/850/problem/F>

## 数论



## 动态点分治

bzoj3924

bzoj1095

bzoj3730

Qtree4

bzoj4372

bzoj5912

## 后缀自动机

- [ ] [CF](<https://codeforces.com/gym/100962/>)  D

- [x] <https://codeforces.com/contest/427/problem/D>

  求最大公共子串

- [x] <https://codeforces.com/contest/700/problem/E>

  后缀自动机+线段树合并+dp

- [x] https://codeforces.com/contest/235/problem/C

  求本质不同的子串的旋转同构出现次数

- [ ] <https://codeforces.com/problemset/problem/316/G3>

- [x] [Ahoi2013差异 3238](<https://www.lydsy.com/JudgeOnline/problem.php?id=3238>)

  求所有后缀的公共前缀之和，翻转之后建后缀自动机，变成求所有前缀的最大后缀之和，等同于求树上的 $lca$，普通的树dp

- [x] <https://www.lydsy.com/JudgeOnline/problem.php?id=3473>

  后缀自动机， 统计答案时暴力向上跳 复杂度 $O(nlogn) $

- [x] https://www.lydsy.com/JudgeOnline/problem.php?id=3277

- [x] [1396识别子串 1396](https://www.lydsy.com/JudgeOnline/problem.php?id=1396)

  sam+线段树，维护两棵线段树对于右半段维护每个结点最短字符串的控制范围区间覆盖最短长度，对于 左半段维护 区间最小的 $pos$ 

- [x] [同上卡空间 2856](https://www.lydsy.com/JudgeOnline/problem.php?id=2865)

- [x] [[Haoi2016]找相同字符 4566](https://www.lydsy.com/JudgeOnline/problem.php?id=4566)

  简单题

- [x] [[Spoj]8093 Sevenk Love Oimaster 2780](https://www.lydsy.com/JudgeOnline/problem.php?id=2780)

  建广义sam，染色时暴力向上跳，**复杂度不会证明**

- [x] [2882: 工艺](https://www.lydsy.com/JudgeOnline/problem.php?id=2882)

  求循环左移最小字典序，加长一倍插入自动机，从1开始跑$|s|$次就是答案

- [x] [3998: [TJOI2015]弦论](https://www.lydsy.com/JudgeOnline/problem.php?id=3998)

  求第K字典序的串， 分本质相同和本质不同，记忆化$dfs$记录从这个点出发的路径数量，然后还要加上自己本身的贡献，如果求本质相同那么自身贡献为1，否则自身贡献为在字符串中的出现次数。

- [x] [4516: [Sdoi2016]生成魔咒](https://www.lydsy.com/JudgeOnline/problem.php?id=4516)

  简单题，求每个前缀本质不同的子串数量，对于每个新加入的节点，对答案贡献就是这个节点表示的串的数量。字符集很大要用map存。

- [x] [4892: [Tjoi2017]dna](https://www.lydsy.com/JudgeOnline/problem.php?id=4892)

  FFT or 暴力$dfs(x,l,t)$在后缀自动机上跑，表示 当前在$x$结点，匹配长度 $l$，失配次数 $t$ 算总方案数，匹配完成后 加上当前结点的$cnt$大小。**复杂度不会证明**

## AC自动机

- [ ] <https://codeforces.com/problemset/problem/710/F>

  支持修改的ac自动机 

## 回文自动机

- [x] <https://www.lydsy.com/JudgeOnline/problem.php?id=3676>

  板子题

- [x] [2565: 最长双回文串](https://www.lydsy.com/JudgeOnline/problem.php?id=2565)

  问最长的前半段和后半段都是回文串的串长度，维护从$i$开始的最长回文子串长度$f[i]$，和以$i$为结尾的最长回文子串长度$g[i]$, $max(f[i],g[i+1])$ 既是答案，正串反串跑一遍回文自动机，分别记录$f[i]$和$g[i]$。

- [x] [2160: 拉拉队排练](https://www.lydsy.com/JudgeOnline/problem.php?id=2160)

  求所有奇数长度的回文子串中，长度前$k$大的回文子串的乘积，回文自动机建出来后$dfs$ 回文自动机的$odd$节点，将所有奇数长度的回文子串提取出来排序之后取前$k$大。

- [x] [E. Palisection](https://codeforces.com/contest/17/problem/E)

  求所有相交的回文子串的对数，可以反过来求所有不相交的回文子串的对数取反，维护从 $i$ 开始的最长回文子串长度 $f[i]$ ，和以$i$为结尾的最长回文子串长度 $g[i]$ , 设 $f[i]$ 前缀和为 $F[i]$ , 答案既是

  $ \sum_{i=0}^{n-1} F[i]*g[i+1]$

- [x] [2084: [Poi2010]Antisymmetry](https://www.lydsy.com/JudgeOnline/problem.php?id=2084)

  $0==1，1!=0, 0 != 1$，求这样的回文子串个数，改一下回文自动机中 $getfail$的判断为$!=$ ，并且奇数串一定不符合条件，所以当$cur$为$1$ 的时候退出。

- [x] [2342: [Shoi2011]双倍回文](https://www.lydsy.com/JudgeOnline/problem.php?id=2342)

  求最长的$ww^Rww^R$ 形式的串， 首先这个串是个回文串，并且他一半的后缀也是个回文串，所以只要判断$fail$树上根节点到当前的点是否存在一个$len[x]/2$ 的节点，$dfs$序用个$multiset$动态维护，回溯时撤回即可。

- [x] [3160: 万径人踪灭](https://www.lydsy.com/JudgeOnline/problem.php?id=3160)

  求回文子序列的个数减去回文子串的个数，$FFT + manacher/回文自动机$

  回文子序列的个数可以用$FFT$ 求。

- [ ] 

- [ ] 

  

  



## 数据结构

- [ ] <https://codeforces.com/contest/1260/problem/F>

  
