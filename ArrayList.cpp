#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <stdexcept>
#include "ArrayList.h"
#include <cstring>

using namespace std;

template <class T>		
ArrayList<T>::ArrayList(){
	_maxLength = 10;
	_currentLength = 0;
	_data = _allocateArr(_maxLength);
}

template <class T>		
ArrayList<T>::~ArrayList(){
	printf("Destroying ArrayList...\n");
	free(_data);
}

template <class T>
void ArrayList<T>::add(T value){
	_expandStorage();
	_data[_currentLength++] = value;
}

template <class T>
void ArrayList<T>::insertAt(size_t index, T value){
	_assertValidInsertIndex(index,"insertAt");
	T* dest = _data+index+1;
	T* src = _data+index;
	size_t blockSize = (_currentLength-index) * sizeof(T);
	if(blockSize > 0) memmove(dest,src,blockSize);
	++_currentLength;
	*(_data+ index) = value;
	_expandStorage();
}

template <class T>
void ArrayList<T>::removeAt(size_t index){
	_assertValidAccessIndex(index,"removeAt");
	T* dest = _data+index-1;
	T* src = _data+index;
	size_t blockSize = (_currentLength-index) * sizeof(T);
	if(blockSize > 1) memmove(dest,src,blockSize);
    --_currentLength;
    _shrinkStorage();
}

template <class T>
T ArrayList<T>::getAt(size_t index){
	_assertValidAccessIndex(index,"getAt");
	return _data[index];
}

template <class T>
size_t ArrayList<T>::size(){
	return this->_currentLength;
}

template <class T>
void ArrayList<T>::_assertValidAccessIndex(size_t index,const char* funcName){
	if(index >= _currentLength){
		char erroMssg[100];
		sprintf(erroMssg,"In %s: Accessing Invalid index=%d while curlen=%d",funcName,index,_currentLength);
		throw std::invalid_argument(erroMssg);
	}
}

template <class T>
void ArrayList<T>::_assertValidInsertIndex(size_t index,const char* funcName){
	if(index > _currentLength){
		char erroMssg[100];
		sprintf(erroMssg,"In %s: Inserting Invalid index=%d while maxlen=%d",funcName,index,_currentLength);
		throw std::invalid_argument(erroMssg);
	}
}

template <class T>
void ArrayList<T>::_expandStorage(){
	if(_currentLength < _maxLength) return;
	printf("curlen=%d, maxlen=%d. Expanding storage...\n",_currentLength,_maxLength);	
	_resizeStorage(_maxLength + 10);
}

template <class T>
void ArrayList<T>::_shrinkStorage(){
	if(_currentLength > _maxLength-20) return;
	printf("curlen=%d, maxlen=%d. Expanding storage...\n",_currentLength,_maxLength);	
	_resizeStorage(_maxLength - 10);
}

template <class T>
void ArrayList<T>::_resizeStorage(size_t newLength){
	_maxLength = newLength;
	T* newdata = _allocateArr(_maxLength);
	memcpy(newdata, _data, _currentLength * sizeof(T));
	free(_data);
	_data = newdata;
}

template <class T>
T* ArrayList<T>::_allocateArr(size_t maxLength){
	return (T*)malloc(_maxLength * sizeof(T));
}

template class ArrayList<short>;
template class ArrayList<float>;
