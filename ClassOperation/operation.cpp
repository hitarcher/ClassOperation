#include "stdafx.h"
#include "operation.h"

int Ex::y = 1;
void Ex::fun()
{
	y = 2;//非静态成员引用必须与特定对象相对
}

Single* Single::interface = NULL;

Single::Single()
{
	//if(interface == Null)
	//{
	//	interface =new Single();
	//} 构造函数里不能初始化 static变量
}
Single* Single::getinerface()
{
	if (interface == NULL)
	{
		interface = new Single();
	}
	return interface;
}

Point::Point(int x,int y)
	:x(x),y(y)
{}
Point::~Point() {}

const Point Point::operator+(const Point &rhs)
{
	Point pt;
	pt.x = this->x + rhs.x;
	pt.y = this->y + rhs.y;
	return pt;
}

const Point Point::operator-( const Point &rhs)
{
	Point pt;
	pt.x = this->x - rhs.x;
	pt.y = this->y - rhs.y;
	return pt;
}
const Point & Point::operator++()
{
	this->x++;
	this->y++;

	return *this;
}
const Point  Point::operator++(int)
{
	Point pt = *this;
// 	this->x++;
// 	this->y++;
	++(*this);//简略版本，调用上面刚刚写好的
	return pt;
}

Mystring::Mystring(char* data)
{
	if (data)
	{
		int len = strlen(data);
		this->m_data = new char[len + 1];
		strcpy(m_data,data);
		m_data[len] = '\0';
	}
	else
	{
		this->m_data = new char[1];
		m_data[0] = '\0';
	}
}
Mystring::~Mystring()
{
	if (m_data)
	{
		delete[] m_data;
	}
}
Mystring::Mystring(const Mystring &rhs)
{
	int len = strlen(rhs.m_data);
	this->m_data = new char[len + 1]();
	strcpy(this->m_data, rhs.m_data);
	this->m_data[len] = '\0';
}

 Mystring& Mystring:: operator =(const Mystring &rhs)
{
	 delete []m_data;
	 int len = strlen(rhs.m_data);
	 this->m_data = new char[len + 1];
	 strcpy(m_data, rhs.m_data);
	 m_data[len] = '\0';
	 return *this;
}

 const Mystring Mystring:: operator+(const Mystring &rhs)
 {
	 int len = strlen(rhs.m_data) + strlen(this->m_data);
	 char *tmp = new char[len + 1]();
	 strcpy(tmp, this->m_data);
	 strcat(tmp, rhs.m_data);
	 Mystring st(tmp);
	 delete [] tmp;
	 return st;
 }
 Mystring & Mystring:: operator +=(const Mystring &rhs)
 {
	 *this = *this + rhs;
	 return *this;
 }

 const char& Mystring::operator[](int index)
 {
	 return m_data[index];
 }
 bool Mystring ::operator== (const Mystring &rhs)
 {
	 return strcmp(m_data, rhs.m_data) == 0;
 }

 bool Mystring ::operator> (const Mystring &rhs)
 {
	 return strcmp(m_data, rhs.m_data) > 0;
 }

 bool Mystring ::operator< (const Mystring &rhs)
 {
	 return strcmp(m_data, rhs.m_data) < 0;
 }

