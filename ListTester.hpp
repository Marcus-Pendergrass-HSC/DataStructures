#pragma once

#include <iostream>

#include "Point2D.hpp"
#include "Node.hpp"
#include "Chain.hpp"
#include "List.hpp"
#include "Vertex.hpp"
#include "NodeTester.hpp"
#include "ChainTester.hpp"
#include "TestResults.hpp"

class ListTester {
    
public:
    
    /*
     Create an empty list, and poll its properties
     */
    static TestResults* test0() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create an empty list
        List<float>* l = new List<float>();
        // test isEmpty();
        pointsPossible++;
        if (l->isEmpty()) {
            pointsEarned++;
        } else {
            sout << "isEmpty() returned false on an empty List" << std::endl;
        }
        // test getSize
        pointsPossible++;
        if (l->getSize() == 0) {
            pointsEarned++;
        } else {
            sout << "getSize() returned a non-zero value on an empty List" << std::endl;
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Create a list, split it, check
     */
    static TestResults* test1() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // list size
        int sz = 6;
        // check all valid split positions
        for (int splitPos = 0; splitPos < sz; splitPos++) {
            // create the list
            List<Point2D>* l0 = new List<Point2D>();
            for (int k = 0; k < sz; k++) {
                Point2D* p = new Point2D(k,k);
                l0->insertAtEnd(p);
            }
            // split it
            List<Point2D>* l1 = l0->splitAfter(splitPos);
            // test sizes of pieces
            int sz0 = l0->getSize();
            int sz1 = l1->getSize();
            pointsPossible++;
            if (sz0 == splitPos + 1) {
                pointsEarned++;
            } else {
                sout << "List l0 has incorrect size " << sz0 << " after split" << std::endl;
            }
            pointsPossible++;
            if (sz0 + sz1 == sz) {
                pointsEarned++;
            } else {
                sout << "List l1 has incorrect size " << sz1 << " after split" << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Create two lists, prepend, check.
     */
    static TestResults* test2() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        
        // create the lists
        int sz0 = 3;
        List<Point2D>* l0 = new List<Point2D>();
        for (int k = 0; k < sz0; k++) {
            Point2D* p = new Point2D(k,k);
            l0->insertAtEnd(p);
        }
        int sz1 = 5;
        List<Point2D>* l1 = new List<Point2D>();
        for (int k = 0; k < sz1; k++) {
            Point2D* p = new Point2D(sz0 + k, sz0 + k);
            l1->insertAtEnd(p);
        }
        
        // prepend l0 to l1
        l1->prepend(l0);
        
        // check size of resulting list
        pointsPossible++;
        int sz2 = l1->getSize();
        if (sz2 == sz0 + sz1) {
            pointsEarned++;
        } else {
            sout << "l1->getSize() returned " << sz2 << ", should have returned " << sz0 + sz1 << std::endl;
        }
        
        // check that elements are in correct order
        for (int k = 0; k < sz0 + sz1; k++) {
            pointsPossible++;
            Point2D* p = l1->peek(k);
            if (p->x == k) {
                pointsEarned++;
            } else {
                sout << "peek(" << k << ") returned incorrect value" << std::endl;
            }
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Create two lists, append, then check.
     */
    static TestResults* test3() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        
        // create the lists
        int sz0 = 3;
        List<Point2D>* l0 = new List<Point2D>();
        for (int k = 0; k < sz0; k++) {
            Point2D* p = new Point2D(k,k);
            l0->insertAtEnd(p);
        }
        int sz1 = 5;
        List<Point2D>* l1 = new List<Point2D>();
        for (int k = 0; k < sz1; k++) {
            Point2D* p = new Point2D(sz0 + k, sz0 + k);
            l1->insertAtEnd(p);
        }
        
        // append l1 to l0
        l0->append(l1);
        
        // check size of resulting list
        pointsPossible++;
        int sz2 = l0->getSize();
        if (sz2 == sz0 + sz1) {
            pointsEarned++;
        } else {
            sout << "l0->getSize() returned " << sz2 << ", should have returned " << sz0 + sz1 << std::endl;
        }
        
        // check that elements are in correct order
        for (int k = 0; k < sz0 + sz1; k++) {
            pointsPossible++;
            Point2D* p = l0->peek(k);
            if (p->x == k) {
                pointsEarned++;
            } else {
                sout << "peek(" << k << ") returned incorrect value" << std::endl;
            }
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Test the getIndex method on data the chain contains
     */
    static TestResults* test4() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create data and list
        int listSize = 4;
        List<Point2D>* l = new List<Point2D>();
        Point2D** dataArray = new Point2D*[listSize];
        for (int k = 0; k < listSize; k++) {
            dataArray[k] = new Point2D(k,k);
            l->insertAtEnd(dataArray[k]);
        }
        // verify list contains data
        for (int k = 0; k < listSize; k++) {
            pointsPossible++;
            int ndx = l->getIndex(dataArray[k]);
            if (ndx == k) {
                pointsEarned++;
            } else {
                sout << "contains(T*) returned incorrect index " << ndx << ", should be " << k << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Test the contains method on data the chain does not contain
     */
    static TestResults* test5() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create data and list
        int listSize = 4;
        List<Point2D>* l = new List<Point2D>();
        Point2D** dataArray = new Point2D*[listSize];
        for (int k = 0; k < listSize; k++) {
            dataArray[k] = new Point2D(k,k);
            l->insertAtEnd(dataArray[k]);
        }
        // verify list does NOT contain some data
        for (int k = 0; k < listSize; k++) {
            pointsPossible++;
            Point2D* p = new Point2D(-k-1,-k-1);
            int ndx = l->getIndex(p);
            if (ndx == -1) {
                pointsEarned++;
            } else {
                sout << "contains(T*) returned incorrect index " << ndx << ", should be -1" << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Test a single insertion into a nonempty list
     */
    static TestResults* test6() {
        // for tracking points and comments
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // list size
        int listSize = 8;
        // check insertions at all valid positions
        for (int insertionPosition = 0; insertionPosition < listSize; insertionPosition++) {
            // create the list
            List<long>* l = new List<long>();
            for (int k = 0; k < listSize; k++) {
                long* j = new long(k);
                l->insertAtEnd(j);
            }
            // insert at desired position
            long* j = new long(-99);
            l->insertAtPosition(insertionPosition, j);
            // peek to confirm
            pointsPossible++;
            if (*(l->peek(insertionPosition)) == -99) {
                pointsEarned++;
            } else {
                sout << "insertAtPosition(" << insertionPosition << ") returned an incorrect value" << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Repeatedly test insertAtPosition at the beginning of an initially empty list
     */
    static TestResults* test7() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // how many times to insert
        int numInsertions = 5;
        // create an empty list
        List<float>* l = new List<float>();
        // insert at position 0
        for (int k = 0; k < numInsertions; k++) {
            float* x = new float(k);
            l->insertAtPosition(0, x);
        }
        // peek to confirm
        int val = numInsertions - 1;
        for (int k = 0; k < numInsertions; k++) {
            pointsPossible++;
            if (*(l->peek(k)) == val) {
                pointsEarned++;
            } else {
                sout << "error" << std::endl;
            }
            val--;
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    static TestResults* runAllTests() {
        int totalPossible = 0;
        int totalEarned = 0;
        
        TestResults* r;
        
        r = test0();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;
        
        r = test1();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;
        
        r = test2();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;
        
        r = test3();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;
        
        r = test4();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;
        
        r = test5();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;
        
        r = test6();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;
        
        r = test7();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;
        
        return new TestResults(totalPossible, totalEarned, "");
    }
    
};
