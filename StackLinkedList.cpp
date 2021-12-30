#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <stdexcept>
#include <cstring>
#include "StackLinkedList.h"
//#include "ArrayList.h"

using namespace std;

template <class T>
StackLinkedList<T>::StackLinkedList() {
	printf("Initilizing Stack...\n");
//	this->_maxLength = 10;
//	this->_currentLength = 0;
//	this->_data = this->_allocateArr(this->_maxLength);
}

template <class T>
StackLinkedList<T>::~StackLinkedList(){
	printf("Destroying Stack...\n");
//	free(this->_data);
}

template <class T>
void StackLinkedList<T>::push(T value){
//	if(this->_currentLength >= this->_maxLength){
//		printf("curlen=%d, maxlen=%d. Expanding storage...\n", this->_currentLength, this->_maxLength);	
//		this->_maxLength += 10;
//		T* newdata = this->_allocateArr(this->_maxLength);
//		memcpy(newdata,this->_data,this->_currentLength * sizeof(T));
//		free(this->_data);
//		this->_data = newdata;
//	}
//	this->_data[this->_currentLength++] = value;
	this->insertAt(0,value);
}

template <class T>
T StackLinkedList<T>::pop(){
	T val = this->peak();
	this->removeAt(0);
	return val;
}

template <class T>
T StackLinkedList<T>::peak(){
//	if(this->_currentLength == 0){
//		char erroMssg[100];
//		sprintf(erroMssg,"Accessing Invalid curlen=%d",this->_currentLength);
//		throw std::invalid_argument(erroMssg);
//	}
//	else
//		return this->_data[this->_currentLength];
	if(this->size() == 0){
		throw std::out_of_range("Stack ");
	}
	return this->getAt(0);
}

//template <class T>
//void StackLinkedList<T>::_expandStorage(){
//	if(_currentLength < _maxLength) return;
//	printf("curlen=%d, maxlen=%d. Expanding storage...\n",_currentLength,_maxLength);	
//	_resizeStorage(_maxLength + 10);
//}
//
//template <class T>
//void StackLinkedList<T>::_shrinkStorage(){
//	if(_currentLength > _maxLength-20) return;
//	printf("curlen=%d, maxlen=%d. Expanding storage...\n",_currentLength,_maxLength);	
//	_resizeStorage(_maxLength - 10);
//}
//
//template <class T>
//void StackLinkedList<T>::_resizeStorage(size_t newLength){
//	maxLength = newLength;
//	T* newdata = _allocateArr(maxLength);
//	memcpy(newdata, _data, _currentLength * sizeof(T));
//	free(_data);
//	_data = newdata;
//}

//template <class T>
//T* StackLinkedList<T>::_allocateArr(size_t maxLength){
//	return (T*)malloc(this->_maxLength * sizeof(T));
//}
//
//template <class T>
//size_t StackLinkedList<T>::size(){
//	return this->_currentLength;
//}

template class StackLinkedList<short>;
template class StackLinkedList<float>;
