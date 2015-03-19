//
//  OccurrenceType.cpp
//  Assignment9
//
//  Created by Taylor Petrychyn on 2015-03-13.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//

#include "OccurrenceType.h"

OccurrenceType::OccurrenceType() {
    length = 0;
    p = -1;
}

void OccurrenceType::ResetP() {
    p = -1;
}

void OccurrenceType::Iterate() {
    p++;
}

bool OccurrenceType::IsPSet() {
    if (p < 0 || p > length-1)
        return false;
    return true;
}

int OccurrenceType::GetP() {
    return p;
}

void OccurrenceType::SetP(const int& newP) {
    p = newP;
}

Hit OccurrenceType::Read() {
    return hit[p];
}

void OccurrenceType::Write(const int& _page, const int& _pos) {
    hit[p].page = _page;
    hit[p].pos = _pos;
}

bool OccurrenceType::IsFull() {
    if (length == MAX_LENGTH)
        return true;
    return false;
}

bool OccurrenceType::IsEmpty() {
    if (length == 0)
        return true;
    return false;
}

void OccurrenceType::InsertUnsorted(const int& _page, const int& _pos) {
    p = length;
    hit[p].page = _page;
    hit[p].pos = _pos;
    length++;
}