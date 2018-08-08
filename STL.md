  

## vector
#### 底层结构
数组，支持快速随机访问

#### 应用
避免使用vector<bool>简单的说就是它并未实际保存一个bool, 而是用位域的概念进行了封装.
 
#### 函数
+ 创建：
>>>  无参数，一个空的vector vector<int> vec;  
 
 
>>>  num 和值   初始放入num 个值为val 的vector  vector<int> vec(num,val);  
 
 
>>>  vector(from) 构造一个与 vector from相同的 vector  


>>>  迭代器       构造一个初始值为[start, end) 的vector   vector(iterator start, iterator end);  


+ 运算符： == , != <= ,>= <, >,[]
+ assign 函数 ： 将区间 [start, end) 赋值到当前vector 或者赋值num个val元素到vector中，这个函数会清除为vector赋值以前的内容
+ at 函数：vec.at(i) 有越界检查
+ front 函数 ： 返回起始元素的引用
+ back 函数：vec.back() 返回最末尾一个元素的引用
+ begin函数  vec.begin() 指向起始元素的迭代器
+ capacity 函数： 返回当前vector在重新进行内存分配以前所能容纳的元素数量
+ clear(): 删除当前vector中的所有元素
+ empty() : 
+ end() : 返回指向当前末尾元素的下一个位置的迭代器，如果要访问末尾元素，此迭代器要先自减1
+ erase() : 要么删除指定位置的元素，要么删除区间[start, end) 所有元素，返回值是指向删除的最后的一个呀u盛怒的下一位置的迭代器
+ get_allocator : 返回当前vector 的内存分配器   ？？？？？？
+ insert ：vec.insert(iterator, num, '要插入的元素')
>>>位置loc前插入值为val的元素,返回指向这个元素的迭代器,   


>>>位置loc前插入num个值为val的元素   


>>>位置loc前插入区间[start, end)的所有元素 .   


+ max_size() : 返回当前vector所能容纳的元素数量的最大值（包括可重新分配内存）
+ pop_back() : 删除当前vector最末的一个元素
+ push_back() : 添加元素到当前vector末尾
+ rbegin() : 返回当前vector末尾的逆迭代器（实际指向末尾的下一位置，而其内容为末尾元素的值）
+ rend() : 当前vector起始位置的逆迭代器
+ reverse(size) : 为当前vector预留至少共容纳size个元素的空间，实际空间可能大于size
+ resize(size, val) : 改变当前的vector 大小为size, 新创建的元素赋值val
+ size() : 返回当前vector所容纳元素的数目
+ swap() : 交换当前vector 与vector(&from) 的元素
```
 void swap(int & __restrict a, int & __restrict b)  //int 类型的优化， 使用异或
{  
    a ^= b;  
    b ^= a;  
    a ^= b;  
}  
```

## list
#### 底层结构
双向链表，支持快速增删
#### 应用
#### 函数

#### vector 和 list 的区别
+ 1 vector 可以从后面快速插入与删除，直接访问任何元素，list 双链表，可以从任何地方快速访问与删除
+ 2 vector 适用于随机存取，支持[]，随机存取时间为常数，但是再非末尾删除插入元素效率极低
    list适用于数组中间频繁插入删除数据，其插入删除开销低，但不支持随机存取
+ 3 vector事实上表示的是一块连续的内存，当数据超过数组大小，需要申请新的内存，这时，vector会申请一块足够大的连续内存，把原来数据复制到新的内存，并释放原来vector占用的内存。所谓随机存取，就是可以通过公式直接计算出元素地址的方式，而不需要挨个查找。vector的计算公式类似于  a0+（i-1）*d  （a0为vector地址，i为第i个元素，d为每个元素占用的地址个数。  


    list是双向链式表，在内存中不一定连续。如果要实现随机访问，需要遍历整个数组，在c++标准库模版索性没有提供随机存储（[]操作)。但是链式存储有一个好处，就是在表中间插入和删除元素特别方便。

## string
#### 底层结构
#### 应用
#### 函数

## deque
#### 底层结构
底层数据结构为一个中央控制器和多个缓冲区，支持首尾（中间不能）快速增删，也支持随机访问
deque是一个双端队列(double-ended queue)，也是在堆中保存内容的.  

它的保存形式如下:
[堆1] --> [堆2] -->[堆3] --> ...
每个堆保存好几个元素,然后堆和堆之间有指针指向,看起来像是list和vector的结合品.
#### 应用
#### 函数

## stack
#### 底层结构
用list 或 deque实现，封装头部即可，不用vector的原因应该是容量大小有限，扩容耗时
#### 应用
#### 函数

## queue
#### 底层结构
用list 或 deque实现，封装头部即可，不用vector的原因应该是容量大小有限，扩容耗时
#### 应用
#### 函数

##### stack 和 queue 其实是适配器不叫容器， 是对容器的再封装
 
## 优先队列 priority_queue

#### 底层结构
底层数据结构一般为vector为底层容器，堆heap为处理规则来管理底层容器实现，简单来说就是vector实现的heap

#### 应用
操作系统中进程和线程的调度

#### 函数
+ 创建： priority_queue<Elem> a;
+ a.top() 返回队列头部数据
+ a.push(r) 在队列尾部增加r数据
+ a.empty()
+ a.size()

## 堆 heap 

#### 底层结构
heap并不归属于STL容器组件
heap没有迭代器 heap的所有元素都必须遵循特别的（complete binary tree）排列规则，所以heap不提供遍历功能，也不提供迭代器。
#### 应用

#### 函数
+ 创建： make_heap(__first, __last, __cmp); 默认建立最大堆， 对于int类型，可以用 greate<int>() 得到最小堆
+ 添加元素： vec.push_back(a); push_heap(vec.begin(), vec.end()); 在容器中添加元素，然后调用 push_heap
+ 删除元素： pop_heap(vec.begin(), vec.end()),vec.pop_back();    先调用pop__heap()再删除容器中的元素
+ 堆排序： sort_heap(vec.begin(), vec.end()); 之后就不是一个合法的堆了？？？？为什么

## -----------------------------------------------------------------------------
底层为红黑树，有序

## set
#### 底层结构
#### 应用
#### 函数

## multiset
#### 底层结构
#### 应用
#### 函数

## map
#### 底层结构
#### 应用
#### 函数

## multimap
#### 底层结构
#### 应用
#### 函数


## --------------------------------------------------------------------------------
底层为hash表 无序

## hash_set
#### 底层结构
#### 应用
#### 函数

## hash_multiset
#### 底层结构
#### 应用
#### 函数

## hash_map
#### 底层结构
#### 应用
#### 函数

## hash_multimap
#### 底层结构
#### 应用
#### 函数
