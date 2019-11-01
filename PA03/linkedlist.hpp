//Name: Joanthan Gassner
//SID: 12299764
//Class: CS1575 Sec A
//Instructor: Dr. Morales
//Date: 10-21-19


template <typename T>
LinkedList<T>::LinkedList(){
  //I almost think it is this as the list has no nodes.
  m_head = m_back = NULL;
  m_size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){
  LLNode<T> * tmp;
  for(int i=0; i<m_size; i++) {
    tmp = m_head; //Set tmp pointer to element to be deleted
    m_head = m_head->m_next; //Point m_head to the next element in the list
    delete tmp;  //Remove element in list.
  }
  tmp = NULL;  //Not needed but good practice
//std::cout << "THe Default Destructor has finished" << std::endl;  //Just for testing
}

template <typename T>
int LinkedList<T>::size() const {
  return m_size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
  if (m_size == 0) {
    return true;
  }
  else{
    return false;
  }
}

template <typename T>
LLNode<T> * LinkedList<T>::getFirstPtr() {
  if (m_size == 0) {
    return NULL;
  }
  else {
    return m_head;
  }
}

template <typename T>
const LLNode<T> * LinkedList<T>::getFirstPtr() const {
  if (m_size == 0) {
    return NULL;
  }
  else {
    return m_head;
  }
}

template <typename T>
LLNode<T> * LinkedList<T>::getLastPtr() {
  if (m_size == 0) {
    return NULL;
  }
  else {
    return m_back;
  }
}

template <typename T>
LLNode<T>* LinkedList<T>::getAtPtr(int i) {
  //Check for out-of-bounds or empty list
  if(m_size==0 || i<0 || i>m_size) {
    return NULL;
  }
  else {
    LLNode<T> * tmp;
    tmp = m_head;  //Point tmp pointer to the begining of list, covers i=0 case
    for(int k=0; k<(i-1); k++) {
      tmp = tmp->m_next; //move tmp up one to return the correct element
    }
    return tmp;
  }
}

//Basic Mutator
template <typename T>
void LinkedList<T>::clear() {
  LLNode<T> * tmp;

  for (int i=0; i<m_size; i++) {
    tmp = m_head; //Set tmp to element needing to be deleted
    m_head = m_head->m_next; //Set head pointer to next element in the list
    delete tmp;  //Remove element from the list
  }
  //Reset everything
  m_size = 0;
  m_head = m_back = NULL;
  tmp = NULL; //Avoid dangling pointer.
}

template <typename T>
void LinkedList<T>::insert_front(const T& x) {
  LLNode<T> * tmp;  //Create a tmp LLNode pointer
  tmp = new LLNode<T>;  //Create a new LLNode
  tmp->m_data = x;  //Set the LLNode's data equal to 'x'
  tmp->m_next = m_head; //Set the LLNode's next pointer to point to the head of the list
  m_head = tmp; //Make the original head point to the new head, breaking the old link.

  //Since there is no sentinel node, this starts the m_back pointer to follow
  //the 'last' element
  if (m_size == 0) {
    m_back = m_head;
  }
  m_size++; //Increment the size of the list.
  //delete tmp; //If this is here, segfault (core dump)
  //tmp = NULL;  //Needed?
}

template <typename T>
void LinkedList<T>::insert_back(const T& x) {
  //Since there's no sentinel node for empty lists, this starts one.
  //The insert_front() takes care of the pointers for it.
  if (m_size == 0) {
    insert_front(x);
  }
  else {
    LLNode<T> * tmp;  //Create LLNode tmp pointer
    tmp = new LLNode<T>;  //Create new LLNode
    tmp->m_data = x;  //Set the data elelment into the new node
    m_back->m_next = tmp; //Set the old list's element's pointer to the new last element
    m_back = tmp; //Make the new node the last element in the list
    m_size++;  //Increase the size
  }
}

template <typename T>
void LinkedList<T>::insert(const T& x, LLNode<T>* pos){
  LLNode<T> * tmp;
  tmp = new LLNode<T>;
  tmp->m_data = x; //Insert 'x' into new node
  tmp->m_next = pos->m_next; //Prep the new node to point to the next list element
  pos->m_next = tmp; //Officially connect the node
  m_size++;
}

template <typename T>
void LinkedList<T>::remove_front() {
  //Checking for an empty list
  if (m_size == 0) {
    std::cout << std::endl << "Empty list. Nothing to remove." << std::endl;
    return;
  }
  //Check for a list size of 1
  else if (m_size == 1) {
    clear();
    return;
  }
  else {
    LLNode<T> * tmp;
    tmp = m_head; //Set the tmp pointer to the front node for deletion
    m_head = m_head->m_next;  //Point the m_head ahead one, making it the new beginning
    delete tmp; //remove the old front of the list
    m_size--;
  }

}

template <typename T>
void LinkedList<T>::remove(LLNode<T>* pos) {
  //in a way we don't delete "pos", but overwrite its contents
  //and jump over the next node ahead.  Follow the memory since LL
  //only go one way.

  //Code below removes based on index at zero
  //Homework removes one ahead for some reason
  /*
  LLNode<T> * tmp;
  tmp = pos->m_next; //tmp now holds the link ahead
  pos->m_data = tmp->m_data; //Overwrite data from one element ahead
  pos->m_next = tmp->m_next; //Jump over the element ahead of "pos"
  delete tmp;
  m_size--;
  */

  //This is for the "remove next one" for the hoemwork
  //See Test03
  //PANIC YOU CAN POINT OFF THE LIST!!!!!
  LLNode<T> * tmp;
  LLNode<T> * keep;
  tmp = pos->m_next; //tmp now holds the link ahead
  keep = pos->m_next->m_next; //Jump two ahead, problem if we are at the end of list
  delete tmp;
  pos->m_next = keep; //Re-join the link
  m_size--;

}




template <typename T>
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list)
{
  //LLNode<T> * tmp = list.m_head;  //m_head is private, need accessor
  //LLNode<T> * tmp = list.getFirstPtr();  //Wont' work unless it's const pointer
  const LLNode<T> * tmp = list.getFirstPtr(); //ASK!!!!


  out << "[ ";

  for (int i=0; i<list.size(); i++){
    out << tmp->m_data << ", "; //Access LLNode actual data
    //tmp->m_next; //move the tmp pointer to point to the next node's member data for the next round. JUST REPEATS!!!!!
    tmp = tmp->m_next; //move the tmp pointer to point to the next node's member data for the next round
  }

  out << "]";

  //delete tmp;
  return out;
}
