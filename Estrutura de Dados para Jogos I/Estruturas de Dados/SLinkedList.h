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

template <class T>
class SLinkedList {

public:
	SListNode<T> * m_tail;
	SListNode<T> * m_head;
	int m_count;

	SLinkedList() {

		m_tail = 0;
		m_head = 0;
		m_count = 0;
	}

	~SLinkedList() {

		SListNode<T> * itr;
		itr = m_head;
		SListNode<T> * next;

		while (itr != 0) {

			next = itr->m_next;
			delete itr;
			itr = mext;
		}
	}

	void Append(T p_data) {

		if (m_head == 0) {

			m_head = m_tail = new SListNode();
			m_head->m_data = p_data;
		}
		else {

			m_tail->InsertAfter(p_data);
			m_tail = m_tail->m_next;
		}
	}
};

#endif