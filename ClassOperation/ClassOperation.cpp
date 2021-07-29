// ClassOperation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "operation.h"
#include "watcher.h"
#include "MyProxy.h"
#include "MyTemplate.h"
#include "Decorate.h"
#include<iostream>
using namespace std;

//流运算符不能成为成员函数<<
ostream &operator<< (ostream &os, const Point &rhs)
{
	os << "(" << rhs.getx() << "," << rhs.gety() << ")";
	return os;
}

std::function<bool(int, int)> wrapper = [](int x, int y) { return x < y; };

int main()
{
	/****************************************************/
	//简单工程模式
	SimpleFactory *sp =new SimpleFactory();
	Operation *op = sp->Createoperator('+');
	op->setA(1);
	op->setB(2);
	
	double i = op->getResult();
	cout << i << endl;
	/****************************************************/
	//代理模式
  	Cheater peter;
	//  Student p = peter;//纯虚类无法实例化
  	Proxy proxy(peter);
  	proxy.takeTest();
	/****************************************************/
	//观察者模式
	Animal *dog = new Dog();
	Animal * cat = new Cat();
	Dog dd;
	Cat cc;
	Trainer *t1 = new Trainer();
	Animal *cat1 = &cc;
	t1->addAn(dog);
	t1->addAn(cat);
	t1->addAn(&dd);//此处可以直接传入子类的指针，和上面，用基类指针指向子类，再传入基类指针，效果类似。	Animal *cat1 = &cc;
	t1->addAn(&cc);
	t1->allAct();
	/****************************************************/
	Base * base = new Ship();
	base->test(2);
	/****************************************************/
	//装饰者模式
	Coffee *cpart1 = new whiteCoffee();
	Coffee *cpart2 = new Milk(cpart1);
	Coffee *cpart3 = new Suger(cpart2);
	cout << cpart3->get_name().c_str() << endl;
	cout<< cpart3->get_cost() << endl;



	/****************************************************/
	//模版测试






	/****************************************************/
	char *_brand;
	_brand = (char*)malloc(sizeof(char) * 20);
	Ex::fun();
	cout << Ex::y << endl;

	Single *s1 = Single::getinerface();

	try
	{
		//throw 1;
		throw "error";
	}
	catch (char *str)
	{
		cout << str << endl;
	}
	catch (int i)
	{
		cout << i << endl;
	}

	myexception myex;
	try
	{
		if (true) //如果，则抛出异常； 
			throw myex;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	try
	{
		int* myarray = new int[100000];
	}
	catch (exception& e)
	{
		cout << "Standard exception: " << e.what() << endl;
	}
	/****************************************************/
	Point p1(1, 1);
	Point p2(2, 3);

	Point p3 = p1 - p2;
	p3++;
	++p3;
	Point p4 = p3 + p1;
	cout << p4 << endl;
	/****************************************************/
	A ca;
	ca.b.display();


	//lambda表达式最前面的方括号的意义,其实这是lambda表达式一个很要的功能，就是闭包。
	// 定义简单的lambda表达式
	auto basicLambda = [] { cout << "Hello, world!" << endl; };
	// 调用
	basicLambda();   // 输出：Hello, world!
	// 指明返回类型
	auto add = [](int a, int b) -> int { return a + b; };
	// 自动推断返回类型
	auto multiply = [](int a, int b) { return a * b; };

	int sum = add(2, 5);   // 输出：7
	int product = multiply(2, 5);  // 输出：10

	int x = 10;

	auto add_x = [x](int a) { return a + x; };  // 复制捕捉x
	auto multiply_x = [&x](int a) { return a * x; };  // 引用捕捉x

	cout << add_x(10) << " " << multiply_x(10) << endl;
	// 输出：20 100


	auto a = [] { cout << "A" << endl; };
	auto b = [] { cout << "B" << endl; };

	//a = b;   // 非法，lambda无法赋值
	auto c = a;   // 合法，生成一个副本


// 	Filter *fp = new Filter(1,2,3);
// 	fp->getInt();

	auto add2 = [=](int a, int b) {return a + b; };
	int ss = add2(1, 2);

	wrapper(1, 2);

	Mystring str1("123");
	Mystring str2(str1);
	Mystring str3("456");
	str2 = str3;
	str3 = str1 + str2;

	Person per1("eric");
	student student1("123", 27);
	Master mm("123", 123, 12);

	while (1);
    return 0;
}

