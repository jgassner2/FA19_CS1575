//Name: Joanthan Gassner
//SID: 12299764
//Class: CS1575 Sec A
//Instructor: Dr. Morales
//Date: 12-9-19

//Derives from the abstractbstree.h file

#ifndef MYBSTREE_H
#define MYBSTREE_H

#include "abstractbstree.h"


template <typename T>
class TreeNode
{
public:
   T m_data;
   TreeNode* m_right;
   TreeNode* m_left;
};

template <typename T>
class MyBSTree : public AbstractBSTree<T>
{
  private:
   TreeNode<T>* m_root;
   int m_size;
  public:


};













#include "mybstree.hpp"
#endif
