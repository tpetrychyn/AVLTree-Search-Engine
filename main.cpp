//
//  main.cpp
//  Assignment9
//
//  Created by Taylor Petrychyn on 2015-03-13.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "IndexType.h"

using namespace std;

int main(int argc, const char * argv[]) {
    IndexType index;
    for (int i=1;i<=20;i++) {
        //Open all 20 files
        ifstream inData;
        inData.open(to_string(i));
        if (!inData)
            return 0;
        
        int pagePos = 0; //each new file set to 0, each word increases this by 1 to store the position of it on the page
        while (!inData.eof()) {
            string word;
            inData >> word;
            transform(word.begin(), word.end(), word.begin(), ::tolower); //lowercase
            Node* searchNode = index.Find(word, index.root); //see if the word already exists
            if (searchNode == NULL) {
                Value tempValue;
                tempValue.occ.InsertUnsorted(i, pagePos);
                tempValue.word = word;
                string x = index.Insert(tempValue, index.root); //add a new occurrence of the word if it exists
            } else {
                if (!searchNode->val.occ.IsFull())
                searchNode->val.occ.InsertUnsorted(i, pagePos); //otherwise insert it to tree
            }
            pagePos++;
        }
    }
    
    //Print tree visually
    index.ReverseOrder(index.root);
    cout << endl;
    
    //Print list with occurrences
    index.InOrder(index.root);
    cout << endl;
    
    //Single word search
    cout << "Enter a word to search: ";
    string searchWord;
    cin >> searchWord;
    Node* newNode = index.Find(searchWord, index.root); //search for the word
    if (newNode != NULL) {
        newNode->val.occ.ResetP();
        newNode->val.occ.Iterate();
        cout << newNode->val.word;
        while (newNode->val.occ.IsPSet()) { //loop through all the occurrencs of the word and print them
            cout << " (" << newNode->val.occ.Read().page << ", " << newNode->val.occ.Read().pos << ")";
            newNode->val.occ.Iterate();
        }
        cout << endl;
    } else
        cout << "Not found" << endl;
    
    return 0;
}
