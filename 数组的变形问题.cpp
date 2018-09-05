+ 给定一个非负的数组，代表一个容器，例如数组【0，1，0，2，1，0，1，3，2，1，2，1】
+ 用这个容器接水的话，请问可以接多少水？以这个数组为例可以接6格水。
+ 时间复杂度O(N),额外空间复杂度O(1)

```
思路：
在一个数组中找到最大值和次大值，中间的部分可以求出来，以次大值为瓶颈
左边次大值      最大值               右边次大值
|_______________|_____________________|

位置 .............i................
元素..............5................
     max 10       |           max 20

（1）标准解法：O（N^2）
water[i] = max(  min(max(arr[0......i -1]), max(arr[i+1 .......N-1])),  0)


加速： O(N), 额外空间复杂度O（N）
准备两个辅助数组：
L[i] arr[0....i] 所有数中的最大值
R[i] arr[i....N -1] 所有数中的最大值
arr 1 2 3 6 5 3 4 1
L   1 2 3 6 6 6 6 6
R   6 6 6 6 5 4 4 1

加速2：
L数组变成一个变量，记录左边的max,因为结算顺序是从左到右

加速3：
处在某个位置，不知道（左右）哪个最大值被使用，所以先找到可能的最大值，看哪些位置
可能被算出来
5 4 ............3 7
L                 R
此时4的水量可以确定，因为右边的最大值大于左边的最大值，瓶颈是5
如果左边是8，可以计算3的水量，因为瓶颈是7

4的水量是1，L向右滑动，Lmax = 5, Rmax = 7
5 4 6 .............3 7
  L                  R
6的水量是0， L向右移动，Lmax = 6, Rmax = 7
5 4 6 8 ............3 7
    L                 R
8的水量是0，Lmax = 8 , L向右移动，Rmax = 7
5 4 6 8 2 ...........3 7
        L              r
然后结算3
哪边的max小就结算哪边，因为max小的会成为当前水域的瓶颈

```
```
代码实现：

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int getWater(vector<int> &arr){
	if (arr.empty() || arr.size() < 3){
		return 0;
	}
	int value = 0;
	int leftMax = arr[0];
	int rightMax = arr[arr.size() - 1];

	int l = 1; //左边第二个元素
	int r = arr.size() - 2;//右边的倒数第二个元素
	while (l <= r){
		if (leftMax <= rightMax){  //哪个小就对哪个进行结算
			value += max(0, leftMax - arr[l]);
			leftMax = max(leftMax, arr[l++]);
		}
		else{
			value += max(0, rightMax - arr[r]);
			rightMax = max(rightMax, arr[r--]);
		}
	}
	return value;

}
int main(){
	vector<int> arr = { 0,1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int res = getWater(arr);
	cout << res << endl;
	return 0;
}

```
+ 给定一个数组，数组中的每个值代表一个柱子的高度，柱子的宽度是1，两个柱子之间
+ 可以围成一个面积，规定 面积 = 两根柱子的最小值* 两根柱子之间的距离。比如数组
+ 【3，4，2，5】。 3 和4 之间围成的面积为0， 因为两个柱子是相邻的，中间没有距离，3和
+ 2之间围成的面积为2，因为两个柱子的距离为1，且最短的柱子是2，所以面积为 2 * 1
+ 求在一个数组中，哪两个柱子围成的面积最大，并返回值
+ 实现时间复杂度 O（N）， 额外空间复杂度 O（1）的解法

6...8...................7
6 和 7 的时候，max = 6 * 10 需要6移动因为瓶颈是6
移动到8 的时候需要7 移动， 因为瓶颈是7
```
int maxArea2(vector<int> &arr){
	if (arr.empty() || arr.size() < 3){
		return 0;
	}
	int l = 0; //边界和上面的不一样
	int r = arr.size() - 1;

	int res = INT_MIN;

	while (l < r){ //两个不可以相同
		if (arr[l] < arr[r]){
			res = max(res, (r - l - 1) * arr[l]); 
			l++;//不断更新			
		}
		else{
			res = max(res, (r - l - 1)* arr[r]);
			r--;
		}
	}
	return res;

}
```
