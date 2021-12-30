#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <stdexcept>
#include <cstring>
#include "Queue.h"

using namespace std;
template <class T>
Queue<T>::Queue(){
	_maxLength = 10;
	_currentLength = 0;
	_firstPosition = 0;
	_data = _allocateArr(_maxLength);
}

template <class T>
Queue<T>::~Queue(){
	printf("Destroying Stack...\n");
	free(_data);
}

template <class T>
void Queue<T>::enqueue(T value){
	_expandStorage();
	_data[_currentLength++] = value;
}

template <class T>
T Queue<T>::dequeue(){
	T val =  peak();
	memmove(_data,_data+1,(_currentLength) * sizeof(T));
	--_currentLength;
	return val;
}

template <class T>
T Queue<T>::peak(){
	if(_currentLength == 0){
		char erroMssg[100];
		sprintf(erroMssg,"Accessing Invalid curlen=%d",_currentLength);
		throw std::invalid_argument(erroMssg);
	}
	else
		return _data[_firstPosition];
}

template <class T>
void Queue<T>::_expandStorage(){
	if(_currentLength < _maxLength) return;
	printf("curlen=%d, maxlen=%d. Expanding storage...\n",_currentLength,_maxLength);	
	_resizeStorage(_maxLength + 10);
}

template <class T>
void Queue<T>::_shrinkStorage(){
	if(_currentLength > _maxLength-20) return;
	printf("curlen=%d, maxlen=%d. Expanding storage...\n",_currentLength,_maxLength);	
	_resizeStorage(_maxLength - 10);
}

template <class T>
void Queue<T>::_resizeStorage(size_t newLength){
	_maxLength = newLength;
	T* newdata = _allocateArr(newLength);
	memcpy(newdata, _data, newLength * sizeof(T));
	free(_data);
	_data = newdata;
}

template <class T>
T* Queue<T>::_allocateArr(size_t maxLength){
	return (T*)malloc(_maxLength * sizeof(T));
}

template <class T>
size_t Queue<T>::size(){
	return _currentLength;
}

template class Queue<short>;
template class Queue<float>;
