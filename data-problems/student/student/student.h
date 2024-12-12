#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <algorithm>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  // your code here
  if(mFront + mSize > mCap)ensureCapacity(mFront + mSize);

  std::sort(pos.begin(), pos.end());

  T *arr = new T[(mFront + mSize) % mCap];

  int indx = 0;

  size_t cnt = 0;

  for(int i = 0 ; i < mSize ; i++){

    if(i == pos[indx]){

      indx++;

    }else{

      cnt++;

      arr[i - indx] = mData[((mFront + i)% mCap)];

    }

  }

  delete[] mData;

  mData = arr;

  mFront = 0;

  mSize = cnt;

}

#endif
