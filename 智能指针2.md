+ shared_ptr 允许多个指针指向同一个对象
+ unique_Ptr 独占所指向的对象
+ weak_ptr 是伴随类，是一种弱引用，指向shared_ptr所管理的对象

#### shared_ptr
也是模板类
shared_ptr<string> p1; 默认的智能指针中保存着一个空指针 
shared_ptr<T>p(q); q的计数器加1
p =q;              q的计数器加1，p的计数器减1
share_ptr<int>p3 = make_shared<int>(42);
share_ptr<int>p3 = make_shared<int>( );//初始化为0

解引用智能指针可以返回指向它的对象,可以使用* 和 -> 访问所指向的资源对象的数据和方法
例如：
p->mem   和 （*p）.mem

```
template <typename T>
class SmartPointer{
public:
   //无参数构造函数
    SmartPointer():mPointer(NULL){}
    //有参数构造函数
    SmartPointer(T *p):mPointer(p){
        if(mPointer) mPointer->incRefCount();  //引用计数加1
    }
    //析构函数
    ~ SmartPointer(){
        if(mPointer && mPointer->decRefCount() == 0) delete mPointer;
    }
    //拷贝构造函数
    SmartPointer(const SmartPointer &other):mPointer(other.pointer){
        if(mPointer) mPointer->incRefCount(); //引用计数加1
    }
    //赋值操作符
    SmartPointer &operator=(const SmartPointer &other){
        T *temp(other.mpointer);
        if(temp) temp->incRefCount(); //指向新对象，引用计数加1
        if(mPointer && mPointer->decRefCount() == 0) delete mPointer;   //指向原对象，引用计数值减1，如果减1后引用计数为0，销毁原对象
        //智能指针指向新资源对象
        mPointer = temp;
        return *this;
    }

    // 重载 *
    T& operator* ()const {return *mPointer;}
    //重载 ->
    T* operator ->() const {return mPointer;}

private:
    T *mPointer;
};
```

share_ptr 的拷贝和赋值

当动态对象不再被使用时，shared_ptr 类会自动释放动态对象
对于一块内存，shared_ptr类保证只要有任何shared_ptr对象引用它，它就不会被释放掉



