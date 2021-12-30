#ifndef __ARRAYLIST__
#define __ARRAYLIST__



template <class T> class ArrayList{
	public:
		
		ArrayList();
		~ArrayList();
		void add(T value);
		void insertAt(size_t index, T value);
		void removeAt(size_t index);
		T getAt(size_t index);	
		size_t size();
		
	protected:
		size_t _maxLength;
		size_t _currentLength;
		T* _data;
		T* _allocateArr(size_t maxLength);
		void _expandStorage();
		void _shrinkStorage();
		void _resizeStorage(size_t newLength);
		void _assertValidInsertIndex(size_t index,const char* funcName);
		void _assertValidAccessIndex(size_t index,const char* funcName);
};

#endif
	

