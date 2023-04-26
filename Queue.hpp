#pragma once

#include <sstream>
#include <string>

#include "Chain.hpp"

/*
 A template representing queues. A queue supports insertion at one end,
 removal at the other end, and peeking at the end where items are removed.
 */
template <typename T>
class Queue {
    
protected:
    
    /*
     The chain that powers this queue. Note: in this implementation,
     the head of the queue is identified with the start node of this
     chain, and the tail of the queue is identified with the end node
     of this chain.
     */
    Chain<T>* theQueue;
    
public:
    
    /*
     Constructs an empty queue
     */
    Queue() {
        this->theQueue = new Chain<T>();
    }
    
    /*
     Returns the number of items on this stack.
     */
    int getSize() {
        return this->theQueue->getSize();
    }
    
    /*
     Inserts an element at the tail of the queue.
     */
    void enqueue(T* data) {
        this->theQueue->insertAtEnd(data);
        
    }
    
    /*
     Removes the element at the head of the queue and returns
     its data. This method returns the null pointer if either
     this queue is empty.
     */
    T* dequeue() {
        return this->theQueue->removeFromStart();
    }
    
    /*
     Returns the data at the head of the queue, but does not
     remove that item from the queue.
     */
    T* peek() {
        return this->theQueue->peek(0);
    }
    
    /*
     Returns a string representation of this queue.
     */
    std::string toString() {
        std::ostringstream sout;
        sout << "Queue at " << this << std::endl;
        sout << "Current size: " << this->getSize() << std::endl;
        return sout.str();
    }
    
};

