#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    //write your code here

    T *v = new T[mSize];

    for(int i=0;i<mSize;i++){

        v[i] = mData[i];

    }
    
    delete[] mData;
    
    mCap = mSize;

    mData = v;

} 

#endif
