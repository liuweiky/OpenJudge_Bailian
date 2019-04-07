# OpenJudge_Bailian
北大百练题解

## 1000:A+B Problem

[Problem description](http://bailian.openjudge.cn/practice/1000/)

[C++ (Accepted)](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1000/main.cpp)

## 1001:Exponentiation

[Problem description](http://bailian.openjudge.cn/practice/1001/)

[C++ (Accepted)](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1001/main.cpp)

### 解题思路

大整数运算，字符串处理，模拟。

首先确定 R 的整数部分和小数部分及其各自数位(llen, rlen)长度。之后去掉小数点，进行大整数运算。在算出结果中，依次作如下判断和修改：

1. 所得结果长度是否不小于 rlen * n？根据小数运算规律，所得的结果小数部分长度应为 rlen * n（包括末尾的 0）。若所得结果长度小于 rlen * n，则在结果前面[加 0](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1001/main.cpp#L63)，直到长度为 rlen * n。

2. 确定结果中应插入的[小数点位置](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1001/main.cpp#L66)

3. [消除小数部分末尾的 0 和多余的小数点](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1001/main.cpp#L70)

## 1002:方便记忆的电话号码

[Problem description](http://bailian.openjudge.cn/practice/1002/)

[C++ (Accepted)](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1002/main.cpp)

### 解题思路

string 的替换 + STL map 的使用。

## 1003:Hangover

[Problem description](http://bailian.openjudge.cn/practice/1003/)

[C++ (Accepted)](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1003/main.cpp)

### 解题思路

题意理解清楚即可。

## 1004:财务管理

[Problem description](http://bailian.openjudge.cn/practice/1004/)

[C++ (Accepted)](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1004/main.cpp)

## 1005:I Think I Need a Houseboat

[Problem description](http://bailian.openjudge.cn/practice/1005/)

[C++ (Accepted)](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1005/main.cpp)

## 1006:Biorhythms

[Problem description](http://bailian.openjudge.cn/practice/1006/)

[C++ (Accepted)](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1006/main.cpp)

### 解题思路

模拟，每次增加一天，检查是否是 peak day。

## 1007:DNA排序

[Problem description](http://bailian.openjudge.cn/practice/1007/)

[C++ (Accepted)](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1007/main.cpp)

### 解题思路

每次读入一个字符，检查之前读入的字符串中与之逆序的有多少个（打表记录之前某个字符出现多少次），加入总计数器中，之后当前字符出现次数 + 1。

## 1008:Maya Calendar

[Problem description](http://bailian.openjudge.cn/practice/1008/)

[C++ (Accepted)](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1008/main.cpp)

### 解题思路

取模，映射， STL map 的使用。

## 1011:Sticks

[Problem description](http://bailian.openjudge.cn/practice/1011/)

[C++ (Accepted)](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1011/main.cpp)

### 解题思路

DFS + 剪枝。不断加入短木棍，若凑成一根，则继续从剩余木棍中拼凑。

不剪枝必然超时。下面是剪枝策略。

1. [应从大到小加入木棍](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1011/main.cppL25)。
2. [若之前有相同长度的木棍失败，则不再尝试下一根相同长度木棍](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1011/main.cppL27)。
3. [若想要凑一根新的木棍时，从第一根短木棍开始搜索失败，则不再从其他长度木棍开始尝试](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1011/main.cppL32)。

## 1012:Joseph

[Problem description](http://bailian.openjudge.cn/practice/1012/)

[C++ (Accepted)](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1012/main.cpp)

### 解题思路

约瑟夫环问题。

第 i 轮被 kill 者下标（每轮环中要除去被 kill 的人）公式：p = (p + m - 1) % (n - i)。其中 m 是报数值 (1, 2, ..., m)，n 是原环中的总人数。初始时 p = 0。

> 举例：n = 10, m = 4
> 
> 0 1 2 3 4 5 6 7 8 9 -- index
>
> 0 1 2 ~~3~~ 4 5 6 7 8 9
>
> 0 1 3 4 5 6 ~~7~~ 8 9
> 
> 0 ~~1~~ 3 4 6 7 8 9
>
> 0 3 4 6 ~~7~~ 8 9
>
> . . .

可见，只要前 k 轮保持 p >= k 即可。

注意[打表](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1012/main.cpp#L37)，否则超时。

对于约瑟夫环问题，求最终胜利者下标有类似公式：p = (p + m) % **i**, i 从 2 到 n, 初始 p = 0。证明从略。

## 1013:Counterfeit Dollar

[Problem description](http://bailian.openjudge.cn/practice/1013/)

[C++ (Accepted)](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1013/main.cpp)

### 解题思路

打表，初始时所有字符都置为 UNKNOWN，当出现“even”，则说明所有在左盘和右盘的都为真币（0）。当出现“up”时，将右盘所有为 UNKNOWN 的置为 -1（light），所有已经疑似 light 的自减 1，所有疑似 heavy 的置为真币（若为真币，不可能一下轻一下重，只可能是被同盘的其他假币干扰）。出现“down”操作同理。

## 1014:Dividing

[Problem description](http://bailian.openjudge.cn/practice/1014/)

[C++ (Accepted)](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1014/main.cpp)

### 解题思路

多重背包的[二进制优化](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1014/main.cpp#L59)。

将若不考虑时间限制，多重背包可以直接转换为 0-1 背包（只需设置某一类每个物品拆分为单独一个）。若时间有限制，则需将某一类物品拆分，捆绑为 1, 2, 4, . . ., 剩余部分。把这些捆绑在一起的一类物品看成一个新物品，并且有 1, 2, 4, . . . 份的体积和重量。之后对这些优化后的物品使用 0-1 背包即可。这么做之所以正确是因为，二进制拆分后所得的这些数可以组合成任意一个物品原数量范围内的数。

## 1017:装箱问题

[Problem description](http://bailian.openjudge.cn/practice/1017/)

[C++ (Accepted)](https://github.com/Heliovic/OpenJudge_Bailian/blob/master/1017/main.cpp)

### 解题思路

模拟 + 贪心。

1. 对于 6 * 6 的产品数量 cnt6，ans 直接加 cnt6 即可，不会有剩余空间
2. 对于 5 * 5 的产品数量 cnt5，每个大箱子可以装 1 个这种产品。ans 加上 cnt5 后，还会有 11 * cnt5 的空间剩余 cnt5_remain
3. 对于 4 * 4 的产品数量 cnt4，每个大箱子可以装 1 个这种产品。ans 加上 cnt4 后，还会有 20 * cnt4 的空间剩余 cnt4_remain
4. 对于 3 * 3 的产品数量 cnt3，每个大箱子可以装 4 个这种产品，因此 ans 加上 cnt3 / 4 取天棚 (block3_need) 后，还会有 block3_need * 36 - cnt3 * 9 的空间剩余 cnt3_remain
5. 考虑 2 * 2 的产品，首先应放入因 3 * 3 而剩下的空间。若 3 * 3 剩下了 1 个 3 * 3 的空间，则只能装 1 个 2 * 2 的产品，且剩余的空间只能装 1 * 1 的产品，这里全部加到 cnt5_remain 上。同理，若 3 * 3 剩下了 2 个 3 * 3 的空间，则能装 3 个 2 * 2 的产品，且剩余的空间只能装 1 * 1 的产品，也全部加到 cnt5_remain 上。若 3 * 3 剩下了 3 个 3 * 3 的空间，则能装 5 个 2 * 2 的产品，且剩余的空间只能装 1 * 1 的产品，也全部加到 cnt5_remain 上。
6. 若进行以上考虑后，2 * 2 的产品还有剩余，则将其放到 4 * 4 所剩余的空间中，其操作类似 3 * 3 的操作。否则，将 4 * 4 剩余空间都加到 cnt5_remain 上留给 1 * 1。
7. 若进行以上考虑后，2 * 2 的产品还有剩余，则要新开大箱子，并更新 ans，直到剩余 2 * 2 产品装完，剩下的空间都加到 cnt5_remain 上留给 1 * 1。
8. 若 cnt5_remain 的空间足够装入所有 1 * 1， 则直接输出 ans，否则，还要新开大箱子，更新 ans ，直到 1 * 1 能被完全装下。
