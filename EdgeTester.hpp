#pragma once

#include <iostream>
#include <random>
#include <sstream>
#include <string>

#include "Edge.hpp"
#include "Graph.hpp"
#include "Point2D.hpp"
#include "Vertex.hpp"
#include "TestResults.hpp"

class EdgeTester {
    
public:
    
    /*
     Create an non-loop edge with no data, then test all getter methods.
     */
    static TestResults* test0() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create a non-loop edge
        Vertex<std::string>* initialVertex = new Vertex<std::string>(new std::string("initial vertex"));
        Vertex<std::string>* terminalVertex = new Vertex<std::string>(new std::string("terminal vertex"));
        Edge<std::string, Point2D>* edge = new Edge<std::string, Point2D>(initialVertex, terminalVertex);
        // test getWeight
        pointsPossible++;
        double edgeWeight = edge->getWeight();
        if (edgeWeight == 1) {
            pointsEarned++;
        } else {
            sout << "getWeight returned " << edgeWeight << ", should have been 1" << std::endl;
        }
        // test getData
        pointsPossible++;
        Point2D* data = edge->getData();
        if (data == nullptr) {
            pointsEarned++;
        } else {
            sout << "getData returned non-null value on an edge with no data" << std::endl;
        }
        // test getInitialVertex
        pointsPossible++;
        Vertex<std::string>* v = edge->getInitialVertex();
        if (v == initialVertex) {
            pointsEarned++;
        } else {
            sout << "getInitialVertex did not return the initial vertex" << std::endl;
        }
        // test getTerminalVertex
        pointsPossible++;
        v = edge->getTerminalVertex();
        if (v == terminalVertex) {
            pointsEarned++;
        } else {
            sout << "getTerminalVertex did not return the terminal vertex" << std::endl;
        }
        // test isLoop
        pointsPossible++;
        if (edge->isLoop() == false) {
            pointsEarned++;
        } else {
            sout << "isLoop returned true on a non-loop edge" << std::endl;
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Create an non-loop edge, add data, set the edge weight, then test all
     getter methods.
     */
    static TestResults* test1() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create a non-loop edge
        Vertex<std::string>* initialVertex = new Vertex<std::string>(new std::string("initial vertex"));
        Vertex<std::string>* terminalVertex = new Vertex<std::string>(new std::string("terminal vertex"));
        Edge<std::string, Point2D>* edge = new Edge<std::string, Point2D>(initialVertex, terminalVertex);
        // add some data to the edge
        Point2D* p = new Point2D(0,0);
        edge->setData(p);
        // set the edge weight
        edge->setWeight(5);
        // test getWeight
        pointsPossible++;
        double edgeWeight = edge->getWeight();
        if (edgeWeight == 5) {
            pointsEarned++;
        } else {
            sout << "getWeight returned " << edgeWeight << ", should have been 1" << std::endl;
        }
        // test getData
        pointsPossible++;
        Point2D* data = edge->getData();
        if (data == p) {
            pointsEarned++;
        } else {
            sout << "getData returned incorrect value" << std::endl;
        }
        // test getInitialVertex
        pointsPossible++;
        Vertex<std::string>* v = edge->getInitialVertex();
        if (v == initialVertex) {
            pointsEarned++;
        } else {
            sout << "getInitialVertex did not return the initial vertex" << std::endl;
        }
        // test getTerminalVertex
        pointsPossible++;
        v = edge->getTerminalVertex();
        if (v == terminalVertex) {
            pointsEarned++;
        } else {
            sout << "getTerminalVertex did not return the terminal vertex" << std::endl;
        }
        // test isLoop
        pointsPossible++;
        if (edge->isLoop() == false) {
            pointsEarned++;
        } else {
            sout << "isLoop returned true on a non-loop edge" << std::endl;
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Create a loop with no data, test all getter methods.
     */
    static TestResults* test2() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create a non-loop edge
        Vertex<std::string>* initialVertex = new Vertex<std::string>(new std::string("initial vertex"));
        Vertex<std::string>* terminalVertex = initialVertex;
        Edge<std::string, Point2D>* edge = new Edge<std::string, Point2D>(initialVertex, terminalVertex);
        // test getWeight
        pointsPossible++;
        double edgeWeight = edge->getWeight();
        if (edgeWeight == 1) {
            pointsEarned++;
        } else {
            sout << "getWeight returned " << edgeWeight << ", should have been 1" << std::endl;
        }
        // test getData
        pointsPossible++;
        Point2D* data = edge->getData();
        if (data == nullptr) {
            pointsEarned++;
        } else {
            sout << "getData returned non-null value on an edge with no data" << std::endl;
        }
        // test getInitialVertex
        pointsPossible++;
        Vertex<std::string>* v = edge->getInitialVertex();
        if (v == initialVertex) {
            pointsEarned++;
        } else {
            sout << "getInitialVertex did not return the initial vertex" << std::endl;
        }
        // test getTerminalVertex
        pointsPossible++;
        v = edge->getTerminalVertex();
        if (v == terminalVertex) {
            pointsEarned++;
        } else {
            sout << "getTerminalVertex did not return the terminal vertex" << std::endl;
        }
        // test isLoop
        pointsPossible++;
        if (edge->isLoop() == true) {
            pointsEarned++;
        } else {
            sout << "isLoop returned false on a loop" << std::endl;
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Create an loop, add data, set the edge weight, then test all
     getter methods.
     */
    static TestResults* test3() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create a non-loop edge
        Vertex<std::string>* initialVertex = new Vertex<std::string>(new std::string("initial vertex"));
        Vertex<std::string>* terminalVertex = initialVertex;
        Edge<std::string, Point2D>* edge = new Edge<std::string, Point2D>(initialVertex, terminalVertex);
        // add some data to the edge
        Point2D* p = new Point2D(0,0);
        edge->setData(p);
        // set the edge weight
        edge->setWeight(5);
        // test getWeight
        pointsPossible++;
        double edgeWeight = edge->getWeight();
        if (edgeWeight == 5) {
            pointsEarned++;
        } else {
            sout << "getWeight returned " << edgeWeight << ", should have been 1" << std::endl;
        }
        // test getData
        pointsPossible++;
        Point2D* data = edge->getData();
        if (data == p) {
            pointsEarned++;
        } else {
            sout << "getData returned an incorrect value" << std::endl;
        }
        // test getInitialVertex
        pointsPossible++;
        Vertex<std::string>* v = edge->getInitialVertex();
        if (v == initialVertex) {
            pointsEarned++;
        } else {
            sout << "getInitialVertex did not return the initial vertex" << std::endl;
        }
        // test getTerminalVertex
        pointsPossible++;
        v = edge->getTerminalVertex();
        if (v == terminalVertex) {
            pointsEarned++;
        } else {
            sout << "getTerminalVertex did not return the terminal vertex" << std::endl;
        }
        // test isLoop
        pointsPossible++;
        if (edge->isLoop() == true) {
            pointsEarned++;
        } else {
            sout << "isLoop returned false on a loop" << std::endl;
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    /*
     Test the equality operator on (a) an edge and itself, (b) two edges that
     that share exactly one vertex, (c) two edges that share both vertices but
     not the data, (d) two edges that share both vertices and data, (e) two
     edges that share the same vertices and data values, but whose values are
     stored in different locations (comparison should return false), (f) two
     edges that share the same vertices and data pointers and weights, and
     (g) two edges that share the same vertieces and data pointers, but whose
     edge weights are different comparison should return false).
     */
    static TestResults* test4() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        // create 3 vertices
        Vertex<std::string>* vertex0 = new Vertex<std::string>(new std::string("vertex 0"));
        Vertex<std::string>* vertex1 = new Vertex<std::string>(new std::string("vertex 1"));
        Vertex<std::string>* vertex2 = new Vertex<std::string>(new std::string("vertex 2"));
        // edge 1 connects vertex0 to vertex1
        Edge<std::string, int>* edge1 = new Edge<std::string, int>(vertex0, vertex1);
        Edge<std::string, int>* edge2 = new Edge<std::string, int>(vertex1, vertex2);
        // (a) is each edge equal to itself?
        Edge<std::string, int>* edge1PtrCopy = edge1;
        pointsPossible++;
        if (*edge1PtrCopy == *edge1) {
            pointsEarned++;
        } else {
            sout << "comparison of edge1 to itself returned false" << std::endl;
        }
        Edge<std::string, int>* edge2PtrCopy = edge2;
        pointsPossible++;
        if (*edge2PtrCopy == *edge2) {
            pointsEarned++;
        } else {
            sout << "comparison of edge2 to itself returned false" << std::endl;
        }
        // (b) is edge1 different than edge2?
        pointsPossible++;
        if (*edge1 != *edge2) {
            pointsEarned++;
        } else {
            sout << "comparison of distinct edges returned true" << std::endl;
        }
        // (c) make a copy of edge1, give it some data, compare to edge1
        Edge<std::string, int>* edge1Copy = new Edge<std::string, int>(vertex0, vertex1);
        int x1 = 1;
        edge1Copy->setData(&x1);
        pointsPossible++;
        if (*edge1Copy != *edge1) {
            pointsEarned++;
        } else {
            sout << "comparison of different edges returned true" << std::endl;
        }
        // (d) if we set edge1's data to point to x1, edge1 should now equal
        // its copy
        edge1->setData(&x1);
        pointsPossible++;
        if (*edge1Copy == *edge1) {
            pointsEarned++;
        } else {
            sout << "comparison of identical edges returned false" << std::endl;
        }
        // (e) set edge1's data to point somewhere else; comparison should now
        // return false.
        int x2 = 1;
        edge1->setData(&x2);
        pointsPossible++;
        if (*edge1Copy != *edge1) {
            pointsEarned++;
        } else {
            sout << "comparison of different edges returned true" << std::endl;
        }
        // (f)
        Edge<std::string, int>* edge2Copy = new Edge<std::string, int>(vertex1, vertex2);
        int x3 = 2;
        edge2->setData(&x3);
        edge2Copy->setData(&x3);
        edge2->setWeight(2);
        edge2Copy->setWeight(2);
        pointsPossible++;
        if (*edge2 == *edge2Copy) {
            pointsEarned++;
            
        }
        // (g)
        edge2->setWeight(0);
        pointsPossible++;
        if (*edge2 != *edge2Copy) {
            pointsEarned++;
        } else {
            sout << "comparison of edges with different weights returned true" << std::endl;
        }
        
        return new TestResults(pointsPossible, pointsEarned, sout.str());
    }
    
    static TestResults* testX() {
        std::ostringstream sout;
        int pointsPossible = 0;
        int pointsEarned = 0;
        
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

            return new TestResults(totalPossible, totalEarned, "");
        }
    
};
