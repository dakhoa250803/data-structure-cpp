#ifndef __SINGLELINKEDLIST__
#define __SINGLELINKEDLIST__

#include <iostream>

template <class T> struct SingleNode {
	T value;
	SingleNode* next;
	
	~SingleNode(){
		std::cout << "Detroying node: " << value << std::endl;
	}
};

template <class T> class SingleLinkedList {
	public:
		SingleLinkedList();
		~SingleLinkedList();
		void add(T value);
		void insertAt(size_t index, T value);
		void removeAt(size_t index);
		T getAt(size_t index);	
		size_t size();
		void print();
		void forEach(void (*func)(T, size_t, size_t));
		
	private:
		size_t _count;
		SingleNode<T>* _head;
		SingleNode<T>* _getNodeAt(size_t index);
		void _addFirstNode(T value);
};

#endif
