#pragma once

#include <iostream>
#include <sstream>

#include "Node.hpp"
#include "Point2D.hpp"

#include "TestResults.hpp"

class NodeTester {
    
public:
    
    /*
     Node test: Create two nodes, hook them up in both directions. See if
     the previousNode and nextNode attributes are set correctly.
     */
    static TestResults* test0() {
        
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        
        // create a node and set its data
        Point2D* p0 = new Point2D(0,0);
        Node<Point2D>* n0 = new Node<Point2D>(p0);
        
        // create another node with data
        Point2D* p1 = new Point2D(1,1);
        Node<Point2D>* n1 = new Node<Point2D>(p1);
        
        // link them up in both directions
        n0->setNextNode(n1);
        n1->setPreviousNode(n0);
        
        // test links
        pointsPossible++;
        if (n0->getPreviousNode() == nullptr) {
            pointsEarned++;
        } else {
            sout << "n0->getPreviousNode() != nullptr" << std::endl;
        }
        
        pointsPossible++;
        if (n0->getNextNode() == n1) {
            pointsEarned++;
        } else {
            sout << "n0->getNextNode() != n1" << std::endl;
        }
        
        pointsPossible++;
        if (n1->getPreviousNode() == n0) {
            pointsEarned++;
        } else {
            sout << "n0->getNextNode() == n1" << std::endl;
        }
        
        pointsPossible++;
        if (n1->getNextNode() == nullptr) {
            pointsEarned++;
        } else {
            sout << "n1->getNextNode() != nullptr" << std::endl;
        }
        
        // call it a day
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Create a chain, test all links.
     */
    static TestResults* test1() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points earned and points possible
        int pointsEarned = 0;
        int pointsPossible = 0;
        
        // chain length
        int numItems = 4;
        // create the chain, providing Point2D data for each node
        Node<Point2D>* startNode = new Node<Point2D>(new Point2D(0,0));
        Node<Point2D>* currentNode = startNode;
        for (int k = 1; k < numItems; k++) {
            Node<Point2D>* nextNode = new Node<Point2D>(new Point2D(k,k));
            currentNode->setNextNode(nextNode);
            nextNode->setPreviousNode(currentNode);
            currentNode = nextNode;
        }
        
        // current node is now at the end node. Save end node for later.
        Node<Point2D>* endNode = currentNode;
        
        // iterate forwards through the chain from the startNode, checking for correct data
        int k = 0;
        currentNode = startNode;
        while (currentNode != nullptr) {
            pointsPossible++;
            Point2D* p = currentNode->getData();
            if (p->x == k) {
                pointsEarned++;
            } else {
                sout << "Data for node " << k << " is not correct" << std::endl;
            }
            currentNode = currentNode->getNextNode();
            k++;
        }
                
        // iterate backwards through the chain from endNode, checking for correct data
        k = numItems - 1;
        currentNode = endNode;
        while (currentNode != nullptr) {
            pointsPossible++;
            Point2D* p = currentNode->getData();
            if (p->x == k) {
                pointsEarned++;
            } else {
                sout << "Data for node " << k << " is not correct" << std::endl;
            }
            currentNode = currentNode->getPreviousNode();
            k--;
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Returns a string representation of this NodeTester
     */
    std::string toString() {
        return "NodeTester";
    }
    
};
