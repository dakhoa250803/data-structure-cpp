#ifndef __STACK_ARR__
#define __STACK_ARR__

#include "ArrayList.h"

template <class T> class StackArray :  public ArrayList<T> {
	public:
		StackArray();
		~StackArray();
		void push(T value); // push(1), push(2), push(3)
		T pop(); // pop() => 3, stack: {1, 2}, pop() => 2, stack: {1}
		T peak(); // peak() => 2, stack: {1, 2}
//		size_t size();
		
	private:
//		size_t _maxLength;
//		size_t _currentLength;
//		T* _data;
//		T* _allocateArr(size_t maxLength);
//		void _expandStorage();
//		void _shrinkStorage();
//		void _resizeStorage(size_t newLength);
		
};

#endif
