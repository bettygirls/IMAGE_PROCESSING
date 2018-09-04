

将一个数组划分为2个部分，保证左右部分最大值的差值最大


3 2 6 5 7 6 1 3 2
3 3 6 6 7 7 7 7 7
7 7 7 7 7 6 3 3 2

方法1： 预处理技术
计算h[i] 和 t[i]
h[i]   arr[0....i] 的最大值
t[i]   arr[i.....N-1]的最大值
左右两侧的最大值相减


3 2 6 5 7 6 1 3 2

方法2：
遍历一次得 max = 7
如果7 作为左边的max出现，让右边的max尽可能小，就是右边包含最后一个数
如果7作为右边的max出现，让左边的max尽可能小，就是左边包含第一个数
7 - 3 = 4
7 - 2 = 5
所以结果是 5

因为：
3 2 6 5 7 6 1 3 2
最后一个数无论如何都会被划分成另一个部分，把最后一个数或者第一个数当成另一部分
会减小这部分max增大的可能性

#include<iostream>
#include<limits.h>
int maxabs1(int *arr, int l){
    int MAX = INT_MIN;
    for(int i =0; i < l; i++){
        MAX = std::max(arr[i], arr[l -1]);
    }
    return MAX - std::min(arr[0], arr[l -1]);
}
