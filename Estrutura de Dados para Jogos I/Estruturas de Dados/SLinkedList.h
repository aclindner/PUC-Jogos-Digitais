#ifndef __SLINKEDLIST_H__
#define __SLINKEDLIST_H__

template <class T>
class SListNode {

public:
	T m_data;
	SListNode<T> * m_next;

	SListNode() {
		m_next = 0;
	}

	//Inserir dado Depois do Nó
	void InsertAfter(T p_data) {

		SListNode<T> * new_node;

		new_node = new SListNode();
		new_node->m_data = p_data;
		new_node->m_next = m_next;

		m_next = new_node;

	}


};

#endif