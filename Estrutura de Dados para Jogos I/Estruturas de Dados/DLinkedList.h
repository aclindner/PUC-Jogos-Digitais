#ifndef __DLINKEDLIST_H__
#define __DLINKEDLIST_H__

template< class T > class DListNode;
template< class T > class DLinkedList;
template< class T > class DListIterator;

template< class T >
class DListNode {

public:
	DListNode< T > * m_next;
	DListNode< T > * m_previous;
	T m_data;

	DListNode() {
		m_next = 0;
		m_previous = 0;
	}

	void InsertAfter( T p_data ) {

		DListNode< T > * new_node;

		new_node = new DListNode();
		new_node->m_data = p_data;
		new_node->m_previous = this;
		new_node->m_next = this->m_next;

		this->m_next = new_node;
	}

	void InsertBefore( T p_data ) {

		DListNode< T > * new_node;

		new_node = new DListNode();
		new_node->m_data = p_data;
		new_node->m_next = this;
		new_node->m_previous = this->m_previous;

		this->m_previous = new_node;
	}
};

template< class T >
class DLinkedList {

public:
	DListNode< T > * m_head;
	DListNode< T > * m_tail;
	int m_count;

	DLinkedList() {
		m_head = 0;
		m_tail = 0;
		m_count = 0;
	}

	~DLinkedList() {

		DListNode< T > * itr;
		itr = m_head;
		DListNode< T > * next;

		while (itr != 0) {

			next = itr->m_next;
			delete itr;
			itr = mext;
		}
	}

	void Prepend(T p_data) {
		DListNode<T> * new_node;
		new_node = new DListNode < T >;
		new_node->m_data = p_data;
		new_node->m_next = m_head;
		m_head = new_node;

		if (m_tail == 0)
			m_tail = m_head;

		m_count++;
	}

	void Append(T p_data) {

		if (m_head == 0)
		{
			m_head = m_tail = new SListNode< T >();
			m_head->m_data = p_data;
		}
		else
		{
			m_tail->InsertAfter(p_data);
			m_tail = m_tail->m_next;
		}
	}

	void Remove(DListIterator<T> & p_iterator) {

		DListNode<T> * node = m_head;

		if (p_iterator.m_list != this)
			return;

		if (p_iterator.m_node == 0)
			return;

		if (p_iterator.m_node == m_head)
		{
			p_iterator.Forth();
			RemoveHead();
		}
		else if (p_iterator.m_node == m_tail)
		{
			p_iterator.Back();
			RemoveTail();
		}
		else {
			p_iterator.m_node->m_previous->m_next = p_iterator.m_node->m_next;
			p_iterator.m_node->m_next->m_previous = p_iterator.m_node->m_next;
			delete p_iterator.m_node;
			p_iterator.Forth;
		}

		m_count--;
	}

	void RemoveHead() {

		DListNode<T> * node = 0;

		if (m_head != 0)
		{
			node = m_head->m_next;
			delete m_head;
			m_head = node;

			if (m_head == 0)
				m_tail = 0;

			m_count--;
		}
	}

	void RemoveTail() {

		DListNode<T> * node = 0;

		if (m_head != 0)
		{
			node = m_tail->m_previous;
			delete m_tail;
			m_tail = node;

			if (m_tail == 0)
				m_head = 0;

			m_count--;
		}
	}

	DListIterator<T> GetIterator() {
		return DListIterator<T>(this, m_head);
	}
};

template <class T>
class DListIterator {

public:
	DLinkedList<T> * m_list;
	DListNode<T> * m_node;

	DListIterator(DLinkedList<T> * p_list = 0, DListNode<T> * p_node = 0) {

		m_list = p_list;
		m_node = p_node;
	}

	void Start() {

		if (m_list != 0)
			m_node = m_list->m_head;
	}

	void Forth() {

		if (m_node != 0)
			m_node = m_node->m_next;
	}

	void Back() {
		if (m_node != 0)
			m_node = m_node->m_previous;
	}

	T& Item() {
		return m_node->m_data;
	}

	bool Valid() {
		return m_node != 0;
	}
};

#endif