//
//  IndexType.cpp
//  Assignment9
//
//  Created by Taylor Petrychyn on 2015-03-13.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//

#include "IndexType.h"
#include <cmath>
#include <iostream>

int spaceAmt = -1;

IndexType::IndexType() {
    root = 0;
}

Node* IndexType::Find(const string& word, Node* p) {
    if (p == NULL || word == p->val.word)
        return p;
    else if (word < p->val.word)
        return Find (word, p->left);
    else
        return Find (word, p -> right);

}

string IndexType::Insert(const Value& val, Node*& p) {
    string result;
    if (p == NULL) {
        try {
            p = new Node;
        } catch (std::bad_alloc& ba) {
            return TREE_FULL;
        }
        p -> val = val;
        result = OK;
    } else if (val.word < p -> val.word) {
        result = Insert (val, p -> left);
        if (result == OK) {
            if (Height (p -> left) - Height (p -> right) == 2) {
                if (val.word < p -> left -> val.word)
                    LL (p);
                else
                    LR (p);
            }
        }
    } else if (val.word > p -> val.word) {
        result = Insert (val, p -> right);
        if (result == OK) {
            if (Height (p -> right) - Height (p -> left) == 2) {
                if (val.word > p->right->val.word)
                    RR (p);
                else
                    RL (p);
            }
        }
    } else
        result = DUPLICATE; // assumes duplicates are not allowed
    if (result == OK)
        p -> height = max (Height (p -> left), Height (p -> right)) + 1;
    return result;
}

void IndexType::LL(Node*& p) {
    Node* q = p -> left;
    p -> left = q -> right;
    q -> right = p;
    p -> height = max (Height (p -> left), Height (p -> right)) + 1;
    q -> height = max (Height (q -> left), Height (q -> right)) + 1;
    p = q;
    return;
}

void IndexType::RR(Node*& p) {
    Node* q = p -> right;
    p -> right = q -> left;
    q -> left = p;
    p -> height = max (Height (p -> left), Height (p -> right)) + 1;
    q -> height = max (Height (q -> left), Height (q -> right)) + 1;
    p = q;
    return;
}

void IndexType::LR(Node*& p) {
    RR(p->left);
    LL(p);
}

void IndexType::RL(Node*& p) {
    LL(p->right);
    RR(p);
}

int IndexType::Height(Node* p) {
    if (p == NULL)
        return -1;
    else
        return p -> height;
}

void IndexType::ReverseOrder(Node*& p) {
    if (p == NULL)
        return;
    spaceAmt++;
    ReverseOrder (p -> right);
    for (int i=0;i<spaceAmt;i++) {
        cout << "-";
    }
    cout << p->val.word;
    cout << endl;
    ReverseOrder (p -> left);
    spaceAmt--;
    return ;
}

void IndexType::InOrder(Node*& p) {
    if (p == NULL)
        return;
    InOrder (p -> left);
    cout << p->val.word;
    p->val.occ.ResetP();
    p->val.occ.Iterate();
    while (p->val.occ.IsPSet()) {
        cout << " (" << p->val.occ.Read().page << ", " << p->val.occ.Read().pos << ") ";
        p->val.occ.Iterate();
    }
    cout << endl;
    InOrder (p -> right);
    return;
}



