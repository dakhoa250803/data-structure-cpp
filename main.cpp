#include <iostream>
#include <stdlib.h>
#include "ArrayList.h"
#include "Stack.h"
#include "Queue.h"
#include "SingleLinkedList.h"
#include "StackArray.h"
#include "StackLinkedList.h"

typedef short data_t;

using namespace std;

void printArray(ArrayList<data_t>* arr);
void printStack(IStack<data_t>* stack);
void printQueue(Queue<data_t>* queue);
void printLinkedList(SingleLinkedList<data_t>* list);
void printNodeValue(data_t val, size_t i, size_t length);
void arrayListExample();
void stackExample();
void queueExample();
void singleLinkedListExample();
void initQueue(Queue<short>* queue);
void initQueue(Queue<float>* queue);
void printValue(short val,size_t size);
void printValue(float val,size_t size);


int main(int argc, char** argv) {
	//arrayListExample();
	stackExample();
	//queueExample();
	//singleLinkedListExample();
	return 0;
}

void arrayListExample(){
	ArrayList<data_t>* arr = new ArrayList<data_t>();
	cout <<"Generating Array ...."<<endl;
	for(short val = 0;val<200;val+=2){
		arr->insertAt(0,val);
	}
	
	cout << "\nYour Array:"<<endl;
	printArray(arr);
	
	cout << "\n\nRemoving element...";
	//arr->removeAt(200);
	for(size_t i = 1;i<60;i+=2){
		arr->removeAt(i);
	}
	printArray(arr);
	
	
	delete arr;
}

void stackExample(){
	cout <<"Generating Array ...."<<endl;
	
	IStack<data_t>* stack = new StackArray<data_t>();
//	IStack<data_t>* stack = new StackLinkedList<data_t>();
	for(data_t val = -50; val <= 50; val+=2){
		stack->push(val);
	}
	
	printStack(stack);
	
	delete stack;
}

void queueExample(){
	cout <<"Generating Array ...."<<endl;
	Queue<data_t>* queue = new Queue<data_t>();
	initQueue(queue);
	printQueue(queue);
	delete queue;
}

void singleLinkedListExample(){
	cout <<"Generating List ...."<<endl;
	SingleLinkedList<data_t>* list = new SingleLinkedList<data_t>();
	for(short val = -50;val <= 50;val += 2){
		list->add(val);
	}
	
	list->insertAt(20,15);
	list->removeAt(3);
	printLinkedList(list);
	
	cout << "Value at 5 = " << list->getAt(5) << endl << endl;
	delete list;
}

void printQueue(Queue<data_t>* queue){
	cout << "\nYour Array:"<<endl;
	cout<<"{";
	while(queue->size() > 0){
		data_t val = queue->dequeue();
		size_t size = queue->size();
		printValue(val, size);
//		printf("%d\n",size);
		cout << (queue->size() == 0 ? "" : ", ") << endl;
	}
	cout << "}";
}

void printStack(IStack<data_t>* stack){
	cout << "\nYour Array:"<<endl;
	cout<<"{";
	while(stack->size() > 0){
		short val = stack ->pop();
		size_t size = stack->size();
		printf("%d/%d,",val,size);
	}
	cout << "}"<<endl;
}

void printArray(ArrayList<data_t>* arr){
	cout<<"{";
	for(size_t i=0,len = arr->size();i<len;++i){
		cout << arr->getAt(i)<<(i == len - 1?"":", ");
	}
	
	cout << "}"<<endl;
}

void printLinkedList(SingleLinkedList<data_t>* list){
	printf("Linked-list (size=%d)",list->size());
	cout<<"{";
	list->forEach(printNodeValue);
	cout << "}"<<endl;
}

//void (*func)(T, size_t)
void printNodeValue(data_t val, size_t i, size_t length){
	cout << val << ", ";
	cout << (i == length - 1 ? "" : ", ");
}

void initQueue(Queue<short>* queue){
	for(short val = -50;val < 50;val += 2){
		queue->enqueue(val);
	}
}

void initQueue(Queue<float>* queue){
	for(float val = -50.543;val < 50.543;val+=2.876){
		queue->enqueue(val);
	}
}

void printValue(short val, size_t size){
	printf("%d/%d", val, size);
}

void printValue(float val, size_t size){
	printf("%9.3f/%d", val, size);
}
