#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >

size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  //write your code here
  if(n == NULL)return 0;
  return process(n->left) + process(n->right) + 1;
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  //write your code here
  if(empty())return std::pair<KeyT,MappedT>();
  delete_all_nodes(left.mRoot);
  delete_all_nodes(right.mRoot);
  left.mRoot = mRoot->left;
  right.mRoot = mRoot->right;
  left.mSize = process(left.mRoot);
  right.mSize = mSize - 1 - left.mSize;
  mRoot->left = NULL;
  mRoot->right = NULL;
  mSize = 1;
  return mRoot->data;
}

#endif

