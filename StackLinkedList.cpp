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

}

template <class T>
StackLinkedList<T>::~StackLinkedList(){
	printf("Destroying Stack...\n");
//	free(this->_data);
}

template <class T>
void StackLinkedList<T>::push(T value){

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

	if(this->size() == 0){
		throw std::out_of_range("Stack ");
	}
	return this->getAt(0);
}


template <class T>
size_t StackLinkedList<T>::size(){
	return this->SingleLinkedList<T>::size();
}

template class StackLinkedList<short>;
template class StackLinkedList<float>;
