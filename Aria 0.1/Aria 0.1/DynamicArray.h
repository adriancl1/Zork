#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__

#include <stdio.h>

class String;

template <class TYPE>
class Vector
{
	friend class String;
public:
	Vector <TYPE>()
	{
		num_elements = 0;
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

	void push_back(const TYPE& data)
	{
		if(num_elements == max_capacity){
			max_capacity *= 2;
			Vector<TYPE> temp(this);
			delete[] buffer;
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

	TYPE& operator[](int a)
	{
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

	void pop_back()
	{
		buffer[--num_elements] = NULL;
	}	//popback elimina el ultimo elemento

	void shrink_to_fit(){
		if(max_capacity > num_elements)
		{
			Vector<TYPE> temp(this);
			delete[] buffer;
			max_capacity = num_elements;
			buffer = new TYPE[max_capacity];
			for (unsigned int i = 0; i < max_capacity; i++)
			{
				buffer[i] != NULL ? buffer[i] = temp.buffer[i] : ;
			}
		}
	}
	
	void Clean()
	{
		delete[] this;
		this = new Vector();
	}

	void Remove(const TYPE& to_remove)
	{
		for (unsigned int i = 0; i < num_elements; i++)
		{
			if (buffer[i] == to_remove){ buffer[i] = NULL;  }
		}
		this->shrink_to_fit();
	}


public:
	TYPE* buffer;
private:
	unsigned int num_elements;
	unsigned int max_capacity;
};
#endif