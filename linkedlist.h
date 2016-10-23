#ifndef LINKED_LIST
#define LINKED_LIST

template <class T>
class ListNode {

    //friend class LinkedList<T>;

public:

    //Add functionality here to provide access to the ListNode Object.
    ListNode();
    ListNode(T &);
    ListNode(T, ListNode<T>*);

    T& getValue();
    ListNode* getNext();
    void setNext(ListNode<T>*);
    ListNode* getPrev();
    void setPrev(ListNode<T>*);





private:
    ListNode<T>*next;
    ListNode<T>*prev;
    T data;
};

template <class T>
ListNode<T>::ListNode(){
    next = 0;
    prev = 0;
}

template <class T>
ListNode<T>::ListNode(T& entry){
    data = entry;
    next = 0;
    prev = 0;
}

template <class T>
ListNode<T>::ListNode(T entry, ListNode<T>* n){
    data = entry;
    next = n;
    prev = 0;
}

template <class T>
T& ListNode<T>::getValue(){
    return (data);
}

template <class T>
ListNode<T>* ListNode<T>::getNext(){
    return next;
}

template <class T>
void ListNode<T>::setNext(ListNode<T>* n){
    next = n;
}

template <class T>
ListNode<T>* ListNode<T>::getPrev(){
    return prev;
}

template <class T>
void ListNode<T>::setPrev(ListNode<T>* p){
    prev = p;
}

template<class T>
class LinkedList {

public:

    LinkedList();
    LinkedList(T);
    LinkedList(const LinkedList<T>&);

    void add(T &);
    void addToFront(T);
    T get(int) const;
    int size() const;
    T remove(int);
    bool isEmpty();

    ~LinkedList();


    T& operator[] (int);
    LinkedList<T>& operator=(const LinkedList<T>&);

private:

    ListNode<T>*head;
    ListNode<T>*tail;
    int num_elements;

};

//Write your implementation here
template <class T>
LinkedList<T>::LinkedList(){
    head = 0;
    tail = 0;
    num_elements = 0;
}

template <class T>
LinkedList<T>::LinkedList(T value){
    head = new ListNode<T>(value);
    tail = head;
    num_elements = 1;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> & RHS){
    head = 0;
    tail = 0;
    num_elements = 0;

    //if RHS has a size of 1
    if (RHS.size()==1){
        head = new ListNode<T>(RHS.head->getValue());
        tail = head;
        head->setPrev(0);
        tail->setNext(0);
        num_elements=1;
    } else {
        //create the first node
        head = new ListNode<T>(RHS.head->getValue());
        tail = head;
        head->setPrev(0);
        num_elements=1;

        //create the rest of the nodes
        ListNode<T>* curr=RHS.head;
        int i=RHS.size()-2;

        while (i>=0){
            curr=curr->getNext();
            add(curr->getValue());
            i--;
        }
    }


}

template <class T>
void LinkedList<T>::add(T& d){
    //if the List is empty
    if (head == 0){
        head = new ListNode<T>(d);
        tail = head;
        num_elements = 1;
    } else {
        //if nodes already exist

        //make a new one
        ListNode<T>* temp = new ListNode<T>(d);
        tail -> setNext(temp);
        tail->getNext()->setPrev(tail);
        tail = tail -> getNext();
        num_elements+=1;
    }

}

template <class T>
void LinkedList<T>::addToFront(T d){
    //if the List is empty
    if (head == 0){
        head = new ListNode<T>(d);
        tail = head;
        num_elements = 1;
    } else {
        //if nodes already exist
        //make a new one at the front of the list
        head->setPrev(new ListNode<T>(d));
        head->getPrev()->setNext(head);
        head = head->getPrev();
        head->setPrev(0);
        num_elements+=1;
    }

}

template<class T>
T LinkedList<T>::get(int element) const{
    //if the list is empty
    if (num_elements==0){
        return T();
    }

    ListNode<T>* curr = head;
    for (int i=0; i<element; i++){
        curr=curr->getNext();
    }
    return curr->getValue();
}

template<class T>
int LinkedList<T>::size() const{
    return num_elements;
}

template<class T>
bool LinkedList<T>::isEmpty(){
    if (num_elements==0){
        return true;
    }
    return false;

}

template<class T>
T LinkedList<T>::remove(int loc){
    if (num_elements==0){
        //list is empty
        head = 0;
        tail = 0;
        return T();
    }
    //only element in the list
    if (num_elements==1){
        T temp = tail->getValue();
        delete tail;
        head = 0;
        tail = 0;
        num_elements=0;
        return temp;
    } else if (loc==0) {
        //it's the head
        T temp = head->getValue();
        head = head->getNext();
        delete head->getPrev();
        head->setPrev(0);
        num_elements-=1;
        return temp;
    } else if (loc==num_elements-1) {
        //it's the tail
        T temp = tail->getValue();
        tail = tail->getPrev();
        delete tail->getNext();
        tail->setNext(0);
        num_elements-=1;
        return temp;
    } else {
        //it's somewhere in the middle
        ListNode<T>* curr = head;
        for (int i=0; i<loc; i++){
            curr = curr->getNext();
        }
        curr->getPrev()->setNext(curr->getNext());
        curr->getNext()->setPrev(curr->getPrev());
        T temp = curr->getValue();
        delete curr;
        num_elements-=1;
        return temp;
    }

    return T();
}

template<class T>
T& LinkedList<T>::operator[] (int loc){
    ListNode<T>* curr = head;
    for (int i=0; i<loc; i++){
        curr=curr->getNext();
    }
    return (curr->getValue());
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& RHS){
    head = 0;
    tail = 0;
    num_elements = 0;

    //if RHS has a size of 1
    if (RHS.size()==1){
        head = new ListNode<T>(RHS.head->getValue());
        tail = head;
        head->setPrev(0);
        tail->setNext(0);
        num_elements=1;
    } else {
        //create the first node
        head = new ListNode<T>(RHS.head->getValue());
        tail = head;
        head->setPrev(0);
        num_elements=1;

        //create the rest of the nodes
        ListNode<T>* curr=RHS.head;
        int i=RHS.size()-2;

        while (i>=0){
            curr=curr->getNext();
            add(curr->getValue());
            i--;
        }
    }
    return *this;
}

template <class T>
LinkedList<T>::~LinkedList(){

    if (head == 0){
        //empty list, nothing to delete
        tail = 0;
        num_elements=0;
    } else {
        while (head!=0){
            remove(0);
        }

        num_elements=0;
        tail = 0;
        head = 0;
    }
}


#endif
