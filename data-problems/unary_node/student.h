#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) const {
  //you may write additional code her

  if(n == NULL) return 0;

  size_t cnt = 0;

  if((n->left != NULL && n->right == NULL) || (n->left == NULL && n->right != NULL)  )cnt += 1;

  return cnt + process(n->left) + process(n->right);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  //write your code here
  return process(mRoot);
}

#endif
