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
    // this is the constructor
    // initializes the tree
    IndexType();
    
    Node* root;
    
    // assumes p is passed-by-value
    Node* Find(const string& word, Node* p);
    
    // assumes p is passed-by-reference
    string Insert(const Value& val, Node*& p);
    
    // assumes p is passed-by-value
    void LL(Node*& p);
    
    // assumes p is passed-by-value
    void RR(Node*& p);
    
    // assumes p is passed-by-value
    void LR(Node*& p);
    
    // assumes p is passed-by-value
    void RL(Node*& p);
    
    // assumes p is passed-by-reference
    int Height(Node* p);
    
    // InOrder but flipped left and right
    void ReverseOrder(Node*& p);
    
    // assumes p is passed-by-value
    void InOrder(Node*& p);

};
#endif /* defined(__Assignment9__IndexType__) */
