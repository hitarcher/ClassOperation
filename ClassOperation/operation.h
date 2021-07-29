#pragma once

#include <iostream>
using namespace std;
#include <functional>
#include <vector>
/*************************************************************************************************/

class Operation
{
	//�������Ĭ�Ϲ��캯���͹���
public:
	void setA(double value) { _numberA = value; }
	void setB(double value) { _numberB = value; }

	double _numberA;
	double	_numberB;
	virtual double getResult()//��д
	{
		return 0;
	}
};

class OperationADD :public Operation
{
public:
	double getResult()
	{
		return _numberA + _numberB;
	}
};

class SimpleFactory
{
public:
	Operation * Createoperator(char sign)
	{
		Operation *op = NULL;
		switch (sign)
		{
		case '+':
			op = new OperationADD();
			break;
		default:
			break;
		}
		return op;
	}
};
/*************************************************************************************************/

class Base
{
public:
	virtual void test(int a)//��virtual��ִ�����
	{
		cout << "this is base" << endl;
	}
};

class Ship :public Base
{
public:
	void test(int a)
	{
		cout << "this is Base overwrite function" << endl;
	}
};
/*************************************************************************************************/
class Ex
{
private:
	int val;
public:
	static int y;

	void display()const
	{
		//this->val = 10;//const Ex*this ,���ʽ�����ǿ��޸ĵ���ֵ
	}
	static void fun();
};


/*************************************************************************************************/

//ֻ�ܴ���һ������
class Single
{
private:
	Single();
	static Single *interface;//���������������������е�
public:
	static Single* getinerface();//ֻ��һ������
};
/*************************************************************************************************/



//�����Լ�����Exception 
class myexception : public exception
{
	virtual const char* what() const throw()
	{
		return "My exception happened";
	}
};
/*************************************************************************************************/

class Point
{
private:
	int x;
	int y;
public:
	int getx() const{ return this->x; }
	int gety() const{ return this->y; }

	Point(int x = 0, int y = 0);
	~Point();
	const Point operator +(const Point &rhs);
	//const Point operator +(const Point &lhs, const Point &rhs);//�ƺ�����ͬʱ����
	const Point operator-( const Point &rhs);

	const Point &operator++();
	const Point operator++(int);
};
/*************************************************************************************************/

class A;
class B
{
	friend class A;
public:
	inline void display() { cout << "iamB" << endl; }
};

class A
{
public:
	B b;
};


// std::function<int(int)> add_x(int x)
// {
// 	return [&](int a) { return x + a; };//xΪ��ʱ����
// }
/*************************************************************************************************/

class Filter
{
public:
	Filter(int divisorVal,int a,int b) :
		divisor{ divisorVal },a(a),b(b)
	{}

// 	std::function<bool(int)> getFilter()
// 	{
// 		return [=](int value) {return value % this->divisor == 0; };
// 	}
// 	std::function<bool(int)> getFilter()
// 	{
// 		return [divisor](int value) {return value % divisor == 0; };
// 	}
// 	std::function<int(int, int)>getInt()
// 	{
// 		return[=](int a, int b) {return a + b; };
// 	}
private:
	int divisor;
	int a;
	int b;
};	
// std::function<int(int, int)>getInt()
// {
// 	return[=](int a, int b) {return a + b; };
// }
/*************************************************************************************************/


class Mystring
{
private:
	char *m_data;

public:
	Mystring(char *str =0);
	~Mystring();
	Mystring(const Mystring &rhs);
	Mystring &operator =(const Mystring &rhs);
	const Mystring operator +(const Mystring &rhs);
	const char* data() { return m_data; }
	Mystring & operator +=(const Mystring &rhs);
	const char& operator[](int index);
	bool operator ==(const Mystring &rhs);
	bool operator >(const Mystring &rhs);
	bool operator <(const Mystring &rhs);
};

/*************************************************************************************************/

class Person
{
private:
	string name;
public:
	Person(const string & str) { name = str; }
};

class student :public Person
{
private: 
	int age;
public:
	student(const string &name, int age)
		:Person(name), age(age) {}
};

class Master :public student
{
private:
	int id;
public:
	Master(const string &name, int age, int id)
		:student(name, age), id(id) {}
};

/*************************************************************************************************/
class Bird
{
public:
	virtual void fly() = 0;
};

class WildGossse :public Bird
{
public:
	WildGossse() {}
	~WildGossse() {}

	virtual void fly()
	{
		cout << "WildGosses fly" << endl;
	}

};

class Parrot :public Bird
{
public:
	Parrot() {}
	~Parrot() {}

	virtual void fly()
	{
		cout << "Parrot fly" << endl;
	}

};

class Cage :public Bird
{
private:
	vector<Bird*>vecBird;
public:

};