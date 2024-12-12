#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure
#include<bits/stdc++.h>

template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  T *arr = new T[mSize];
  int cnt = 0;

 std::unordered_map<T,bool> ump;
  
  for(auto it = begin();it < end();it++){
    ump[(mData[it-begin()])] = 0;
  }

  for(auto it = begin();it < end();it++){

    int indx = it - begin();

    if(ump[mData[indx]] == 0){

      ump[mData[indx]] = 1;

      arr[indx-cnt] = mData[indx];

    }else{

      cnt++;
    }

  }
  mSize-=cnt;
  mData = arr;
  
}

#endif
