#pragma once

#include <sstream>

#include "Chain.hpp"

/*
 A template that represents stacks. A stack supports insertion and removal at
 one end only, and peeking at that same end.
 */
template <typename T>
class Stack {
    
protected:
    
    /*
     The chain that powers this stack. We identify the first
     node in the chain with the top of the stack.
     */
    Chain<T>* theStack;
    
public:
    
    /*
     Creates an empty stack.
     */
    Stack(){
        this->theStack = new Chain<T>();
    };
    
    /*
     Returns the number of items on this stack.
     */
    int getSize() {
        return this->theStack->getSize();
    }
    
    /*
     Removes the item at the top of the stack, and returns
     its value. This method returns the null pointer if
     either the stack is empty.
     */
    T* pop() {
        // start node is top of the stack, so remove from start
        return theStack->removeFromStart();
    }
    
    /*
     Pushes the specified data onto the top of the stack.
     */
    void push(T* data) {
        // start node is top of the stack, so insert at start
        theStack->insertAtStart(data);
    }
    
    /*
     Returns the value at the top of the stack, but does not
     remove it from the stack.
     */
    T* peek() {
        // start node is top of the stack, so peek at start, which
        // is at position 0
        return theStack->peek(0);
    }
    
    /*
     Returns a string representation of this Stack.
     */
    std::string toString() {
        std::ostringstream sout;
        sout << "Stack at " << this << std::endl;
        sout << "Current size is " << this->getSize() << std::endl;
        return sout.str();
    }
    
};
