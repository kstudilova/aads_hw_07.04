#include <iostream>

template< class T, size_t K >
struct BTree 
{
  T val[K];
  BTree< T, K >* childs[K + 1];
  BTree< T, K >* parent;
};

template< class T, size_t K >
struct BTreeIt
{
  size_t s;
  BTree< T, K >* current;
};

template<class T, size_t K>
BTreeIt<T, K> minimum(BTree<T, K>* node)
{
  if (!node) return {0, nullptr};
  while (node->children[0]) {
    node = node->children[0];
  }
  return {0, node};
}

template<class T, size_t K>
BTreeIt<T, K> maximum(BTree<T, K>* node)
{
  if (!node) return {0, nullptr};
  while (node->children[K]) {
    node = node->children[K];
  }
  size_t last = K - 1;
  while (last > 0 && node->val[last] == T()) last--;
  return {last, node};
}

template< class T, size_t K >
T value(BTreeIt< T, K > it)
{
  return it.current->val[it.s];
}

template< class T, size_t K >
BTreeIt< T, K > next(BTreeIt< T ,K > it)
{
  BTree<T, K>* next = it.current;
  size_t ind = it.s;
    
  if (!next)
  {
    return {0, nullptr};
  }

  if (next->children[ind + 1])
  {
    next = next->children[ind + 1];
    next = minimum(next).current;
    return {0, next};
  }
    
  if (ind + 1 < K)
  {
    return {ind + 1, next};
  }

  BTree<T, K>* parent = next->parent;
  while (parent) {
    size_t i = 0;
    for (; i <= K && parent->children[i] != next; ++i) {}
        
    if (i < K)
    {
      return {i, parent};
    }
        
    next = parent;
    parent = next->parent;
  }
    
  return {0, nullptr};
}

template< class T, size_t K >
BTreeIt< T, K > prev(BTreeIt< T ,K > it)
{
    
}

template< class T, size_t K >
bool hasNext(BTreeIt< T ,K > it)
{

}

template< class T, size_t K >
bool hasPrev(BTreeIt< T ,K > it)
{
    
}

int main()
{
  
}