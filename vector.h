#ifndef VECTOR
#define VECTOR

template<class T>
class Vector{

public:

    Vector();
    Vector(int);
    Vector(const Vector<T>&);

    void add(T);
    void add(T, int);

    //returns the element at the passed position in the vector
    T get(int) const;

    //returns the last element in the vector
    T back();


    //returns how many elements are currently stored in the vector
    int size() const;
    //returns the current capacity of the vector
    int capacity();
    void sort();
    void remove(int index);
    //exchange contents of two elements in a vector
    void swap(int, int);

    T& operator[](int) const;
    bool operator==(T);
    bool operator==(const Vector<T>&);
    bool operator!=(T);
    bool operator!=(const Vector<T>&);
    Vector<T>& operator=(const Vector<T>&);
    Vector<T>& operator+=(T);

    ~Vector();

private:
    int maxcap; //the current capacity of the vector
    int csize; //the current size of the vector
    T* vec;   // the vectors
    T* loc; //points to the current location on the vector

    void resize();

};

template<class T>
Vector<T>::Vector(){
    maxcap=10; //vector initialized with 10 slots
    csize=0; //vector is initialized empty
    vec = new T[10];

}

template<class T>
Vector<T>::Vector(int psize){
    csize=0; //vector is initilized empty
    maxcap=psize; //vector is initialized with passed number of slots

    //empty vector with a capacity of psize
    vec = new T[maxcap];

}

template<class T>
Vector<T>::Vector(const Vector<T>& RHS){
    csize=RHS.csize;

    //if the # of elements is less than 10, maxcap=10
    if (csize<10){
        maxcap=10;
    }

    //otherwise maxcap=csize;
    maxcap=csize;

    //initialize vector
    vec= new T[maxcap];

    //copy over vector
    for (int i=0; i<csize; i++){
        vec[i]=RHS.vec[i];
    }

}


template<class T>
T Vector<T>::get(int RHS) const{
    return (vec[RHS]);
}

template<class T>
T Vector<T>::back(){
    return(vec[csize-1]);
}

template<class T>
void Vector<T>::add(T RHS){
    if (csize==maxcap){
        resize();
    }
    vec[csize]=RHS;
    //increase csize because an element was added
    csize+=1;
}

//overloaded add function
template<class T>
void Vector<T>::add(T RHS, int index){
    //if the vector will be at maxcap, resize it
    if (maxcap==(csize+1)){
        resize();
    }
    //if the given index would place the element at the end, stick it on the end
    if (index==csize){
        vec[index]=RHS;
        //increase csize because an element was added.
        csize+=1;
    }else{
        //otherwise shift everything up
        for (int i=csize-1; i>=index; i--){
            T temp = vec[i];
            vec[i+1]=temp;
        }
        //now replace the element located at index
        vec[index]=RHS;
        //increase csize because an element was added.
        csize+=1;
    }
}

template<class T>
int Vector<T>::size() const{
    return (csize);
}

template<class T>
int Vector<T>::capacity(){
    return (maxcap);
}

template<class T>
void Vector<T>::sort(){

    //bubble sort, order ascecnding

    for (int i=0; i<csize; i++){
        for(int j=0; j<csize-i-1; j++){

            if (vec[j]>vec[j+1]){
                //swap the elements
                swap(j, j+1);
            }
        }
    }



}

template<class T>
void Vector<T>::remove(int index){
    //shift everything down one
    for (int i=index; i<csize; i++){
        T temp = vec[i+1];
        vec[i]=temp;
    }

    //decrease csize because an element was removed.
    csize-=1;
}

template<class T>
void Vector<T>::swap(int first, int second){
    T temp = vec[first];

    vec[first] = vec[second];

    vec[second] = temp;
}

//if capacity is reached, vector grows at a rate of 1.5
template<class T>
void Vector<T>::resize(){
    if (maxcap==1){
        maxcap*=2;
    } else {
        maxcap*=1.5;
    }

    //initialize larger, temporary vector
    T* temp = new T[maxcap];

    //copy over original into larger
    for (int i=0; i<csize; i++){
        temp[i] = vec[i];
    }

    //delete the contents of the original vector
    delete[] vec;

    //have the pointer of the original point to the new vector
    vec = temp;
}

template<class T>
T& Vector<T>::operator[](int RHS) const{
    return vec[RHS];
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& RHS){
    delete[] vec;
    vec = new T[RHS.csize];
    csize=RHS.size();
    maxcap=RHS.size();

    for (int i=0; i<RHS.csize; i++){
        vec[i] = RHS.get(i);
    }


    return *this;
}

template<class T>
bool Vector<T>::operator== (const T RHS){
    //if strcomp is 0, they are the same
    if (vec[csize]==RHS){
        return true;
    }

    //otherwise
    return false;
}

template<class T>
bool Vector<T>::operator== (const Vector& RHS){

    if (vec[csize]==RHS.vec){
        return true;
    }

    //otherwise
    return false;
}

template<class T>
bool Vector<T>::operator!= (const T RHS){
    //if strcomp is 0, they are the same
    if (vec[csize]==RHS){
        return false;
    }

    //otherwise
    return true;
}

template<class T>
bool Vector<T>::operator!= (const Vector& RHS){

    if (vec[csize]==RHS.vec){
        return false;
    }

    //otherwise
    return true;

}

template<class T>
Vector<T>& Vector<T>::operator+=(T RHS){
    add(RHS);

    return *this;
}

template<class T>
Vector<T>::~Vector(){
    delete[] vec;
}

#endif
