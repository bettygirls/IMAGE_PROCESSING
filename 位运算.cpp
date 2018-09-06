

from : https://blog.csdn.net/zouliping123/article/details/8995373
#### 左移运算
x<<y 将x左移y位，将x最左边的y位丢弃，在右边补y个0

#### 右移运算
x >> y。将x右移y位，这需要区分x是有符号数还是无符号数。在x是无符号数时，只需将x的最右边的y位丢弃，在左边补上y个0。
在x是有符号数时，又分为x是正数还是负数。正数时，同无符号数的处理相同；负数时，将将x的最右边的y位丢弃，在左边补上y个1。

#### 计算一个数的二进制中1的个数
通过与初始值为1的标志位进行与判断，判断最低位是否为1
然后将标志位左移，判断次低位是否为1
```
int countOf1(){
    int count =0;
    unsigned int flag =1;
    while(flag){
        if(num & flag){
            count++:
        }
        flag = flag<<1;
    }
    return count;
}

个整数减一，可以得到该整数的最右边的1变为0，这个1右边的0变为1。
对这个整数和整数减一进行与运算，将该整数的最右边的1变为0，其余位保持不变。
直到该整数变为0，进行的与运算的次数即为整数中1的个数。 
int countOf2(int num){
   int count = 0;
   while(num){
       num = num & (num -1);
       count++;
   }
   return count;
}

```
#### 判断要给数是否是2的n次方
一个数是2的n次方，则这个数的最高位是1，其余位是0.
```
bool is2Power(int num){
    boll flag = true;
    num = num & (num -1);
    if(num){
       flag = false;
    }
    return flag;
}

```
#### 整数N经过多少步可以变为整数m
n 和 m的异或结果可以得知两数不同位的个数，再调用计算一个数中1的个数的方法，即可
```
int countChange(int n, int m){
    n = n ^ m;
    return countOf1_2(n);
}
```
#### 获得最大的int值
```
int getMaxInt()
{
   return (1 << 31) -1 ;

}
```
#### 获得最小的int值
int getMinInt()
{ 
   return 1 << 31;
}
#### 获得最大的long值
long getMaxLong(){
    return ((unsigned long) -1) >> 1;
}
#### 判断一个数的奇偶性
最后一位是否为1
```
bool isOdd(int num){
    return num & 1 == 1;
}
```
#### 交换两个数（不借助第三变量）
```
1 
a = a + b;
b = b - a;
a = a - b;

2
a = a ^ b;
b = b ^ a;
a = a ^ b;

3
viod mySwap(int* a, int* b){
(*a)^= (*b) = ^(*a) ^= (*b);
}

```
#### 求一个数的绝对值
将n右移31位，可以获得n的符号， n为正数得到0，n为负数得到-1

```
int myAbs(int n){
    return (n ^ n  >> 31) - (n >> 31);
}

```
#### 求两个数的平均值
```
int getAverage(int m, int n){
    return (m + n) >> 1;
}
求m和n的平均数
	(m ^ n) >> 1 -> 获得m和n两个数中一个数的某些位为1的一半
	m & n -> 获得m和n两个数中都为1的某些位
    
int getAerage(int m, int n){
   return ((m ^ n) >> 1) + (m & n);
}
```
#### 求倒数第m位相关问题
```

int getMthByTail(int n, int m){
    return (n >> (m -1)) & 1;
}

```
