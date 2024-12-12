#ifndef __STUDENT_H_
#define __STUDENT_H_
#include"vector.h"
#include<algorithm>

template <typename T>

void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {

  std::sort(data.begin(), data.end());

  T *v = new T[mSize + data.size()];

  mSize += data.size();

  mCap += data.size();

  int cnt = 0;

  for(int i = 0 ; i < mSize ; i++){

    if(i == data[cnt].first+cnt){
      
      v[i] = data[cnt].second;

      cnt++;

    }else{
      
      v[i] = mData[i-cnt];

    }
    
  }

  mData = v;
  
}
#endif
