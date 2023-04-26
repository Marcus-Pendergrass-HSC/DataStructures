#pragma once

#include <iostream>

#include "Pair.hpp"
#include "TestResults.hpp"
#include "Point2D.hpp"

class PairTester {
    
public:
    
    /*
     Use default constructor to create an empty pair. Test the isEmpty() and
     isComplete() methods
     */
    static TestResults* test0() {
        
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        // create an empty pair
        Pair<std::string, Point2D>* p = new Pair<std::string, Point2D>();
        
        pointsPossible++;
        if (p->isEmpty() == true) {
            pointsEarned++;
        } else {
            sout << "Error: isEmpty() returned false on an empty Pair" << std::endl;
        }
        
        pointsPossible++;
        if (p->isComplete() == false) {
            pointsEarned++;
        } else {
            sout << "Error: isComplete() returned true on an empty Pair" << std::endl;
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Create a pair with a first element but not a second.
     Test the isEmpty() and isComplete() methods
     */
    static TestResults* test1() {
        
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        // create a pair with a first element but not a second
        std::string name = "Marcus Pendergrass";
        Pair<std::string, Point2D>* p = new Pair<std::string, Point2D>();
        p->first = &name;
        
        pointsPossible++;
        if (p->isEmpty() == false) {
            pointsEarned++;
        } else {
            sout << "Error: isEmpty() returned true on an non-empty Pair" << std::endl;
        }
        
        pointsPossible++;
        if (p->isComplete() == false) {
            pointsEarned++;
        } else {
            sout << "Error: isComplete() returned true on an non-complete Pair" << std::endl;
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Create a pair with a second element but not a first.
     Test the isEmpty() and isComplete() methods
     */
    static TestResults* test2() {
        
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        // create a pair with a second element but not a first
        Point2D* p2d = new Point2D(-99,-99);
        Pair<std::string, Point2D>* p = new Pair<std::string, Point2D>();
        p->second = p2d;
        
        pointsPossible++;
        if (p->isEmpty() == false) {
            pointsEarned++;
        } else {
            sout << "Error: isEmpty() returned true on an non-empty Pair" << std::endl;
        }
        
        pointsPossible++;
        if (p->isComplete() == false) {
            pointsEarned++;
        } else {
            sout << "Error: isComplete() returned true on an non-complete Pair" << std::endl;
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Create a complete pair.
     Test the isEmpty() and isComplete() methods
     */
    static TestResults* test3() {
        
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        
        // create a pair with a second element but not a first
        std::string name = "Marcus Pendergrass";
        Point2D* p2d = new Point2D(-99,-99);
        Pair<std::string, Point2D>* p = new Pair<std::string, Point2D>();
        p->first = &name;
        p->second = p2d;
        
        pointsPossible++;
        if (p->isEmpty() == false) {
            pointsEarned++;
        } else {
            sout << "Error: isEmpty() returned true on an non-empty Pair" << std::endl;
        }
        
        pointsPossible++;
        if (p->isComplete() == true) {
            pointsEarned++;
        } else {
            sout << "Error: isComplete() returned false on an complete Pair" << std::endl;
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Test the overloading of ==. We've defined two Pairs as being equal under
     comparison if their first and second pointers point to the same memory
     locations.
     
     In this test, we test == when the two Pairs have equal values, but not
     equal memory locations. The comparison should be false.
     */
    static TestResults* test4() {

        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        
        // Pair1
        std::string* name1 = new std::string("Marcus");
        Point2D* p2d1 = new Point2D(1,1);
        Pair<std::string, Point2D>* p1 = new Pair<std::string, Point2D>(name1, p2d1);
        
        // Pair2: data has same values as Pair1, but stored in different locations
        std::string* name2 = new std::string("Marcus");
        Point2D* p2d2 = new Point2D(1,1);
        Pair<std::string, Point2D>* p2 = new Pair<std::string, Point2D>(name2, p2d2);
        
        // comparison should be false
        pointsPossible++;
        if (p1 != p2) {
            pointsEarned++;
        } else {
            sout << "operator== returned true on distinct Pairs" << std::endl;
        }

        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Test the overloading of ==. We've defined two Pairs as being equal under
     comparison if their first and second pointers point to the same memory
     locations.
     
     In this test, we test == when the data members of both pairs point to the
     same locations. The comparison should be true.
     */
    static TestResults* test5() {

        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        
        // Pair1
        std::string* name1 = new std::string("Marcus");
        Point2D* p2d1 = new Point2D(1,1);
        Pair<std::string, Point2D>* p1 = new Pair<std::string, Point2D>(name1, p2d1);
        
        // Pair2: data points to the same values as in p1
        Pair<std::string, Point2D>* p2 = new Pair<std::string, Point2D>(name1, p2d1);
        
        // comparison should be true
        pointsPossible++;
        if (*p1 == *p2) {
            pointsEarned++;
        } else {
            sout << "operator== returned false on identical Pairs" << std::endl;
        }

        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Test the swap function.
     */
    static TestResults* test6() {
        
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        
        // build a Pair
        std::string* name = new std::string("Marcus");
        int* age = new int(60);
        Pair<std::string, int>* thePair = new Pair<std::string, int>(name, age);
        
        // swap it
        Pair<int, std::string>* theSwap = thePair->swap();
        
        // check
        pointsPossible++;
        if (theSwap->first == thePair->second && theSwap->second == thePair->first) {
            pointsEarned++;
        }

        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    static TestResults* runAllTests() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int totalEarned = 0;
        int totalPossible = 0;
        int testNum = 0;
        
        TestResults* r;
        
        // test0
        r = test0();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "test" << testNum << " results:" << std::endl;
        testNum++;
        std::cout << r->toString() << std::endl;

        // test1
        r = test1();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "test" << testNum << " results:" << std::endl;
        testNum++;
        std::cout << r->toString() << std::endl;

        // test2
        r = test2();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "test" << testNum << " results:" << std::endl;
        testNum++;
        std::cout << r->toString() << std::endl;

        // test3
        r = test3();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "test" << testNum << " results:" << std::endl;
        testNum++;
        std::cout << r->toString() << std::endl;

        // test4
        r = test4();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "test" << testNum << " results:" << std::endl;
        testNum++;
        std::cout << r->toString() << std::endl;

        // test5
        r = test5();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "test" << testNum << " results:" << std::endl;
        testNum++;
        std::cout << r->toString() << std::endl;

        // test6
        r = test6();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "test" << testNum << " results:" << std::endl;
        testNum++;
        std::cout << r->toString() << std::endl;
        // return details
        return new TestResults(totalPossible, totalEarned, sout.str());

    }
    

};
