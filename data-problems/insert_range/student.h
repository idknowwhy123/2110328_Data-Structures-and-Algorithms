#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "vector.h"
template <typename T>

void CP::vector<T>::insert(iterator position,iterator first,iterator last){

    size_t pos = position - begin();

    for(auto it = first;it < last ;it++){

        ensureCapacity(mSize + 1);

        for(size_t i = mSize;i > pos;i--) {

            mData[i] = mData[i-1];

        }

        //std::cout << *it << '\n';

        mData[pos] = *it;

        mSize++;

        pos++;

    }
    
}

#endif