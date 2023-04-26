#pragma once

#include "Chain.hpp"

/*
 A class representing double-ended queues. A deque supports insertion and
 removal at either end, and peek at either end.
 */
template <typename T>
class Deque {
    
protected:
    
    /*
     The chain that powers this deque. The front of the deque is
     identified with the start node of this chain, and the
     back of the deque is identified with the end node of this
     chain.
     */
    Chain<T>* theDeque;
    
public:
    
    /*
     Creates an empty deque
     */
    Deque() {
        this->theDeque = new Chain<T>();
    }
    
    /*
     Returns the number of items on this stack.
     */
    int getSize() {
        return this->theDeque->getSize();
    }
    
    /*
     Pushes the specified data to the front of the deque.
     */
    void pushToFront(T* data) {
        this->theDeque->insertAtStart(data);
    }
    
    /*
     Pushes the specified data to the back of the deque.
     */
    void pushToBack(T* data) {
        this->theDeque->insertAtEnd(data);
    }
    
    /*
     Removes the item at the front of the deque and returns
     its value.
     */
    T* popFromFront() {
        return this->theDeque->removeFromStart();
    }
    
    /*
     Removes the item at the back of the deque and returns
     its value.
     */
    T* popFromBack() {
        return this->theDeque->removeFromEnd();
    }
    
    /*
     Returns the value at the front of the deque, but does
     not remove it from the deque.
     */
    T* peekAtFront() {
        return this->theDeque->peek(0);
    }
    
    /*
     Returns the value at the back of the deque, but does
     not remove it from the deque.
     */
    T* peekAtBack() {
        return this->theDeque->peek(this->getSize() - 1);
    }
    
    /*
     Returns a string representation of this deque.
     */
    std::string toString() {
        std::ostringstream sout;
        sout << "Deque at " << this << std::endl;
        sout << "Current size: " << this->getSize() << std::endl;
        return sout.str();
    }
    
};


