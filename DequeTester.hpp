#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "Deque.hpp"
#include "Point2D.hpp"
#include "TestResults.hpp"

class DequeTester {
    
public:
    
    /*
     Create an empty deque, test getSize()
     */
    static TestResults* test0() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create an empty deque of ints
        Deque<int>* s = new Deque<int>();
        // getSize should return 0
        pointsPossible++;
        int sz = s->getSize();
        if (sz == 0) {
            pointsEarned++;
        } else {
            sout << "Empty deck reported size of " << sz << ", should have been 0" << std::endl;
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Create a deque, push items to the front, test getSize, then pop items
     from the back and check their order.
     */
    static TestResults* test1() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // number of items to put on the deque
        int numItems = 4;
        // create an empty deque of Point2D
        Deque<Point2D>* d = new Deque<Point2D>();
        // put some items on the deque
        for (int k = 0; k < numItems; k++) {
            d->pushToFront(new Point2D(k,k));
        }
        // test getSize()
        pointsPossible++;
        int sz = d->getSize();
        if (sz == numItems) {
            pointsEarned++;
        } else {
            sout << "getSize() returned " << sz << ", should have been " << numItems << std::endl;
        }
        // Test: Pop items from back the deque. They should come off in the same order
        // in which they were inserted.
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            Point2D* p = d->popFromBack();
            if (p->x == k) {
                pointsEarned++;
            } else {
                sout << "Item " << k << " dequeued from stack incorrectly" << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Create a deque, push items to the front, test getSize, then pop items
     from the front and check their order.
     */
    static TestResults* test2() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // number of items to put on the deque
        int numItems = 4;
        // create an empty deque of Point2D
        Deque<Point2D>* d = new Deque<Point2D>();
        // put some items on the deque
        for (int k = 0; k < numItems; k++) {
            d->pushToFront(new Point2D(k,k));
        }
        // test getSize()
        pointsPossible++;
        int sz = d->getSize();
        if (sz == numItems) {
            pointsEarned++;
        } else {
            sout << "getSize() returned " << sz << ", should have been " << numItems << std::endl;
        }
        // Test: Pop items from front the deque. They should come off in the reverse order
        // in which they were inserted.
        int ref = numItems - 1;
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            Point2D* p = d->popFromFront();
            if (p->x == ref) {
                pointsEarned++;
            } else {
                sout << "Item " << k << " popped from front of deque incorrectly" << std::endl;
            }
            ref--;
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Create a deque, push items to the back, test getSize, then pop items
     from the front and check their order.
     */
    static TestResults* test3() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // number of items to put on the deque
        int numItems = 4;
        // create an empty deque of Point2D
        Deque<Point2D>* d = new Deque<Point2D>();
        // put some items on the stack
        for (int k = 0; k < numItems; k++) {
            d->pushToBack(new Point2D(k,k));
        }
        // test getSize()
        pointsPossible++;
        int sz = d->getSize();
        if (sz == numItems) {
            pointsEarned++;
        } else {
            sout << "getSize() returned " << sz << ", should have been " << numItems << std::endl;
        }
        // Test: Pop items from front the deque. They should come off in the same order
        // in which they were inserted.
        int ref = 0;
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            Point2D* p = d->popFromFront();
            if (p->x == ref) {
                pointsEarned++;
            } else {
                sout << "Item " << k << " popped from front of deque incorrectly" << std::endl;
            }
            ref++;
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Create a deque, push items to the back, test getSize, then pop items
     from the back and check their order.
     */
    static TestResults* test4() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // number of items to put on the deque
        int numItems = 4;
        // create an empty deque of Point2D
        Deque<Point2D>* d = new Deque<Point2D>();
        // put some items on the stack
        for (int k = 0; k < numItems; k++) {
            d->pushToBack(new Point2D(k,k));
        }
        // test getSize()
        pointsPossible++;
        int sz = d->getSize();
        if (sz == numItems) {
            pointsEarned++;
        } else {
            sout << "getSize() returned " << sz << ", should have been " << numItems << std::endl;
        }
        // Test: Pop items from front the deque. They should come off in the same order
        // in which they were inserted.
        int ref = numItems - 1;
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            Point2D* p = d->popFromBack();
            if (p->x == ref) {
                pointsEarned++;
            } else {
                sout << "Item " << k << " popped from front of deque incorrectly" << std::endl;
            }
            ref--;
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }


    /*
     Test the peek function: push to the back of the deque, peek at the front,
     check, remove from front, repeat
     */
    static TestResults* test5() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // number of items to put on the stack
        int numItems = 5;
        // create an empty stack of Point2D
        Deque<Point2D>* d = new Deque<Point2D>();
        // put some items on the stack
        for (int k = 0; k < numItems; k++) {
            d->pushToBack(new Point2D(k,k));
        }
        // peek at an item, remove it, and repeat
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            // peek
            Point2D* itemK = d->peekAtFront();
            // test
            if (itemK->x == k) {
                pointsEarned++;
            } else {
                sout << "peek() returned itemK->x = " << itemK->x << ", should have been " << k << std::endl;
            }
            // remove
            d->popFromFront();
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Test the peek function: push to the back of the deque, peek at the back,
     check, remove from back, repeat
     */
    static TestResults* test6() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // number of items to put on the stack
        int numItems = 5;
        // create an empty stack of Point2D
        Deque<Point2D>* d = new Deque<Point2D>();
        // put some items on the stack
        for (int k = 0; k < numItems; k++) {
            d->pushToBack(new Point2D(k,k));
        }
        // peek at an item, remove it, and repeat
        int ref = numItems - 1;
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            // peek
            Point2D* itemK = d->peekAtBack();
            // test
            if (itemK->x == ref) {
                pointsEarned++;
            } else {
                sout << "peek() returned itemK->x = " << itemK->x << ", should have been " << k << std::endl;
            }
            ref--;
            // remove
            d->popFromBack();
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Test the peek function: push to the front of the deque, peek at the back,
     check, remove from back, repeat
     */
    static TestResults* test7() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // number of items to put on the stack
        int numItems = 5;
        // create an empty stack of Point2D
        Deque<Point2D>* d = new Deque<Point2D>();
        // put some items on the stack
        for (int k = 0; k < numItems; k++) {
            d->pushToFront(new Point2D(k,k));
        }
        // peek at an item, remove it, and repeat
        int ref = 0;
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            // peek
            Point2D* itemK = d->peekAtBack();
            // test
            if (itemK->x == ref) {
                pointsEarned++;
            } else {
                sout << "peek() returned itemK->x = " << itemK->x << ", should have been " << k << std::endl;
            }
            ref++;
            // remove
            d->popFromBack();
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Test the peek function: push to the front of the deque, peek at the front,
     check, remove from back, repeat
     */
    static TestResults* test8() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // number of items to put on the stack
        int numItems = 5;
        // create an empty stack of Point2D
        Deque<Point2D>* d = new Deque<Point2D>();
        // put some items on the stack
        for (int k = 0; k < numItems; k++) {
            d->pushToFront(new Point2D(k,k));
        }
        // peek at an item, remove it, and repeat
        int ref = numItems - 1;
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            // peek
            Point2D* itemK = d->peekAtFront();
            // test
            if (itemK->x == ref) {
                pointsEarned++;
            } else {
                sout << "peek() returned itemK->x = " << itemK->x << ", should have been " << k << std::endl;
            }
            ref--;
            // remove
            d->popFromFront();
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
        std::cout << "DequeTester::test0():" << std::endl;
        std::cout << r->pointsEarned << " out of " << r->pointsPossible << " points earned" << std::endl;
        if (r->pointsEarned < r->pointsPossible) {
            std::cout << r->comments << std::endl;
        }

        r = test1();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "DequeTester::test1():" << std::endl;
        std::cout << r->pointsEarned << " out of " << r->pointsPossible << " points earned" << std::endl;
        if (r->pointsEarned < r->pointsPossible) {
            std::cout << r->comments << std::endl;
        }

        r = test2();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "DequeTester::test2():" << std::endl;
        std::cout << r->pointsEarned << " out of " << r->pointsPossible << " points earned" << std::endl;
        if (r->pointsEarned < r->pointsPossible) {
            std::cout << r->comments << std::endl;
        }

        r = test3();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "DequeTester::test3():" << std::endl;
        std::cout << r->pointsEarned << " out of " << r->pointsPossible << " points earned" << std::endl;
        if (r->pointsEarned < r->pointsPossible) {
            std::cout << r->comments << std::endl;
        }

        r = test4();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "DequeTester::test4():" << std::endl;
        std::cout << r->pointsEarned << " out of " << r->pointsPossible << " points earned" << std::endl;
        if (r->pointsEarned < r->pointsPossible) {
            std::cout << r->comments << std::endl;
        }

        r = test5();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "DequeTester::test5():" << std::endl;
        std::cout << r->pointsEarned << " out of " << r->pointsPossible << " points earned" << std::endl;
        if (r->pointsEarned < r->pointsPossible) {
            std::cout << r->comments << std::endl;
        }

        r = test6();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "DequeTester::test6():" << std::endl;
        std::cout << r->pointsEarned << " out of " << r->pointsPossible << " points earned" << std::endl;
        if (r->pointsEarned < r->pointsPossible) {
            std::cout << r->comments << std::endl;
        }

        r = test7();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "DequeTester::test7():" << std::endl;
        std::cout << r->pointsEarned << " out of " << r->pointsPossible << " points earned" << std::endl;
        if (r->pointsEarned < r->pointsPossible) {
            std::cout << r->comments << std::endl;
        }

        r = test8();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "DequeTester::test8():" << std::endl;
        std::cout << r->pointsEarned << " out of " << r->pointsPossible << " points earned" << std::endl;
        if (r->pointsEarned < r->pointsPossible) {
            std::cout << r->comments << std::endl;
        }

        return new TestResults(totalPossible, totalEarned, "");

    }

//    static TestResults* testXXX() {
//        std::ostringstream sout;
//        int pointsPossible = 0;
//        int pointsEarned = 0;
//
//        return new TestResults(pointsPossible, pointsEarned, sout.str());
//    }
    
};

