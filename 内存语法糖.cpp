int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, *p = &a[3], b;
	p++;
	b = p[4];
	p[4]--;
	cout << "b: " << b << endl;  //8
-------------------------------------------------------------------------------------------  
  
char x = 0;
class A{
public:
	A() { x = 11; cout << "A() was used. x = 11" << endl; }
	virtual ~A(){ x = 12; cout << "virtual ~A() was used. x = 12 " << endl; }
	void func1(){ x = 13; cout << "funcA1() was used. x = 13"  << endl; }
	void func2(){  cout << "funcA2() was used. x = 14"  << endl; func3(); }
	virtual void func3(){ x = 14; cout << "virtual void funcA3() was used. x = 14 "  << endl; }


};

class B : public A{
public:
	B() { x = 21; cout << "B() was used. x = 21 " << endl; }
	virtual ~B(){ x = 22; cout << "virtual ~B() was used. x = 22"  << endl; }
	void func1(){ x = 23; cout << "funcB1() was used. x =  23"  << endl; }
	void func2(){cout << "funcB2() was used. x =  24"  << endl;  func3();  }
	virtual void func3(){ x = 24; cout << "virtual void funcB3() was used. x = 24"  << endl; }
};


B testb; //对象调用构造函数
B* testc; //指针不会调用构造函数
int main(){
	cout << "1:  " << endl;
	A* testa; //指针是不会调用构造函数的
	cout << "2: " << endl;
	testa = (A*)&testb;  //基类指针指向子类对象+强制类型转换， 没有新对象创建
	cout << "3:  " << endl;
	testa->func1(); // 调用了基类的函数
	cout << "4：  " << endl;
	testc = new B; //创建新的子类对象，会先调用基类的构造函数
	cout << "5： " << endl;
	delete testc; // 先调用子类的析构函数，再调用基类的构造函数
	cout << "6： " << endl;
	testa->func2();  //基类的指针指向了子类对象 ,先调用 A 的funcA2, 因为里面有funcA3是虚函数，所以调用B的实现

	return 0;
}

输出
A() was used. x = 11
B() was used. x = 21
1:
2:
3:
funcA1() was used. x = 13
4：
A() was used. x = 11
B() was used. x = 21
5：
virtual ~B() was used. x = 22
virtual ~A() was used. x = 12
6：
funcA2() was used. x = 14
virtual void funcB3() was used. x = 24
编译器自动析构
virtual ~B() was used. x = 22
virtual ~A() was used. x = 12
------------------------------------------------------------------------------------------------------
class foo{
public:
	static char a[4];
	virtual int func(){};
};
class bar :public foo{
private:
	char *p;
};

char foo::a[4] = { 4, 5, 6, 7 };

int main(){
	
	char *p1 = foo::a + 2; // 6 元素位置
	char *p2 = (char*)(foo::a + 1);  //5元素位置
	char *a = foo::a;  //4 元素位置
	
	cout << "sizeof(foo): " << sizeof(foo) << endl; //4
	cout << "sizeof(bar): " << sizeof(bar) << endl; //8 指针类型只和计算机位数有关，和所指向的数据类型无关
	cout << "foo::a: "  <<  *a << endl;
	cout << "*(foo::a+1): " << *(a + 1) << endl;  //5
	cout << "*p1: " << *p1 << endl;  //6
	cout << "*(p2 - 1): " << (p2 - 1) << endl; //4 元素位置
	cout << "foo::a[p2 - p1]:" << foo::a[4] << endl; //p2 指针和p1 指针相邻，相减为4 a[4] ？？？？？有问题
	return 0;
}
