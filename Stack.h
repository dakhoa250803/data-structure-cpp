#ifndef __STACK__
#define __STACK__


template <class T> class Stack {
	public:
		Stack();
		~Stack();
		void push(T value); // push(1), push(2), push(3)
		T pop(); // pop() => 3, stack: {1, 2}, pop() => 2, stack: {1}
		T peak(); // peak() => 2, stack: {1, 2}
		size_t size();
		
	private:
		size_t _maxLength;
		size_t _currentLength;
		T* _data;
		T* _allocateArr(size_t maxLength);
};

#endif
