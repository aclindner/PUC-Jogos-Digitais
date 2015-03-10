#ifndef __ARRAY_H__
#define __ARRAY_H__

template <class T>
class Array
{

public:
	T* m_array;
	int m_size;
	
	Array(int p_size)
	{
		m_array = new T[p_size];
		m_size = p_size;
	}

	~Array()
	{
		if (array != 0)
		{
			delete[] m_array;
		}

		m_array = 0;
	}


private:


};

#endif