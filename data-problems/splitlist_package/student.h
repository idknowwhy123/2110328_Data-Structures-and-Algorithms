void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    int n1,n2;

    if(size()%2 == 0){
        n1 = size()/2;
    }else{
        n1 = (size()+1)/2;
    }

    n2 = mSize - n1;

    auto it = begin();

    for(int i=0;i<n1;i++){
        it++;
    }

    list1.mHeader->prev->next = mHeader->next;
    mHeader->next->prev = list1.mHeader->prev;
    it.ptr->prev->next = list1.mHeader;
    list1.mHeader->prev = it.ptr->prev;

    list2.mHeader->prev->next = it.ptr;
    it.ptr->prev = list2.mHeader->prev;
    mHeader->prev->next = list2.mHeader;
    list2.mHeader->prev = mHeader->prev;
    
    mHeader->prev = mHeader;
    mHeader->next = mHeader;

    mSize = 0;
    list1.mSize += n1;
    list2.mSize += n2;

}
