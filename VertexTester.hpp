#pragma once

#include <iostream>
#include <random>
#include <cmath>

#include "Point2D.hpp"
#include "Node.hpp"
#include "Chain.hpp"
#include "List.hpp"
#include "Map.hpp"
#include "Vertex.hpp"
#include "NodeTester.hpp"
#include "ChainTester.hpp"
#include "TestResults.hpp"

class VertexTester {
    
public:
    
    /*
     Vertex test: create a vertex, store some data in it, retrieve
     it using getData(), and compare retrieved data to stored data.
     */
    static TestResults* test0() {
        TestResults* r;
        Vertex<Point2D>* v = new Vertex<Point2D>();
        Point2D* p = new Point2D(99,99);
        v->setData(p);
        Point2D* q = v->getData();
        if (p == q) {
            r = new TestResults(1, 1, "");
        } else {
            std::string comment = "getData() returned incorrect value";
            r = new TestResults(1, 0, comment);
        }
        return r;
    }

    /*
     Vertex test: create a root vertex and several child nodes. Check
     that child nodes are stored in first in, first out order.
     */
    static TestResults* test1() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create the fan
        int numChildren = 4;
        Vertex<int>* root = new Vertex<int>(new int(-1));
        for (int k = 0; k < numChildren; k++) {
            Vertex<int>* childK = new Vertex<int>(new int(k));
            root->addOutVertex(childK);
        }
        // get the outnodes, check for correct labels
        for (int k = 0; k < numChildren; k++) {
            pointsPossible++;
            Vertex<int>* childK = root->getOutVertex(k);
            int* dta = childK->getData();
            if (*dta == k) {
                pointsEarned++;
            } else {
                sout << "child " << k << " getData() returns " << *dta << ", should be " << k << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Vertex test: create a root vertex and several parent nodes. Check
     that parent nodes are stored in first in, first out order.
     */
    static TestResults* test2() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create the fan
        int numChildren = 4;
        Vertex<int>* root = new Vertex<int>(new int(-1));
        for (int k = 0; k < numChildren; k++) {
            Vertex<int>* childK = new Vertex<int>(new int(k));
            root->addInVertex(childK);
        }
        // get the innodes, check for correct labels
        for (int k = 0; k < numChildren; k++) {
            pointsPossible++;
            Vertex<int>* childK = root->getInVertex(k);
            int* dta = childK->getData();
            if (*dta == k) {
                pointsEarned++;
            } else {
                sout << "child " << k << " getData() returns " << *dta << ", should be " << k << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Vertex test: create a chain with forward links. Crawl through
     checking links.
     */
    static TestResults* test3() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // build the chain
        int chainLength = 4;
        Vertex<Point2D>* startNode = new Vertex<Point2D>(new Point2D(0,0));
        Vertex<Point2D>* currentNode = startNode;
        for (int k = 0; k < chainLength; k++) {
            Vertex<Point2D>* nextNode = new Vertex<Point2D>(new Point2D(k+1,k+1));
            currentNode->addOutVertex(nextNode);
            currentNode = nextNode;
        }
        // crawl through it from the start node, checking labels
        currentNode = startNode;
        int k = 0;
        while(currentNode->getOutDegree() > 0) {
            pointsPossible++;
            Point2D* p = currentNode->getData();
            if (p->x == k) {
                pointsEarned++;
            } else {
                sout << "Node " << k << " has incorrect data" << std::endl;
            }
            k++;
            currentNode = currentNode->getOutVertex(0);
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Vertex test: create a chain with backward links. Crawl through
     checking links.
     */
    static TestResults* test4() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // build the chain
        int chainLength = 4;
        Vertex<Point2D>* endNode = new Vertex<Point2D>(new Point2D(0,0));
        Vertex<Point2D>* currentNode = endNode;
        for (int k = 0; k < chainLength; k++) {
            Vertex<Point2D>* previousNode = new Vertex<Point2D>(new Point2D(k+1,k+1));
            currentNode->addInVertex(previousNode);
            currentNode = previousNode;
        }
        // crawl through it from the end node, checking labels
        currentNode = endNode;
        int k = 0;
        while(currentNode->getInDegree() > 0) {
            pointsPossible++;
            Point2D* p = currentNode->getData();
            if (p->x == k) {
                pointsEarned++;
            } else {
                sout << "Node " << k << " has incorrect data" << std::endl;
            }
            k++;
            currentNode = currentNode->getInVertex(0);
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Create a circle with forward links, crawl through multiple times
     checking labels.
     */
    static TestResults* test5() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points possible and earned
        int pointsPossible = 0;
        int pointsEarned = 0;
        // build the circle
        int numNodes = 4;
        int numCycles = 2;
        Vertex<Point2D>* firstNode = new Vertex<Point2D>(new Point2D(0,0));
        Vertex<Point2D>* currentNode = firstNode;
        for (int k = 1; k < numNodes; k++) {
            Vertex<Point2D>* nextNode = new Vertex<Point2D>(new Point2D(k,k));
            currentNode->addOutVertex(nextNode);
            currentNode = nextNode;
        }
        currentNode->addOutVertex(firstNode);
        //
        currentNode = firstNode;
        for (int k = 0; k < numCycles*numNodes; k++) {
            pointsPossible++;
            Point2D* p = currentNode->getData();
            if (p->x == k % numNodes) {
                pointsEarned++;
            } else {
                sout << "Node " << k << " has incorrect data" << std::endl;
            }
            currentNode = currentNode->getOutVertex(0);
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Create a circle with backward links, crawl through multiple times
     checking labels.
     */
    static TestResults* test6() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points possible and earned
        int pointsPossible = 0;
        int pointsEarned = 0;
        // build the circle
        int numNodes = 4;
        int numCycles = 2;
        Vertex<Point2D>* firstNode = new Vertex<Point2D>(new Point2D(0,0));
        Vertex<Point2D>* currentNode = firstNode;
        for (int k = 1; k < numNodes; k++) {
            Vertex<Point2D>* nextNode = new Vertex<Point2D>(new Point2D(k,k));
            currentNode->addInVertex(nextNode);
            currentNode = nextNode;
        }
        currentNode->addInVertex(firstNode);
        //
        currentNode = firstNode;
        for (int k = 0; k < numCycles*numNodes; k++) {
            pointsPossible++;
            Point2D* p = currentNode->getData();
            if (p->x == k % numNodes) {
                pointsEarned++;
            } else {
                sout << "Node " << k << " has incorrect data" << std::endl;
            }
            currentNode = currentNode->getInVertex(0);
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Make the complete graph on n vertices (n small!) using
     only forward links. Check all links using labels.
     */
    static TestResults* test7() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points possible and earned
        int pointsPossible = 0;
        int pointsEarned = 0;
        // build the complete graph
        int numNodes = 4;
        // create the vertices
        Vertex<Point2D>** vertices = new Vertex<Point2D>*[numNodes];
        for ( int k = 0; k < numNodes; k++) {
            vertices[k] = new Vertex<Point2D>(new Point2D(k,k));
        }
        // hook them up
        for (int k = 0; k < numNodes; k++) {
            for (int j = 0; j < numNodes; j++) {
                if (j != k) {
                    vertices[k]->addOutVertex(vertices[j]);
                }
            }
        }
        // check outdegree of each vertex
        for (int k = 0; k < numNodes; k++) {
            pointsPossible++;
            if (vertices[k]->getOutDegree() == numNodes-1) {
                pointsEarned++;
            } else {
                sout << "Outdegree of vertex " << k << " is incorrect" << std::endl;
            }
        }
        // check that each vertex is connected to all other vertices
        for (int k = 0; k < numNodes; k++) {
            for (int j = 0; j < numNodes-1; j++) {
                pointsPossible++;
                Vertex<Point2D>* neighborJ = vertices[k]->getOutVertex(j);
                Point2D* p = neighborJ->getData();
                if (p->x != k) {
                    pointsEarned++;
                } else {
                    sout << "Vertex " << k << " has an incorrect neighbor" << std::endl;
                }
            }
        }        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Make the complete graph on n vertices (n small!) using
     only backward links. Check all links using labels.
     */
    static TestResults* test8() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points possible and earned
        int pointsPossible = 0;
        int pointsEarned = 0;
        // build the complete graph
        int numNodes = 4;
        // create the vertices
        Vertex<Point2D>** vertices = new Vertex<Point2D>*[numNodes];
        for ( int k = 0; k < numNodes; k++) {
            vertices[k] = new Vertex<Point2D>(new Point2D(k,k));
        }
        // hook them up
        for (int k = 0; k < numNodes; k++) {
            for (int j = 0; j < numNodes; j++) {
                if (j != k) {
                    vertices[k]->addInVertex(vertices[j]);
                }
            }
        }
        // check outdegree of each vertex
        for (int k = 0; k < numNodes; k++) {
            pointsPossible++;
            if (vertices[k]->getInDegree() == numNodes-1) {
                pointsEarned++;
            } else {
                sout << "Outdegree of vertex " << k << " is incorrect" << std::endl;
            }
        }
        // check that each vertex is connected to all other vertices
        for (int k = 0; k < numNodes; k++) {
            for (int j = 0; j < numNodes-1; j++) {
                pointsPossible++;
                Vertex<Point2D>* neighborJ = vertices[k]->getInVertex(j);
                Point2D* p = neighborJ->getData();
                if (p->x != k) {
                    pointsEarned++;
                } else {
                    sout << "Vertex " << k << " has an incorrect neighbor" << std::endl;
                }
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Test removeOutVertex repeatedly.
     */
    static TestResults* test9() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points possible and earned
        int pointsPossible = 0;
        int pointsEarned = 0;
        // build a fan
        int numNodes = 4;
        Vertex<Point2D>* hub = new Vertex<Point2D>(new Point2D(0,0));
        for (int k = 1; k < numNodes; k++) {
            Vertex<Point2D>* spokeK = new Vertex<Point2D>(new Point2D(k,k));
            hub->addOutVertex(spokeK);
        }
        // remove the spokes one at a time. Returned labels should be in
        // increasing order.
        int outDeg = hub->getOutDegree();
        for (int k = 0; k < outDeg; k++) {
            pointsPossible++;
            Point2D* p = hub->removeOutVertex(0);
            if (p->x == k+1) {
                pointsEarned++;
            } else {
                sout << "removeOutVertex(0) returned an incorrect vertex when k = " << k << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     Test removeInVertex repeatedly.
     */
    static TestResults* test10() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points possible and earned
        int pointsPossible = 0;
        int pointsEarned = 0;
        // build a fan
        int numNodes = 4;
        Vertex<Point2D>* hub = new Vertex<Point2D>(new Point2D(0,0));
        for (int k = 1; k < numNodes; k++) {
            Vertex<Point2D>* spokeK = new Vertex<Point2D>(new Point2D(k,k));
            hub->addInVertex(spokeK);
        }
        // remove the spokes one at a time. Returned labels should be in
        // increasing order.
        int inDeg = hub->getInDegree();
        for (int k = 0; k < inDeg; k++) {
            pointsPossible++;
            Point2D* p = hub->removeInVertex(0);
            if (p->x == k+1) {
                pointsEarned++;
            } else {
                sout << "removeInVertex(0) returned an incorrect vertex when k = " << k << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     call removeInVertex once, examine, add the vertex back in , repeat
     */
    static TestResults* test11() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points possible and earned
        int pointsPossible = 0;
        int pointsEarned = 0;
        // number of nodes for the fan
        int numNodes = 5;
        // positionToRemove should be between 0 and numNodes-2 inclusive
        for (int positionToRemove = 0; positionToRemove < numNodes-1; positionToRemove++) {
            // build the fan
            Vertex<Point2D>* hub = new Vertex<Point2D>(new Point2D(-1,-1));
            for (int k = 1; k < numNodes; k++) {
                Vertex<Point2D>* spokeK = new Vertex<Point2D>(new Point2D(k-1,k-1));
                hub->addOutVertex(spokeK);
            }
            // remove and check label
            pointsPossible++;
            Point2D* p = hub->removeOutVertex(positionToRemove);
            if (p->x == positionToRemove) {
                pointsEarned++;
            } else {
                sout << "removeOutVertex(" << positionToRemove << ") failed" << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }

    /*
     call removeOutVertex once, examine, add the vertex back in , repeat
     */
    static TestResults* test12() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points possible and earned
        int pointsPossible = 0;
        int pointsEarned = 0;
        // number of nodes for the fan
        int numNodes = 5;
        // positionToRemove should be between 0 and numNodes-2 inclusive
        for (int positionToRemove = 0; positionToRemove < numNodes-1; positionToRemove++) {
            // build the fan
            Vertex<Point2D>* hub = new Vertex<Point2D>(new Point2D(-1,-1));
            for (int k = 1; k < numNodes; k++) {
                Vertex<Point2D>* spokeK = new Vertex<Point2D>(new Point2D(k-1,k-1));
                hub->addInVertex(spokeK);
            }
            // remove and check label
            pointsPossible++;
            Point2D* p = hub->removeInVertex(positionToRemove);
            if (p->x == positionToRemove) {
                pointsEarned++;
            } else {
                sout << "removeOutVertex(" << positionToRemove << ") failed" << std::endl;
            }
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }



    /*
     Test the getInDegree and getOutDegree functions
     */
    static TestResults* test13() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points possible and earned
        int pointsPossible = 0;
        int pointsEarned = 0;
        // in- and out-degrees
        int inDegree = 3;
        int outDegree = 4;
        // make the center node
        Point2D* p = new Point2D(0,0);
        Vertex<Point2D>* center = new Vertex<Point2D>(p);
        // make the incoming nodes
        for (int k = 0; k < inDegree; k++) {
            p = new Point2D(-k,-k);
            Vertex<Point2D>* v = new Vertex<Point2D>(p);
            center->addInVertex(v);
        }
        // make the outgoing nodes
        for (int k = 0; k < outDegree; k++) {
            p = new Point2D(k,k);
            Vertex<Point2D>* v = new Vertex<Point2D>(p);
            center->addOutVertex(v);
        }
        // check in and out degrees
        pointsPossible++;
        if (center->getInDegree() == inDegree) {
            pointsEarned++;
        } else {
            sout << "Indegree incorrect" << std::endl;
        }
        pointsPossible++;
        if (center->getOutDegree() == outDegree) {
            pointsEarned++;
        } else {
            sout << "Outdegree incorrect" << std::endl;
        }
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Test hasInVertex().
     */
    static TestResults* test14() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points possible and earned
        int pointsPossible = 0;
        int pointsEarned = 0;
        // in- and out-degrees
        int inDegree = 3;
        int outDegree = 4;
        // make the center node
        Point2D* p = new Point2D(0,0);
        Vertex<Point2D>* center = new Vertex<Point2D>(p);
        // make the incoming nodes
        Vertex<Point2D>** incomingVertices = new Vertex<Point2D>*[inDegree];
        for (int k = 0; k < inDegree; k++) {
            p = new Point2D(-k,-k);
            incomingVertices[k] = new Vertex<Point2D>(p);
            center->addInVertex(incomingVertices[k]);
        }
        // make the outgoing nodes
        Vertex<Point2D>** outgoingVertices = new Vertex<Point2D>*[outDegree];
        for (int k = 0; k < outDegree; k++) {
            p = new Point2D(k,k);
            outgoingVertices[k] = new Vertex<Point2D>(p);
            center->addOutVertex(outgoingVertices[k]);
        }
        // check to make sure the center vertex "knows" all of its
        // incoming nodes.
        for (int k = 0; k < inDegree; k++) {
            pointsPossible++;
            if (center->hasInVertex(incomingVertices[k])) {
                pointsEarned++;
            } else {
                sout << "hasInVertex returned false on incoming vertex " << k << std::endl;
            }
        }
        // check to make sure the center vertex "knows" all of its
        // outgoing nodes.
        for (int k = 0; k < outDegree; k++) {
            pointsPossible++;
            if (center->hasOutVertex(outgoingVertices[k])) {
                pointsEarned++;
            } else {
                sout << "hasOutVertex returned false on outgoing vertex " << k << std::endl;
            }
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Create the complete graph on n vertices (no loops), and do a random
     walk in it. On average, all vertices should be visited equally often.
     Do a chi-square test of this null hypothesis.
     */
    static TestResults* test15() {
        // for compiling comments
        std::ostringstream sout;
        // keep track of points possible and earned
        int pointsPossible = 0;
        int pointsEarned = 0;
        // number of nodes for the complete graph
        int numNodes = 5;
        // length of the random walk
        int numSteps = 3*numNodes;
        Vertex<Point2D>** vertices = new Vertex<Point2D>*[numNodes];
        for (int k = 0; k < numNodes; k++) {
            vertices[k] = new Vertex<Point2D>(new Point2D(k,k));
        }
        // hook the vertices up
        for (int k = 0; k < numNodes; k++) {
            for (int j = k+1; j < numNodes; j++) {
                vertices[k]->addOutVertex(vertices[j]);
                vertices[k]->addInVertex(vertices[j]);
                vertices[j]->addOutVertex(vertices[k]);
                vertices[j]->addInVertex(vertices[k]);
            }
        }
        // perform a random walk on the graph and collect stats on the path
        // first, build the random number generator
        std::random_device r;
        std::default_random_engine rng(r());
        std::uniform_int_distribution<int> uniform_dist(0, numNodes-2);
        // walk and collect stats
        int* hist = new int[numNodes];
        int currNdx = 0;
        for (int k = 0; k < numSteps; k++) {
            Vertex<Point2D>* currentVertex = vertices[currNdx];
            int nextNdxNdx = uniform_dist(rng);
            Vertex<Point2D>* nextVertex = currentVertex->getOutVertex(nextNdxNdx);
            currNdx = nextVertex->getData()->x;
            hist[currNdx]++;
        }
//        // for a long walk, if things are working correctly the
//        // empirical distibution should be uniform. Check this
//        // with a chi-square test.
//        int dof = numNodes - 1;
//        // compute chi-square test statistic. If all is well each
//        // vertex should be visited equally often on average.
//        float expectedCount = numSteps/numNodes;
//        float chiSquare = 0;
//        for (int k = 0; k < numNodes; k++) {
//            std::cout << k << ":" << hist[k] << std::endl;
//            chiSquare += (hist[k] - expectedCount)*(hist[k] - expectedCount)/expectedCount;
//        }
//        // compute the P-value
//        double pVal;
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    static TestResults* runAllTests() {
        int totalPossible = 0;
        int totalEarned = 0;
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
        // test8
        r = test8();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "test" << testNum << " results:" << std::endl;
        testNum++;
        std::cout << r->toString() << std::endl;
        // test9
        r = test9();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "test" << testNum << " results:" << std::endl;
        testNum++;
        std::cout << r->toString() << std::endl;
        // test10
        r = test10();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "test" << testNum << " results:" << std::endl;
        testNum++;
        std::cout << r->toString() << std::endl;
        // test11
        r = test11();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "test" << testNum << " results:" << std::endl;
        testNum++;
        std::cout << r->toString() << std::endl;
        // test12
        r = test12();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << r->toString() << std::endl;
        // test13
        r = test13();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "test" << testNum << " results:" << std::endl;
        testNum++;
        std::cout << r->toString() << std::endl;
        // test14
        r = test14();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "test" << testNum << " results:" << std::endl;
        testNum++;
        std::cout << r->toString() << std::endl;
        // test15
        r = test15();
        totalPossible += r->pointsPossible;
        totalEarned += r->pointsEarned;
        std::cout << "test" << testNum << " results:" << std::endl;
        testNum++;
        std::cout << r->toString() << std::endl;

        // return details
        return new TestResults(totalPossible, totalEarned, "");
    }


};
