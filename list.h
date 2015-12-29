#ifndef ALGORITHMS_LIST_H_
#define ALGORITHMS_LIST_H_

#include <iostream>

template <class O>
class list_object {
public:
    list_object<O>();
    O data;
    list_object* next;
    
    list_object<O> operator++();
};


template <class O>
inline list_object<O> list_object<O>::operator++() {
    data = next->data;
    next = next->next;
    return *this;
}

template <class O>
inline list_object<O>::list_object()
{
}


template <class T> 
class list {
public:
    int push_back(T element);
    T pop_front();
    T peek_front();
    void insert(T element, int index);
    void delete_index(int index);
    int search(T target);
    void clear();
    int size() { return count; }

    list<T>();
    ~list<T>();

private:
    list_object<T>* skip2index(int index);

    int count;
    list_object<T> *head;
    list_object<T> *tail;

};

template <class T>
list<T>::list()
    :count(0), head(NULL), tail(NULL)
{

}

template <class T>
list<T>::~list() {
    clear();
}

template <class T>
void list<T>::clear() {
    while (count > 0) {
        pop_front();
    }
}

template <class T>
int list<T>::push_back(T data) {
    list_object<T> *elem = new list_object<T>();
    elem->data = data;
    if (0 == count) {
        head = elem;
        tail = elem;
    }
    else {
        tail->next = elem;
        tail = elem;
    }
    
    return ++count;
}

template <class T>
T list<T>::pop_front() {
    if (count > 0) {
        list_object<T> *temp = head;
        head = head->next;
        T data = temp->data;
        delete temp;
        --count;
        return data;
    }
	else {
		return -1;
	}
}

template <class T>
T list<T>::peek_front() {
    return count <= 0 ? nullptr : head;
}

template <class T>
void list<T>::delete_index(int index) {
    if (index < count)
    {
        list_object<T> *obj = skip2index(--index);
        if (obj != nullptr)
        {
            list_object<T> *del = obj->next;
            obj = del->next;
            delete del;
        }
    }
}

template <class T> 
void list<T>::insert(T element, int index) {
    list_object<T> *elem = new list_object<T>();
}

template <class T>
int list<T>::search(T target) {
    if (0 == count) {
        return -1;
    }
    list_object<T> *elem = head;
    int i = 0;
    while (elem->next != NULL) {
        if (elem->data == target) {
            return i;
        }
        elem = elem->next;
        ++i;
    }
    return -1;
}

template <class T>
list_object<T>* list<T>::skip2index(int index) {
    if (index >= count)
    {
        return nullptr;
    }
    else
    {
        list_object<T> *obj = head;
        for (int i = 0; i < index; ++i)
        {
            ++obj;
        }

        return obj;
    }
}


#endif ALGORITHMS_LIST_H_
