#ifndef __ARRAY_H__
#define __ARRAY_H__

template <class T>
class Array
{

public:
	T* m_array;
	int m_size;
	
	Array( int p_size ) {

		m_array = new T[p_size];
		m_size = p_size;

	}//Fim Construtor

	~Array() {

		if (m_array != 0)
		{
			delete[] m_array;
		}

		m_array = 0; //NULL

	}//Fim Destrutor

	void Resize( int p_size ) {

		T* new_array = new T[p_size];
		int min;

		if ( new_array == 0 )
			return;

		if ( p_size < m_size )
			min = p_size;
		else
			min = m_size;

		for ( int i = 0; i < min; i++ )
			new_array[i] = m_array[i];

		m_size = psize;

		if ( m_array != 0 )
			delete[] m_array;

		m_array = new_array;

	}//Fim Resize( int p_size )

	T& operator[] ( int p_index ) {

		return m_array[p_index];

	}//Fim operator []

	operator T*() {

		return m_array;

	}//Fim operator T*

private:


};

#endif