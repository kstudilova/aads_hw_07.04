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