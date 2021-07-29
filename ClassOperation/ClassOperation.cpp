// ClassOperation.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "operation.h"
#include "watcher.h"
#include "MyProxy.h"
#include "MyTemplate.h"
#include "Decorate.h"
#include<iostream>
using namespace std;

//����������ܳ�Ϊ��Ա����<<
ostream &operator<< (ostream &os, const Point &rhs)
{
	os << "(" << rhs.getx() << "," << rhs.gety() << ")";
	return os;
}

std::function<bool(int, int)> wrapper = [](int x, int y) { return x < y; };

int main()
{
	/****************************************************/
	//�򵥹���ģʽ
	SimpleFactory *sp =new SimpleFactory();
	Operation *op = sp->Createoperator('+');
	op->setA(1);
	op->setB(2);
	
	double i = op->getResult();
	cout << i << endl;
	/****************************************************/
	//����ģʽ
  	Cheater peter;
	//  Student p = peter;//�������޷�ʵ����
  	Proxy proxy(peter);
  	proxy.takeTest();
	/****************************************************/
	//�۲���ģʽ
	Animal *dog = new Dog();
	Animal * cat = new Cat();
	Dog dd;
	Cat cc;
	Trainer *t1 = new Trainer();
	Animal *cat1 = &cc;
	t1->addAn(dog);
	t1->addAn(cat);
	t1->addAn(&dd);//�˴�����ֱ�Ӵ��������ָ�룬�����棬�û���ָ��ָ�����࣬�ٴ������ָ�룬Ч�����ơ�	Animal *cat1 = &cc;
	t1->addAn(&cc);
	t1->allAct();
	/****************************************************/
	Base * base = new Ship();
	base->test(2);
	/****************************************************/
	//װ����ģʽ
	Coffee *cpart1 = new whiteCoffee();
	Coffee *cpart2 = new Milk(cpart1);
	Coffee *cpart3 = new Suger(cpart2);
	cout << cpart3->get_name().c_str() << endl;
	cout<< cpart3->get_cost() << endl;



	/****************************************************/
	//ģ�����






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
		if (true) //��������׳��쳣�� 
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


	//lambda���ʽ��ǰ��ķ����ŵ�����,��ʵ����lambda���ʽһ����Ҫ�Ĺ��ܣ����Ǳհ���
	// ����򵥵�lambda���ʽ
	auto basicLambda = [] { cout << "Hello, world!" << endl; };
	// ����
	basicLambda();   // �����Hello, world!
	// ָ����������
	auto add = [](int a, int b) -> int { return a + b; };
	// �Զ��ƶϷ�������
	auto multiply = [](int a, int b) { return a * b; };

	int sum = add(2, 5);   // �����7
	int product = multiply(2, 5);  // �����10

	int x = 10;

	auto add_x = [x](int a) { return a + x; };  // ���Ʋ�׽x
	auto multiply_x = [&x](int a) { return a * x; };  // ���ò�׽x

	cout << add_x(10) << " " << multiply_x(10) << endl;
	// �����20 100


	auto a = [] { cout << "A" << endl; };
	auto b = [] { cout << "B" << endl; };

	//a = b;   // �Ƿ���lambda�޷���ֵ
	auto c = a;   // �Ϸ�������һ������


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

