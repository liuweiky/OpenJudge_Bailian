# OpenJudge_Bailian
🏆北大百练题解

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
