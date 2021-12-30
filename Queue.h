#ifndef __QUEUE__
#define __QUEUE__


template <class T> class Queue {
	public:
		Queue();
		~Queue();
		void enqueue(T value); 
		T dequeue(); 
		T peak(); 
		size_t size();
		
	private:
		size_t _firstPosition;
		size_t _maxLength;
		size_t _currentLength;
		T* _data;
		T* _allocateArr(size_t maxLength);
		void _expandStorage();
		void _shrinkStorage();
		void _resizeStorage(size_t newLength);
};

#endif
