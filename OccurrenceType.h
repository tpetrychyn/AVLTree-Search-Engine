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
    OccurrenceType();
    
    void ResetP();
    
    void Iterate();
    
    bool IsPSet();
    
    int GetP();
    
    void SetP(const int& newP);
    
    Hit Read();
    
    void Write(const int& _page, const int& _pos);
    
    bool IsFull();
    bool IsEmpty();
    
    int Length() { return length; }
    
    void InsertUnsorted(const int& _page, const int& _pos);
};

#endif
