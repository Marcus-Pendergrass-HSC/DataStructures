#pragma once

#include <iostream>
#include <sstream>

#include "Chain.hpp"
#include "TestResults.hpp"
#include "Point2D.hpp"

class ChainTester {
    
public:

    /*
     Test default constructor. Test the isEmpty method, the getSize method,
     and check that the links are null in an empty chain.
     */
    static TestResults* test0() {
        
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;

        // create an empty chain of Point2D's
        Chain<Point2D>* c = new Chain<Point2D>();
        
        // test isEmpty
        pointsPossible++;
        if (c->isEmpty() == true) {
            pointsEarned++;
        } else {
            sout << "isEmpty() returned false on an empty chain" << std::endl;
        }
        
        // test getSize
        pointsPossible++;
        if (c->getSize() == 0) {
            pointsEarned++;
        } else {
            sout << "getSize() did not return 0 on an empty chain" << std::endl;
        }
    
        // test startNode link
        pointsPossible++;
        if (c->startNode == nullptr) {
            pointsEarned++;
        } else {
            sout << "c->startNode != nullptr" << std::endl;
        }
    
        // test endNode link
        pointsPossible++;
        if (c->endNode == nullptr) {
            pointsEarned++;
        } else {
            sout << "c->endNode != nullptr" << std::endl;
        }
    
        // test numNodes initialization
        pointsPossible++;
        if (c->numNodes == 0) {
            pointsEarned++;
        } else {
            sout << "c->numNodes != 0" << std::endl;
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Create a chain of length at least 2 and test ordering of nodes.
     */
    static TestResults* test1() {
        
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        
        int numItems = 4;

        // create an empty chain of Point2D's
        Chain<Point2D>* c = new Chain<Point2D>();
        
        // add the desired number of nodes
        for (int k = 0; k < numItems; k++) {
            Point2D* p = new Point2D(k,k);
            c->insertAtEnd(p);
        }
        
        // crawl through the chain, checking to see if the nodes
        // are connected and in the right order
        Node<Point2D>* currentNode = c->startNode;
        int k = 0;
        while (currentNode != nullptr) {
            // test that the nodes are in correct order
            pointsPossible++;
            Point2D* p = currentNode->getData();
            if (p->x == k) {
                pointsEarned++;
            } else {
                sout << "Node " << k << " out of sequence" << std::endl;
            }
            k++;
            currentNode = currentNode->getNextNode();
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Create a chain of length at least 2 using insertAtEnd.
     Then check all of its links.
     */
    static TestResults* test2() {
        
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        
        // chain length
        int numItems = 4;

        // create an empty chain of Point2D's
        Chain<Point2D>* c = new Chain<Point2D>();
        
        // add the desired number of nodes
        for (int k = 0; k < numItems; k++) {
            Point2D* p = new Point2D(k,k);
            c->insertAtEnd(p);
        }
        
        // check all nextNode links
        Node<Point2D>* currentNode = c->startNode;
        for (int k = 0; k < numItems - 1; k++) {
            pointsPossible++;
            if (currentNode->getNextNode() != nullptr) {
                pointsEarned++;
            } else {
                sout << "Node " << k << " should not be nullptr" << std::endl;
            }
            currentNode = currentNode->getNextNode();
        }
        // currentNode is now the last node, which should have no nextNode
        pointsPossible++;
        if (currentNode->getNextNode() == nullptr) {
            pointsEarned++;
        } else {
            sout << "Last node has non-null nextNode attribute" << std::endl;
        }
        
        // check all previousNode links
        for (int k = 0; k < numItems - 1; k++) {
            pointsPossible++;
            if (currentNode->getPreviousNode() != nullptr) {
                pointsEarned++;
            } else {
                sout << "Node " << k << " should not be nullptr" << std::endl;
            }
            currentNode = currentNode->getPreviousNode();
        }
        
        // currentNode is now the first node, which should have no previousNode
        pointsPossible++;
        if (currentNode->getPreviousNode() == nullptr) {
            pointsEarned++;
        } else {
            sout << "First node has non-null previousNode attribute" << std::endl;
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Create a chain of length at least 2 using insertAtStart.
     Then check all of its links.
     */
    static TestResults* test3() {
        
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        
        // chain length
        int numItems = 2;

        // create an empty chain of Point2D's
        Chain<Point2D>* c = new Chain<Point2D>();
        
        // add the desired number of nodes
        for (int k = 0; k < numItems; k++) {
            Point2D* p = new Point2D(k,k);
            c->insertAtStart(p);
        }
        
        // check all nextNode links
        Node<Point2D>* currentNode = c->startNode;
        for (int k = 0; k < numItems - 1; k++) {
            pointsPossible++;
            if (currentNode->getNextNode() != nullptr) {
                pointsEarned++;
            } else {
                sout << "Node " << k << " should not be nullptr" << std::endl;
            }
            currentNode = currentNode->getNextNode();
        }
        // currentNode is now the last node, which should have no nextNode
        pointsPossible++;
        if (currentNode->getNextNode() == nullptr) {
            pointsEarned++;
        } else {
            sout << "Last node has non-null nextNode attribute" << std::endl;
        }
        
        // check all previousNode links
        for (int k = 0; k < numItems - 1; k++) {
            pointsPossible++;
            if (currentNode->getPreviousNode() != nullptr) {
                pointsEarned++;
            } else {
                sout << "Node " << k << " should not be nullptr" << std::endl;
            }
            currentNode = currentNode->getPreviousNode();
        }
        
        // currentNode is now the first node, which should have no previousNode
        pointsPossible++;
        if (currentNode->getPreviousNode() == nullptr) {
            pointsEarned++;
        } else {
            sout << "First node has non-null previousNode attribute" << std::endl;
        }

        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Insert items at start, then remove items at end. Items should be removed
     in the same order as they are inserted.
     */
    static TestResults* test4() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        
        // chain length
        int numItems = 4;

        // create an empty chain of Point2D's
        Chain<Point2D>* c = new Chain<Point2D>();
        
        // add the desired number of nodes
        for (int k = 0; k < numItems; k++) {
            Point2D* p = new Point2D(k,k);
            c->insertAtStart(p);
        }
        
        // remove nodes from the end, check to see if they
        // come off in the right order
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            Point2D* p = c->removeFromEnd();
            if (p->x == k) {
                pointsEarned++;
            } else {
                sout << "Item " << k << " out of order" << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Insert items at start, then remove items from start. Items should be removed
     in the reverse of the order in which they are inserted.
     */
    static TestResults* test5() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        
        // chain length
        int numItems = 4;

        // create an empty chain of Point2D's
        Chain<Point2D>* c = new Chain<Point2D>();
        
        // add the desired number of nodes
        for (int k = 0; k < numItems; k++) {
            Point2D* p = new Point2D(k,k);
            c->insertAtStart(p);
        }
        
        // remove nodes from the end, check to see if they
        // come off in the right order
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            Point2D* p = c->removeFromStart();
            if (p->x == numItems - 1 - k) {
                pointsEarned++;
            } else {
                sout << "Item " << k << " out of order" << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Insert items at end, then remove items from start. Items should be removed
     in the same order as they are inserted.
     */
    static TestResults* test6() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        
        // chain length
        int numItems = 4;

        // create an empty chain of Point2D's
        Chain<Point2D>* c = new Chain<Point2D>();
        
        // add the desired number of nodes
        for (int k = 0; k < numItems; k++) {
            Point2D* p = new Point2D(k,k);
            c->insertAtEnd(p);
        }
        
        // remove nodes from the end, check to see if they
        // come off in the right order
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            Point2D* p = c->removeFromStart();
            if (p->x == k) {
                pointsEarned++;
            } else {
                sout << "Item " << k << " out of order" << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Insert items at end, then remove items from end. Items should be removed
     in the reverse of order in which they are inserted.
     */
    static TestResults* test7() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        
        // chain length
        int numItems = 4;

        // create an empty chain of Point2D's
        Chain<Point2D>* c = new Chain<Point2D>();
        
        // add the desired number of nodes
        for (int k = 0; k < numItems; k++) {
            Point2D* p = new Point2D(k,k);
            c->insertAtEnd(p);
        }
        
        // remove nodes from the end, check to see if they
        // come off in the right order
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            Point2D* p = c->removeFromEnd();
            if (p->x == numItems - 1 - k) {
                pointsEarned++;
            } else {
                sout << "Item " << k << " out of order" << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Test the getSize function.
     */
    static TestResults* test8() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        
        // chain length
        int numItems = 4;

        // create an empty chain of Point2D's
        Chain<Point2D>* c = new Chain<Point2D>();
        
        // add the desired number of nodes
        for (int k = 0; k < numItems; k++) {
            Point2D* p = new Point2D(k,k);
            c->insertAtEnd(p);
        }
        
        // test the getSize method
        pointsPossible++;
        int theSize = c->getSize();
        if (theSize == numItems) {
            pointsEarned++;
        } else {
            sout << "getSize() returned " << theSize << " on a chain of length " << numItems << std::endl;
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Test the toString() method.
     */
    static TestResults* test9() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        
        // test on an empty chain
        pointsPossible++;
        Chain<Point2D>* c0 = new Chain<Point2D>();
        std::string s0 = c0->toString();
        // first line should begin with "Chain at"
        std::size_t pos = s0.find("Chain at");
        if (pos == 0) {
            pointsEarned++;
        } else {
            sout << "First line of toString() output incorrect" << std::endl;
        }
        
        // second line should be "No start node"
        pointsPossible++;
        std::size_t mark = 1 + s0.find("\n");
        pos = s0.find("No start node");
        if (pos == mark) {
            pointsEarned++;
        } else {
            sout << "Second line should be No start node" << std::endl;
        }
        
        // third line should be "No end node"
        pointsPossible++;
        mark = 1 + s0.find("\n", pos+1);
        pos = s0.find("No end node");
        if (pos == mark) {
            pointsEarned++;
        } else {
            sout << "Third line should be No end node" << std::endl;
        }
        
        // test on a chain with multiple nodes
        pointsPossible++;
        // chain length
        int numItems = 4;
        // create an empty chain of Point2D's
        Chain<Point2D>* c1 = new Chain<Point2D>();
        // add the desired number of nodes
        for (int k = 0; k < numItems; k++) {
            Point2D* p = new Point2D(k,k);
            c1->insertAtEnd(p);
        }
        // call toString()
        std::string s1 = c1->toString();
        // first line should begin with "Chain at"
        pos = s1.find("Chain at");
        if (pos == 0) {
            pointsEarned++;
        } else {
            sout << "First line should begin with Chain at" << std::endl;
        }
        
        // second line should be "No start node"
        pointsPossible++;
        mark = 1 + s1.find("\n");
        pos = s1.find("Start node at");
        if (pos == mark) {
            pointsEarned++;
        } else {
            sout << "Second line should be begin with Start data at" << std::endl;
        }
        
        // third line should be "No end node"
        pointsPossible++;
        mark = 1 + s1.find("\n", pos+1);
        pos = s1.find("End node at");
        if (pos == mark) {
            pointsEarned++;
        } else {
            sout << "Third line should begin with End node at" << std::endl;
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Test the peek function.
     */
    static TestResults* test10() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        
        // chain length
        int numItems = 4;

        // create an empty chain of Point2D's
        Chain<Point2D>* c = new Chain<Point2D>();
        
        // add the desired number of nodes at the end of the chain
        for (int k = 0; k < numItems; k++) {
            Point2D* p = new Point2D(k,k);
            c->insertAtEnd(p);
        }
        
        // test the peek function. If we start with the item in position 0,
        // the data in the node should be the same as the position
        for (int k = 0; k < numItems; k++) {
            pointsPossible++;
            Point2D* p = c->peek(k);
            if (p->x == k) {
                pointsEarned++;
            } else {
                sout << "Peek function returned incorrect value on node " << k << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Returns a string representation of this ChainTester.
     */
    std::string toString() {
        return "ChainTester";
    }
};
