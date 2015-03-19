//
//  IndexType.h
//  Assignment9
//
//  Created by Taylor Petrychyn on 2015-03-13.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//

#ifndef INDEXTYPE_H
#define INDEXTYPE_H

#include <stdio.h>
#include <string>
#include "OccurrenceType.h"

using namespace std;

const string OK = "OK";
const string TREE_FULL = "TREE_FULL";
const string DUPLICATE = "DUPLICATE";

struct Value {
    string word = "";
    OccurrenceType occ;
};

struct Node {
    Value val;
    int height;
    Node* left;
    Node* right;
};

class IndexType {
public:
    IndexType();
    
    Node* root;
    
    Node* Find(const string& word, Node* p);
    
    string Insert(const Value& val, Node*& p);
    
    void LL(Node*& p);
    
    void RR(Node*& p);
    
    void LR(Node*& p);
    
    void RL(Node*& p);
    
    int Height(Node* p);
    
    void ReverseOrder(Node*& p);
    
    void InOrder(Node*& p);

};
#endif /* defined(__Assignment9__IndexType__) */
