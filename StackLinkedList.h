#ifndef __STACK_LIST__
#define __STACK_LIST__

#include "SingleLinkedList.h"
#include "IStack.h"

template <class T> class StackLinkedList :  public SingleLinkedList<T>, public IStack<T> {
	public:
		StackLinkedList();
		~StackLinkedList();
		void push(T value); 
		T pop(); 
		T peak();
		size_t size();
};

#endif
