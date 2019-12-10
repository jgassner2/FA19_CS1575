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
    MyBSTree();
    //Big Three
    ~MyBSTree();
    MyBSTree<T>& operator=(const MyBSTree<T>& rhs);
    MyBSTree(const MyBSTree<T>& cpy);  //Copy Constructor

    //Derived functions
    int size() const;
    bool isEmpty() const;
    int height() const;
    const T& getMax() const throw (Oops);
    const T& getMin() const throw (Oops);
    int find(const T& x) const;
    void clear();
    void insert(const T& x);
    void remove(const T& x);
    void printPreOrder() const;
    void printPostOrder() const;
    void print() const;

};













#include "mybstree.hpp"
#endif
