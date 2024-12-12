void shift(int k) {
	// TODO: Add your code here

	auto it = begin();

	if(k > 0){
		for(int i=0;i<k;i++){
			mHeader = mHeader->next;
			mHeader->prev->data = mHeader->data;
		}
	}else{
		for(int i=0;i<-k;i++){
			mHeader = mHeader->prev;
			mHeader->next->data = mHeader->data;
		}
	}


	
	
	
}
