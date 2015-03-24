#include "Array.h"
#include "SLinkedList.h"
#include <iostream>

using namespace std;

template<class T>
void showFromBegin(SListNode<T> * p_node) {
	SListNode<T> * itr = p_node;
	while (itr != 0)
	{
		std::cout << itr->m_data << std::endl;
		itr = itr->m_next;
	}
}

int main()
{
	SListNode<int> * node;
	node = new SListNode<int>();
	node->m_data = 10;

	node->m_next = new SListNode<int>();
	node->m_next->m_data = 20;

	node->m_next->m_next = new SListNode<int>();
	node->m_next->m_next->m_data = 30;

	//Do começo ao Fim
	showFromBegin(node);

	SListNode<char> * node2;
	node2 = new SListNode<char>();
	node2->m_data = 'a';
	node2->InsertAfter('c');
	node2->InsertAfter('b');
	
	//Do começo ao Fim
	showFromBegin(node2);

	SLinkedList<int> * lista = new SLinkedList<int>();

	lista->Append(10);
	lista->Append(20);
	lista->Append(30);

	showFromBegin(lista->m_head);

	lista->Prepend(0);

	showFromBegin(lista->m_head);
	
	system("PAUSE");
	return 0;
}