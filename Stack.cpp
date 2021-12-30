#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <stdexcept>
#include <cstring>
#include "Stack.h"

using namespace std;

template <class T>
Stack<T>::Stack(){
	_maxLength = 10;
	_currentLength = 0;
	_data = _allocateArr(_maxLength);
}

template <class T>
Stack<T>::~Stack(){
	printf("Destroying Stack...\n");
	free(_data);
}

template <class T>
void Stack<T>::push(T value){
	if(_currentLength >= _maxLength){
		printf("curlen=%d, maxlen=%d. Expanding storage...\n", _currentLength, _maxLength);	
		_maxLength += 10;
		T* _newdata = _allocateArr(_maxLength);
		memcpy(_newdata,_data,_currentLength * sizeof(T));
		free(_data);
		_data = _newdata;
	}
	_data[_currentLength++] = value;
}

template <class T>
T Stack<T>::pop(){
	T val =  peak();
	--_currentLength;
	return val;
}

template <class T>
T Stack<T>::peak(){
	if(_currentLength == 0){
		char erroMssg[100];
		sprintf(erroMssg,"Accessing Invalid curlen=%d",_currentLength);
		throw std::invalid_argument(erroMssg);
	}
	else
		return _data[_currentLength];
}

template <class T>
T* Stack<T>::_allocateArr(size_t maxLength){
	return (T*)malloc(_maxLength * sizeof(T));
}

template <class T>
size_t Stack<T>::size(){
	return _currentLength;
}

template class Stack<short>;
template class Stack<float>;
