#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <stdexcept>
#include <cstring>
#include "SingleLinkedList.h"


using namespace std;

template <class T>
SingleLinkedList<T>::SingleLinkedList(){
	_head = NULL;
	_count = 0;
}

template <class T>
SingleLinkedList<T>::~SingleLinkedList(){
	printf("Destroying SingleLinkedList...\n");
	if(!_head) return;
	SingleNode<T>* next;
	for(SingleNode<T>* node = _head; node != NULL; ){
		next = node->next;
		delete node;
		node = next;
	}
}

template <class T>
void SingleLinkedList<T>::add(T value){
//	if(!_head){
//		_addFirstNode(value);
//		return;
//	}
//	SingleNode<T>* lastNode = _getNodeAt(_count - 1);
//	SingleNode<T>* newNode = new SingleNode<T>();
//	newNode->value = value;
//	newNode->next = NULL;
//	lastNode->next = newNode;
//	++_count;
	insertAt(_count, value);
}

template <class T>
void SingleLinkedList<T>::insertAt(size_t index, T value){
	if(!_head){
		_addFirstNode(value);
		return;
	}

	SingleNode<T>* newNode = new SingleNode<T>();
	newNode->value = value;
	if(index == 0){
		newNode->next = _head;
		_head = newNode;
	}
	else{
		SingleNode<T>* curNode = _getNodeAt(index-1);
		newNode->next = curNode->next;
		curNode->next = newNode;
		
	}
	++_count;
}

template <class T>
void SingleLinkedList<T>::removeAt(size_t index){
	if(!_head){
		return;
	}

	SingleNode<T> *curNode, *prevNode;
	if(index == 0){
		curNode = _head;
		_head = _head->next;
	}
	else{
		size_t count = 0;
		for(curNode = _head; curNode != NULL; curNode = curNode->next){
			if(index == count){
				break;
			}
			prevNode = curNode;
			++count;
		}
		prevNode->next = curNode->next;
	}
	delete curNode; 
	--_count;
}

template <class T>
void SingleLinkedList<T>::_addFirstNode(T value){
	_head = new SingleNode<T>();
	_head->value = value;
	_head->next = NULL;
	++_count;
}

template <class T>
T SingleLinkedList<T>::getAt(size_t index){
	SingleNode<T> *node = _getNodeAt(index);
	return node->value;
}

template <class T>	
size_t SingleLinkedList<T>::size(){
//	if(!_head) return 0;
//	size_t count = 0;
//	SingleNode<T>* node = _head;
//	for(SingleNode<T>* node = _head; node != NULL; node = node->next){
//		++count;
//	}
	return _count;
}

//template <class T>
//void SingleLinkedList<T>::print(){
//	if(!_head) return;
//	size_t totalCount = count();
//	size_t i = 0;
//	cout << "{";
//	for(SingleNode<T>* node = _head; node != NULL; node = node->next){
//		cout << (*node).value;
//		cout << (i++ == totalCount-1 ?"": ", ");
//	}
//	cout << "}";
//}

template <class T>
SingleNode<T>* SingleLinkedList<T>::_getNodeAt(size_t index){
	
	size_t count = 0;
	SingleNode<T>* node;
	for(node = _head; node != NULL; node = node->next){
		if(count == index){
			break;
		}
		++count;
	}
	return node;
}

template <class T>
void SingleLinkedList<T>::forEach(void (*func)(T, size_t, size_t)){
	if(!_head) return;
	size_t i = 0;
	for(SingleNode<T>* node = _head; node != NULL; node = (*node).next){
		func(node->value, i, _count);
		++i;
	}
}

template class SingleLinkedList<short>;
template class SingleLinkedList<float>;
