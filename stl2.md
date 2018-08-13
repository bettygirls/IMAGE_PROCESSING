#### queue 和 priority_queue 是容器适配器
queuqe底层实现是dequeue
priority_queue底层实现是 vector 服从 堆的规则

```
容器适配器是对容器的适配，从代码层面来讲，它就是对容器的再封装。
因此，这些容器适配器实际上都是由其他容器的功能实现的。 不难看出， 容器适配器所具有的功能是内部容器功能的子集。
```
所有设计头尾两端外的位置的函数都不在队列的概念内

+ 区别： 队列按照出队和入队的时间排序，优先队列按元素优先级排序

+ 优先队列
>> 按优先级排序，按优先级获取
>> 值得注意的是，不像队列那样，优先队列里的元素没有时间前后之分，所以priority_queue模版类去掉了front和back成员函数，代之以top函数，用以指代下一个出队的优先级最高的元素

####  list 底层实现是双向链表
 >> 具有双向迭代器  
 
 插入和删除是常数时间的，元素访问时线性时间的
 ```
splice：将一个list中的元素 拼接 到另一个list中。 标准文档上给出的解释是“destructively move elements from one list to another”，也就是说两个list对象都会被影响。
merge：合并两个list，效果上像是splice的特例。
remove、remove_if：移除相等的元素、移除满足给定条件的元素。
unique：移除重复的元素，也即使元素唯一。
sort：对list进行排序。
reverse：逆转链表，这个对于双向链表来说非常方便，只要交换一下头尾指针的值就可以了。
 ```
#### forward_list 前向列表 只能从单一方向遍历
没有size()成员函数

+ forward_list是单向链表，内部只维护了单向遍历的信息。 因此，forward_list的迭代器是前向迭代器（forward intertor)。
+ 它们的插入操作也有明显的不同，具体体现在传入的迭代器上：
list::insert：在传入的迭代器之前插入，一个结点的前驱后继都可以获得。
forward_list::insert:在传入的迭代器之后插入，无法获得前驱结点，可以获得后继结点所以只能从后面进行插入，
