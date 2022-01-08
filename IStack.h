#ifndef __STACK_INTERFACE__
#define __STACK_INTERFACE__


template <class T> class IStack {
	public:
		virtual void push(T value) = 0;
		virtual T pop() = 0;
		virtual T peak() = 0;
		virtual size_t size() = 0;
};

#endif
