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

template <class T>
class SListInterator {

public:
	SLinkedList<T> * m_list;
	SListNode<T> * m_node;

	SListInterator(SLinkedList<T> * p_list = 0 , SListNode<T> * p_node = 0) {

		m_list = p_list;
		m_node = p_node;
	}

	void Start() {

		if (m_list != 0) {
			
			m_node = m_list->m_head;
		}
	}

	void Forth() {

		if (m_node != 0) {

			m_node = m_node->m_next;
		}
	}

	T& Item() {
		return m_node->m_data;
	}

	bool Valid() {
		return m_node != 0;
	}
};

#endif