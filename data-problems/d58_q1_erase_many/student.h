#ifndef __STUDENT_H_
#define __STUDENT_H_
#include"vector.h"

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {

  int cnt = 0;

  for(auto x : pos){

    T* it = &mData[x-cnt];

    while((it+1)!=end()) {

      *it = *(it+1);

      it++;

    }
    cnt++;

    mSize--;

  }
    
}

#endif
