bitset<4> bitset1;　　//无参构造，长度为4，默认每一位为0无参构造，

bitset<8> bitset2(12);　　//长度为8，二进制保存，前面用0补充

string s = "100101";
bitset<10> bitset3(s);　　//长度为10，前面用0补充

char s2[] = "10101";
bitset<13> bitset4(s2);　　//长度为13，前面用0补充

bitset<2> bitset1(12);　　//12的二进制为1100（长度为4），但bitset1的size=2，只取后面部分，即00

string s = "100101";　　
bitset<4> bitset2(s);　　//s的size=6，而bitset的size=4，只取前面部分，即1001

char s2[] = "11101";
bitset<4> bitset3(s2);　　//与bitset2同理，只取前面部分，即1110

bitset<N> B;
B.count(); // 1 的个数
B.any(); // 是否有 1
B.none(); // 是否没有 1
B.all(); // 是否全为 1

string s = B.to_string();　　//将bitset转换成string类型
unsigned long a = B.to_ulong();　　//将bitset转换成unsigned long类型
unsigned long long b = B.to_ullong();　　//将bitset转换成unsigned long long类型
