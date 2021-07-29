#ifndef MYTEMPLATE_H_
#define MYTEMPLATE_H_
#include <iostream>
using namespace std;

template<typename T>
bool isEqual(T i, T j);

template<typename T>
bool isEqual(T i, T j)
{
	return i == j;
}

template<>//?????
bool isEqual<string>(string s1, string s2);




#endif
