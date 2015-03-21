//
//  OccurrenceType.h
//  Assignment9
//
//  Created by Taylor Petrychyn on 2015-03-13.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//

#ifndef OCCURRENCETYPE_H
#define OCCURRENCETYPE_H

#include <stdio.h>

const int MAX_LENGTH = 100;

struct Hit {
    int page;
    int pos;
};

class OccurrenceType {
private:
    Hit hit[MAX_LENGTH];
    int length;
    int p;
    
public:
    // this is the constructor
    // initializes the list
    OccurrenceType();
    
    //sets p to -1
    void ResetP();
    
    //add 1 to p
    void Iterate();
    
    //checks if p is within the allowed range
    bool IsPSet();
    
    //returns p
    int GetP();
    
    // always call IsPSet after each call to SetP
    // sets p
    void SetP(const int& newP);
    
    // returns the value of the element pointed to by p
    // p must be set prior to calling Read
    // always call IsPSet prior to calling Read
    Hit Read();
    
    // writes a new value into the element pointed to by p
    // p must be set prior to calling Write
    // always call IsPSet prior to calling Write
    // could cause a problem in a sorted list if the key is changed
    void Write(const int& _page, const int& _pos);
    
    //checks whether the list is full
    bool IsFull();
    
    //checks whether the list is empty
    bool IsEmpty();
    
    //returns length
    int Length() { return length; }
    
    // inserts a new element at the end of the list
    // always call IsFull prior to calling InsertUnsorted
    // sets p
    void InsertUnsorted(const int& _page, const int& _pos);
};

#endif
