#ifndef __STRING_H__
#define __STRING_H__

#include "DynamicArray.h"

class String
{
private:
	char* buffer = nullptr;
	unsigned int  max_capacity;
public:
	String();
	String(const char* str);
	String(const String& str);
	~String();
	unsigned int length()const;
	char* c_str()const;
	bool empty()const;
	bool operator == (const String& str)const;
	bool String::operator == (const char* str)const;
	void operator += (const String& str);
	void operator =(const String& str);
	String operator + (const String& str)const;
	unsigned int capacity()const;
	void clean();
	void shrink_to_fit();
	Vector<String*>Tokenize();
};

#endif