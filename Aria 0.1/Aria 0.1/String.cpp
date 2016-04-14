#include "String.h"
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

String::String()
{

}

String::String(const char* str)
{
	max_capacity = strlen(str) + 1;
	buffer = new char[max_capacity];
	strcpy_s(buffer, max_capacity, str);
	printf("La clase string amb %s se ha construido.\n", buffer);
}

String::String(const String& str)
{
	max_capacity = strlen(str.buffer) + 1;
	buffer = new char[max_capacity];
	strcpy_s(buffer, max_capacity, str.buffer);
	printf("La clase copia string amb %s se ha construido.\n", buffer);
}

String::~String(){
	printf("La clase string amb %s se ha destruido.\n", buffer);

	delete[] buffer;
}

unsigned int String::length()const
{
	return strlen(buffer);
}

char* String::c_str()const
{
	return buffer;
}

bool String::empty()const
{
	return (strlen(buffer) == 0);
}

bool String::operator == (const String& str)const
{
	return(strcmp(buffer, str.buffer) == 0);
}

bool String::operator == (const char* str)const
{
	return(strcmp(buffer, str) == 0);
}

void String::operator += (const String& str)
{

	if (str.length() + length() + 1 > max_capacity)
	{
		max_capacity += str.length();
		char* temp = nullptr;
		temp = new char[max_capacity];
		strcpy_s(temp, max_capacity, buffer);
		delete[] buffer;
		buffer = new char[max_capacity];
		strcat_s(temp, max_capacity, str.buffer);
		buffer = temp;
	}
	else{
		strcat_s(buffer, max_capacity, str.buffer);
	}

}

void String::operator = (const String& str)
{
	if (str.length() + 1 > max_capacity)
	{
		max_capacity = str.length() + 1;
		delete[] buffer;
		buffer = new char[max_capacity];
		strcpy_s(buffer, max_capacity, str.buffer);
	}
	else if (str.length() + 1 <= max_capacity)
	{
		strcpy_s(buffer, str.length() + 1, str.buffer);
	}
}


String String::operator + (const String& str)const
{
	String concat(buffer);
	int len = strlen(str.buffer) + max_capacity;
	concat.buffer = new char[len];
	strcpy_s(concat.buffer, max_capacity, buffer);
	strcat_s(concat.buffer, len, str.buffer);
	return concat;
}

unsigned int String::capacity()const{
	return max_capacity;
}

void String::clean()
{
	strcpy_s(buffer, max_capacity, "");
}

void String::shrink_to_fit()
{
	if (max_capacity > length() + 1){
		max_capacity = length() + 1;
		delete[] buffer;
		buffer = new char[max_capacity];
	}
	else
	{
		printf("The capacity is already the string length\n");
	}
}

Vector<String*> String::Tokenize()
{
	Vector<String*> tokens;
	char* str = buffer;
	unsigned int i=0;
	while (i<this->length()){
		while(*str != ' ' && i<this->length()){
			str++;
			i++;
		}
		str++;
		i++;
		tokens.push_back(new String(str));
	}
	return tokens;
}