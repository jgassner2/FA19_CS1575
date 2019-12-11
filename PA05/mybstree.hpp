//Name: Joanthan Gassner
//SID: 12299764
//Class: CS1575 Sec A
//Instructor: Dr. Morales
//Date: 12-9-19


template <typename T>
MyBSTree<T>::MyBSTree() {
  m_root = NULL;
  m_size = 0;
}

template <typename T>
MyBSTree<T>::~MyBSTree() {
  clear();

}

template <typename T>
MyBSTree<T>& MyBSTree<T>:: operator=(const MyBSTree<T>& rhs) {

}

template <typename T>
MyBSTree<T>::MyBSTree(const MyBSTree<T>& cpy) {


}

template <typename T>
int MyBSTree<T>::size() const {

}

template <typename T>
bool MyBSTree<T>::isEmpty() const {
  if (m_size == 0) {
    return true;
  }
  else {
    return false;
  }
}

template <typename T>
int MyBSTree<T>:: height() const{

}

template <typename T>
const T& MyBSTree<T>:: getMax() const throw (Oops) {

}

template <typename T>
const T& MyBSTree<T>:: getMin() const throw (Oops) {

}

template <typename T>
int MyBSTree<T>::find(const T& x) const {

}

template <typename T>
void MyBSTree<T>::clear() {
  clearTree(m_root);
  m_root = NULL;
  m_size = 0;
}

template <typename T>
void MyBSTree<T>::insert(const T& x) {
  insertElement(x,m_root);
}

template <typename T>
void MyBSTree<T>::remove(const T& x) {

}

template <typename T>
void MyBSTree<T>::printPreOrder() const {

}

template <typename T>
void MyBSTree<T>::printPostOrder() const {

}

template <typename T>
void MyBSTree<T>::print() const {
//Just have it call the "Pretty print function" :D
prettyPrint(m_root, 0);
}


//
template <typename T>
void prettyPrint (const TreeNode<T>* t, int pad)
{
 string s(pad, ' ');
 if (t == NULL)
     cout << endl;
 else{
   prettyPrint(t->m_right, pad+4);
   cout << s << t->m_data << endl;
   prettyPrint(t->m_left, pad+4);
 }
}

template <typename T>
void MyBSTree<T>::insertElement(const T& x, TreeNode<T>* &t) {
  if (t == NULL) {
    //m_root = new TreeNode<T>(x, NULL, NULL);  //Coudn't get parameterized constructor to work
    t = new TreeNode<T>;
    t->m_data = x;
    t->m_left = NULL;
    t->m_right = NULL;
  }
  else {
    //Check to see if data goes in left subtree
    if (x < t->m_data) {
      insertElement(x,t->m_left);
    }
    //Check to see if the data goes in the right subtree
    else if(x > t->m_data) {
      insertElement(x, t->m_right);
    }
    //Duplicate data, i.e. x==m_data
    else
      return;
  }
}

template <typename T>
void MyBSTree<T>::clearTree(TreeNode<T>* &t) {
  //Clear left tree/subtrees
  if (t != NULL)
    clearTree(t->m_left);
  //Clear right tree/subtrees
  if (t != NULL)
    clearTree(t->m_right);
  //Delete nodes
  delete t;
}
