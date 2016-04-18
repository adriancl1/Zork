#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__

#include <stdio.h>
#include <assert.h>

class String;

template <class TYPE>
class Vector
{
	friend class String;
public:
	Vector <TYPE>()
	{
		max_capacity = 5;
		buffer = new TYPE[max_capacity];

	}
	Vector<TYPE>(const Vector<TYPE>& tocopy)
	{
		num_elements = tocopy.num_elements;
		max_capacity = tocopy.max_capacity;
		buffer = new TYPE[max_capacity];
		for (unsigned int i = 0; i < num_elements; i++){
			buffer[i] = tocopy.buffer[i];
		}
	}
	Vector<TYPE>(const Vector<TYPE>* tocopy)
	{
		num_elements = tocopy->num_elements;
		max_capacity = tocopy->max_capacity;
		buffer = new TYPE[num_elements];
		for (unsigned int i = 0; i < num_elements; i++){
			buffer[i] = tocopy->buffer[i];
		}
	}

	Vector<TYPE>(unsigned int num)
	{
		max_capacity = num;
		buffer = new TYPE[max_capacity];
	}

	void push_back(const TYPE& data)
	{
		if(num_elements == max_capacity){
			max_capacity *= 2;
			Vector<TYPE> temp(this);
			if (num_elements > 0){
				delete[] buffer;
			}
			buffer = new TYPE[max_capacity];
			for (unsigned int i = 0; i < num_elements; i++)
			{
				buffer[i] = temp.buffer[i];
			}
		}
		buffer[num_elements++] = data;
	}


	void push_front(const TYPE& data)
	{
		Vector<TYPE> temp(this);
		unsigned int i;
		if (num_elements < max_capacity)
		{
			for (i = 0; i < num_elements; i++)
			{
				buffer[i + 1] = temp.buffer[i];
			}
		}
		else{
			max_capacity *= 2;
			delete[] buffer;
			buffer = new TYPE[max_capacity];
			for (i = 0; i < num_elements; i++)
			{
				buffer[i + 1] = temp.buffer[i];
			}
		}
		buffer[0] = data;
		num_elements++;
	}

	TYPE operator[](unsigned int a)const
	{
		assert(a < num_elements);
		return buffer[a];
	}

	TYPE& operator[](unsigned int a)
	{
		assert(a < num_elements);
		return buffer[a];
	}

	bool empty()const
	{
		return num_elements == 0;
	}

	unsigned int size()const
	{
		return num_elements;
	}

	unsigned int capacity()const
	{
		return max_capacity;
	}

	bool pop_back(TYPE& value)
	{
		if (num_elements > 0){
			--num_elements;
			value = vector[num_elements];
			return true;
		}
		else{ return false; }
	}

	void shrink_to_fit(){
		if(max_capacity > num_elements)
		{
			Vector<TYPE> temp(this);
			delete[] buffer;
			max_capacity = num_elements;
			buffer = new TYPE[max_capacity];
			for (unsigned int i = 0; i < max_capacity; i++)
			{
				if (buffer[i] != NULL){
					buffer[i] = temp.buffer[i];
				}
			}
		}
	}
	
	void Clean()
	{
		delete[] this;
		this = new Vector();
	}

	void Remove(unsigned int index)
	{
		for (unsigned int i = index; i < num_elements; i++){
			buffer[i] = buffer[i + 1];
		}
		num_elements--;
		this->shrink_to_fit();
	}

	void Clear(){
		num_elements = 0;
	}


public:
	TYPE* buffer;
private:
	unsigned int num_elements = 0;
	unsigned int max_capacity;
};
#endif