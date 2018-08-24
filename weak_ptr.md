

#### weak_ptr
weak_ptr 是一种不控制所指向对象生存期的智能指针，它指向一个shared_ptr 管理的对象，将一个weak_ptr 绑定到一个shared_ptr ，
不会改变shred_ptr的引用计数，一旦最后一个指向对象的shared_ptr被销毁，对象就会被释放。

创建weak_ptr时，要用一个shred_ptr 来初始化它。
```
auto p = make_shared<int>(42);
weak_ptr<int>wp(p);
wp 和 p 指向相同的对象，由于是弱共享，创建wp不会改变p的引用计数，wp指向的对象可能被释放掉。
```

访问对象的时候不能直接使用weak_ptr，要调用lock.
```
if(shared_ptr<int> np = wp.lock){  //如果np不为空则条件成立
}
只有当lock调用返回true时我们才会进入if语句体，在if中使用np访问共享对象是安全的
```
```
 weak_ptr:
 weak_ptr和shared_ptr的最大区别在于weak_ptr在指向一个对象的时候不会增加其引用计数，
 因此你可以用weak_ptr去指向一个对象并且在weak_ptr仍然指向这个对象的时候析构它，
 此时你再访问weak_ptr的时候，weak_ptr其实返回的会是一个空的shared_ptr。
 
 实际上，通常shared_ptr内部实现的时候维护的就不是一个引用计数，而是两个引用计数，
 一个表示strong reference，也就是用shared_ptr进行复制的时候进行的计数，
 一个是weak reference，也就是用weak_ptr进行复制的时候的计数。
 weak_ptr本身并不会增加strong reference的值，而strong reference降低到0，对象被自动析构。
 
 为什么要采取weak_ptr来解决刚才所述的环状引用的问题呢？
 
 需要注意的是环状引用的本质矛盾是不能通过任何程序设计语言的方式来打破的，为了解决环状引用，第一步首先得打破环，
 也就是得告诉C++，这个环上哪一个引用是最弱的，是可以被打破的，
 因此在一个环上只要把原来的某一个shared_ptr改成weak_ptr，实质上这个环就可以被打破了，
 原有的环状引用带来的无法析构的问题也就随之得到了解决。
 
```
