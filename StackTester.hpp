#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "Stack.hpp"
#include "Point2D.hpp"
#include "TestResults.hpp"

class StackTester {
    
public:
    
    /*
     Create an empty stack, test getSize()
     */
    static TestResults* test0() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create an empty stack of ints
        Stack<int>* s = new Stack<int>();
        // getSize should return 0
        pointsPossible++;
        int sz = s->getSize();
        if (sz == 0) {
            pointsEarned++;
        } else {
            sout << "Empty stack reported size of " << sz << ", should have been 0" << std::endl;
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Create a stack, put several items on it, test getSize() and the order
     in which items are popped from the stack
     */
    static TestResults* test1() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // number of items to put on the stack
        int numItems = 4;
        // create an empty stack of Point2D
        Stack<Point2D>* s = new Stack<Point2D>();
        // put some items on the stack
        for (int k = 0; k < numItems; k++) {
            s->push(new Point2D(k,k));
        }
        // test getSize()
        pointsPossible++;
        int sz = s->getSize();
        if (sz == numItems) {
            pointsEarned++;
        } else {
            sout << "getSize() returned " << sz << ", should have been " << numItems << std::endl;
        }
        // Test: Pop items of the stack. They should come off in the reverse order
        // in which they were inserted.
        int count = 0;
        for (int k = numItems - 1; k >= 0; k--) {
            pointsPossible++;
            Point2D* p = s->pop();
            if (p->x == k) {
                pointsEarned++;
            } else {
                sout << "Item " << count << " popped from stack incorrectly" << std::endl;
            }
            count++;
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Test the peek function: load up a stack, peek at an element, check it,
     remove it, repeat.
     */
    static TestResults* test2() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // number of items to put on the stack
        int numItems = 5;
        // create an empty stack of Point2D
        Stack<Point2D>* s = new Stack<Point2D>();
        // put some items on the stack
        for (int k = 0; k < numItems; k++) {
            s->push(new Point2D(k,k));
        }
        // peek at an item, remove it, and repeat
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            // peek
            Point2D* itemK = s->peek();
            // test
            if (itemK->x == numItems - 1 - k) {
                pointsEarned++;
            } else {
                sout << "peek() returned itemK->x = " << itemK->x << ", should have been " << numItems - 1 - k << std::endl;
            }
            // remove
            s->pop();
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Runs all the above tests and reports total points possible and earned.
     */
    static TestResults* runAllTests() {
    int totalPossible = 0;
        int totalEarned = 0;
    
        TestResults* r;
    
        r = test0();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "StackTester::test0():" << std::endl;
        std::cout << r->pointsEarned << " out of " << r->pointsPossible << " points earned" << std::endl;
        if (r->pointsEarned < r->pointsPossible) {
            std::cout << r->comments << std::endl;
        }
        
        r = test1();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "StackTester::test1():" << std::endl;
        std::cout << r->pointsEarned << " out of " << r->pointsPossible << " points earned" << std::endl;
        if (r->pointsEarned < r->pointsPossible) {
            std::cout << r->comments << std::endl;
        }

        r = test2();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "StackTester::test2():" << std::endl;
        std::cout << r->pointsEarned << " out of " << r->pointsPossible << " points earned" << std::endl;
        if (r->pointsEarned < r->pointsPossible) {
            std::cout << r->comments << std::endl;
        }
        
        return new TestResults(totalPossible, totalEarned, "");

    }
    
};

