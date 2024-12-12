// Your code here



KeyT count(node* n){

    if(n == NULL)return -1;
    
    return 1 + std::max(count(n->left),count(n->right));
}

void traverse(node* n, KeyT& max, KeyT& res) {

    if (n == NULL) return;

    traverse(n->left, max, res);
    traverse(n->right, max, res);

    KeyT imbalance = abs(count(n->left) - count(n->right));
    
    if (imbalance > max) {
        max = imbalance;
        res = n->data.first;
    }else if (imbalance == max) {
        res = std::min(res, n->data.first);
    }
}

KeyT getValueOfMostImbalanceNode() {

    KeyT max = -1;  
    KeyT res = -1;    

    traverse(mRoot, max, res);

    return res;
}
