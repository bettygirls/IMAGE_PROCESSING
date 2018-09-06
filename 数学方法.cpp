#### 最大公约数
```
int gcd(int x, int y){
   if(y ==0) return x;
   if(x <y) return gcd(y,x);
   else  return gcd(y, x%y);
}

//或者 
int gcd(int a, int b) {
return a ==0 ? b : gcd( b%a,a);
}
```
#### 最小公倍数
X 和 Y 的小公倍数 * 最大公约数  = X * Y

#### 负数的二进制  负数在计算机中二进制补码

#### 小数的二进制
```
```
