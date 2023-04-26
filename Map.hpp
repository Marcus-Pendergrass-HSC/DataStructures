#pragma once

#include "List.hpp"
#include "Pair.hpp"

/*
 A Map stores key/value pairs, and supports looking up the value associated
 with a specific key.
 */
template <typename T, typename U>
class Map {
        
protected:
        
    List<Pair<T,U>>* thePairs;
    
    /*
     If the specified key is part of this map, this method returns the
     index of the corresponding key/value pair. If the specified key is
     not part of this map, this method returns a negative number.
     */
    int getIndex(T* key) {
        int ndx = -1;
        for (int k = 0; k < thePairs->getSize(); k++) {
            Pair<T,U>* pairK = this->thePairs->peek(k);
            if (pairK->first == key) {
                ndx = k;
                break;
            }
        }
        return ndx;
    }
        
public:
    
    /*
     Creates an empty map
     */
    Map() {
        this->thePairs = new List<Pair<T,U>>();
    }
    
    /*
     Returns true if and only if this map has no key-value pairs
     */
    bool isEmpty() {
        return this->thePairs->isEmpty();
    }
    
    /*
     Returns the number of key-value pairs in this map.
     */
    int getSize() {
        return this->thePairs->getSize();
    }
    
    /*
     Returns true if and only if the specified key is the
     key of some member of this map.
     */
    bool contains(T* key) {
        return this->getIndex(key) >= 0;
    }
    
    /*
     Adds the key-value pair to this map. Since this is a map,
     duplicate keys are not allowed. If the specified key already
     exists in this map, the corresponding value will be overwritten.
     */
    void add(T* key, U* value) {
        int ndx = this->getIndex(key);
        if (ndx < 0) {
            Pair<T,U>* newPair = new Pair<T,U>(key, value);
            this->thePairs->insertAtEnd(newPair);
        } else {
            this->thePairs->peek(ndx)->second = value;
        }
    }
    
    /*
     Removes the key-value pair whose key is identical to the specified key,
     and returns the value associated with that key. If no key-value pair
     matches the specified key, the null pointer is returned.
     */
    U* remove(T* key) {
        U* result;
        int ndx = this->getIndex(key);
        if (ndx >= 0) {
            Pair<T,U>* p = this->thePairs->removeFromPosition(ndx);
            result = p->second;
        } else {
            result = nullptr;
        }
        return result;
    }
    
    /*
     Returns the value associated with the specified key. If the specified
     key is not in this map then the null pointer is returned.
     */
    U* lookUp(T* key) {
        U* result;
        int ndx = this->getIndex(key);
        if (ndx >= 0) {
            result = this->thePairs->peek(ndx)->second;
        } else {
            result = nullptr;
        }
        return result;
    }
    
    /*
     Returns a pointer to the first element of an array containing
     all the keys in this map. The size of the array is equal to the
     value returned by this->getSize().
     */
    T** getKeys() {
        T** result = new T*[this->getSize()];
        for (int k = 0; k < this->getSize(); k++) {
            result[k] = this->thePairs->peek(k)->first;
        }
        return result;
    }
    
    
    
};
