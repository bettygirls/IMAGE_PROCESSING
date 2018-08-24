
#### weak_ptr
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
