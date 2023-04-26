
#include <iostream>
#include <sstream>
#include <string>

#include "Map.hpp"
#include "Point2D.hpp"
#include "TestResults.hpp"

class MapTester {
    
public:
    
    /*
     Create an empty map, test isEmpty, getSize, and contains
     */
    static TestResults* test0() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create an empty map
        Map<std::string, int>* m = new Map<std::string, int>();
        // test isEmpty
        pointsPossible++;
        if (m->isEmpty() == true) {
            pointsEarned++;
        } else {
            sout << "isEmpty() returned false on an empty Map" << std::endl;
        }
        // test getSize
        pointsPossible++;
        if (m->getSize() == 0) {
            pointsEarned++;
        } else {
            sout << "getSize() returned a non-zero value on an empty Map" << std::endl;
        }
        // test contains on an empty Map
        pointsPossible++;
        std::string* key = new std::string("Hello!");
        if (m->contains(key) == false) {
            pointsEarned++;
        } else {
            sout << "contains(T*) returned true on an empty Map" << std::endl;
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Create a map with several elements, test isEmpty and getSize
     */
    static TestResults* test1() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        
        // create the map
        int numItems = 4;
        Map<std::string, Point2D>* m = new Map<std::string, Point2D>();
        // load it up
        for (int k = 0; k < numItems; k++) {
            std::ostringstream soutK;
            soutK << "Key " << k << std::endl;
            std::string* keyK = new std::string(soutK.str());
            Point2D* valueK = new Point2D(k,k);
            m->add(keyK, valueK);
        }
        // test isEmpty
        pointsPossible++;
        if (m->isEmpty() == false) {
            pointsEarned++;
        } else {
            sout << "isEmpty() returned true on a non-empty Map" << std::endl;
        }
        // test getSize()
        pointsPossible++;
        int sz = m->getSize();
        if (sz == numItems) {
            pointsEarned++;
        } else {
            sout << "getSize() returned " << sz << ", should have been " << numItems << std::endl;
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Test contains(T*) on a complete map. Check that it returns true on all
     of its keys
     */
    static TestResults* test2() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        
        // create the map, save the keys
        int numItems = 5;
        std::string* keys = new std::string[numItems];
        Map<std::string, Point2D>* m = new Map<std::string, Point2D>();
        for (int k = 0; k < numItems; k++) {
            sout << "Item " << k;
            keys[k] = sout.str();
            sout.str(""); // reset the string stream
            Point2D* valueK = new Point2D(k,k);
            m->add(&keys[k], valueK);
        }
        // contains should return true on each key
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            if (m->contains(&keys[k]) == true) {
                pointsEarned++;
            } else {
                sout << "contains(T*) returned false on a contained key" << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Test contains(T*) on a complete map. Check that it returns false on
     a key that it does not contain.
     */
    static TestResults* test3() {
        std::ostringstream sout, sout2;
        int pointsPossible = 0;
        int pointsEarned = 0;
        
        // create the map, save the keys
        int numItems = 5;
        std::string* keys = new std::string[numItems];
        Map<std::string, Point2D>* m = new Map<std::string, Point2D>();
        for (int k = 0; k < numItems; k++) {
            sout2 << "Item " << k;
            keys[k] = sout2.str();
            sout2.str(""); // reset the string stream
            Point2D* valueK = new Point2D(k,k);
            m->add(&keys[k], valueK);
        }
        // create a new key which points to equivalent data, but is not
        // part of this map
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            sout2 << "Item " << k;
            std::string keyK = sout2.str();
            sout2.str("");
            if (m->contains(&keyK) == false) {
                pointsEarned++;
            } else {
                sout << "contains(T*) returned true on a non-member key" << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Test lookup on every valid key.
     */
    static TestResults* test4() {
        std::ostringstream sout, sout2;
        int pointsPossible = 0;
        int pointsEarned = 0;
        
        // create the map, save the keys
        int numItems = 5;
        std::string* keys = new std::string[numItems];
        Map<std::string, Point2D>* m = new Map<std::string, Point2D>();
        for (int k = 0; k < numItems; k++) {
            sout2 << "Item " << k;
            keys[k] = sout2.str();
            sout2.str(""); // reset the string stream
            Point2D* valueK = new Point2D(k,k);
            m->add(&keys[k], valueK);
        }
        // perform lookup on each key. Check value
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            Point2D* p = m->lookUp(&keys[k]);
            if (p->x == k) {
                pointsEarned++;
            } else {
                sout << "Lookup error on item " << k << std::endl;
            }
        }

        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Test look up on items not in the map.
     */
    static TestResults* test5() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        
        // create the map
        int numItems = 5;
        int numBadKeys = 5;
        Map<std::string, Point2D>* m = new Map<std::string, Point2D>();
        // load it up
        for (int k = 0; k < numItems; k++) {
            std::ostringstream soutK;
            soutK << "Key " << k << std::endl;
            std::string* keyK = new std::string(soutK.str());
            Point2D* valueK = new Point2D(k,k);
            m->add(keyK, valueK);
        }
        // lookup on some bad keys
        for (int k = 0; k < numBadKeys; k++) {
            pointsPossible++;
            std::string* badKeyK = new std::string("bad key");
            Point2D* valueK = m->lookUp(badKeyK);
            if (valueK == nullptr) {
                pointsEarned++;
            } else {
                sout << "lookup(T*) returned non-null value on a bad key" << std::endl;
            }
        }

        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Test remove: build a map, remove items, check their data, check getSize(),
     check isEmpty()
     */
    static TestResults* test6() {
        std::ostringstream sout, sout2;
        int pointsPossible = 0;
        int pointsEarned = 0;
        
        // create the map, save the keys
        int numItems = 5;
        std::string* keys = new std::string[numItems];
        Map<std::string, Point2D>* m = new Map<std::string, Point2D>();
        for (int k = 0; k < numItems; k++) {
            sout2 << "Item " << k;
            keys[k] = sout2.str();
            sout2.str(""); // reset the string stream
            Point2D* valueK = new Point2D(k,k);
            m->add(&keys[k], valueK);
        }
        // remove items in the order they were added; check data, and check
        // size of the resulting map
        int ref = numItems;
        for (int k = 0; k < numItems; k++) {
            // check getSize()
            pointsPossible++;
            int sz = m->getSize();
            if (sz == ref) {
                pointsEarned++;
            } else {
                sout << "getSize() returned " << sz << ", should have been " << ref << std::endl;
            }
            // remove pair associated with kth key
            Point2D* p = m->remove(&keys[k]);
            // check data
            pointsPossible++;
            if (p->x == k) {
                pointsEarned++;
            } else {
                sout << "remove(T*) returned incorrect value for k = " << k << std::endl;
            }
            ref--;
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Test getKeys()
     */
    static TestResults* test7() {
        std::ostringstream sout, sout2;
        int pointsPossible = 0;
        int pointsEarned = 0;
        
        // create the map, save the keys
        int numItems = 5;
        std::string* keys = new std::string[numItems];
        Map<std::string, Point2D>* m = new Map<std::string, Point2D>();
        for (int k = 0; k < numItems; k++) {
            sout2 << "Item " << k;
            keys[k] = sout2.str();
            sout2.str(""); // reset the string stream
            Point2D* valueK = new Point2D(k,k);
            m->add(&keys[k], valueK);
        }
        // get all keys
        std::string** returnedKeys = m->getKeys();
        // check all keys
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            if (returnedKeys[k] == &keys[k]) {
                pointsEarned++;
            } else {
                sout << "getAllKeys() failed on key " << k << std::endl;
            }
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    static TestResults* testXX() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        
        
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

        // test7
        r = test7();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "test" << testNum << " results:" << std::endl;
        testNum++;
        std::cout << r->toString() << std::endl;
        // return details
        return new TestResults(totalPossible, totalEarned, sout.str());

    }
    
};
