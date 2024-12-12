#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>>& ls) {
    for (auto it = ls.begin(); it != ls.end(); ++it) {
        node* first = it->mHeader->next; 
        node* last = it->mHeader->prev;
        
        if (first != it->mHeader) {  
          
            mHeader->prev->next = first;
            first->prev = mHeader->prev;

            last->next = mHeader;
            mHeader->prev = last;

            mSize += it->mSize;

            it->mHeader->next = it->mHeader;
            it->mHeader->prev = it->mHeader;
            it->mSize = 0;
        }
    }
}

#endif
