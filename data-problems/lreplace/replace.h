void replace(const T& x, list<T>& y) {
  //write your code here
  for(auto it = begin(); it != end() ; it++){
    if(*it == x){
      
      for(auto p : y){
        insert(it,p);
      }

      erase(it);
      
    }
  }

}
