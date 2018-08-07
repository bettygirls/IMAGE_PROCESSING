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
 
