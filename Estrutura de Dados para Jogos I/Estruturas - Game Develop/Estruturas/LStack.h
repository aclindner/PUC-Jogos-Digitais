#include "DLinkedList.h"

#ifndef __LSTACK_H__
#define __LSTACK_H__

template <class T>
class LStack : public DLinkedList <T> {

public:

	void Push(T p_data) {
		Append(p_data);
	}

	void Pop() {
		RemoveTail();
	}

	T Top() {
		return m_tail->m_data;
	}
};

#endif