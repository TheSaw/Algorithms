#ifndef ALGORITHMS_HASHTABLE_H_
#define ALGORITHMS_HASHTABLE_H_

#include <functional>
#include <string>
#include <vector>

template <class O>
class hashobject {
public:	
	hashobject<O>();
	hashobject<O>(size_t key, O value);

	size_t m_key;
	O m_value;
};

template <class O>
hashobject<O>::hashobject()
	: m_key(-1) {

}

template <class O>
hashobject<O>::hashobject(size_t key, O value)
	: m_key(key), m_value(value) {

}

template <class T>
class hashtable {
public:
	hashtable<T>();
	bool put(std::string key, T new_elem);
	T get(std::string key);
	bool remove(std::string );

private:	
	int reduce(size_t key);
	const size_t MAX_SIZE = 1001;
	std::vector<hashobject<T>> memory;
	bool badalloc;
};

template <class T>
hashtable<T>::hashtable()
	:badalloc(false) {
	memory.resize(MAX_SIZE);
}

template <class T>
bool hashtable<T>::put(std::string key, T new_elem) {	
    std::hash<std::string> hash_fn;
    size_t hash = hash_fn(key);
    hashobject<T> obj(hash, new_elem);
    unsigned int slot = reduce(hash);    
    unsigned int count = 0;
    while (memory[slot].m_key != -1) {

        // if key is the same, or deleted the overwrite
        if (memory[slot].m_key == hash && 
            memory[slot].m_key == 0) {
            memory[slot].m_value = new_elem;
            return true;
        }
        slot++;        
        if (slot >= MAX_SIZE) {
            slot = 0;
        }
        if (count >= MAX_SIZE) {
            return false;
        }
        count++;
    }
	memory[slot] = obj;
	return true;
}

template <class T>
T hashtable<T>::get(std::string key) {   
    std::hash<std::string> hash_fn;
    size_t hash = hash_fn(key);
    unsigned int slot = reduce(hash);
    
    if (memory[slot].m_key == -1) {
        return false;
    }
    else {
        int count = 0;
        while (memory[slot].m_key != hash) {
            slot++;
            if (slot >= MAX_SIZE) {
                slot = 0;
            }
            if (count >= MAX_SIZE) {
                return false;
            }
            count++;
        }
        if (memory[slot].m_key > 0) {
            return memory[slot].m_value;
        }
        else {
            return false;
        }

    }
}

template <class T>
bool hashtable<T>::remove(std::string key) {
    std::hash<std::string> hash_fn;
    size_t hash = hash_fn(key);
    unsigned int slot = reduce(hash);
    if (memory[slot].m_key == -1) {
        return false;
    }
    else {
        int count = 0;
        while (memory[slot].m_key != hash) {
            slot++;
            if (slot >= MAX_SIZE) {
                slot = 0;
            }
            if (count >= MAX_SIZE) {
                return false;
            }
            count++;
        }
        if (memory[slot].m_key > 0) {
            memory[slot].m_key = 0;
        }
        else {
            return false;
        }

    }
}

template <class T>
int hashtable<T>::reduce(size_t key) {
	return key % MAX_SIZE;
}

#endif ALGORITHMS_HASHTABLE_H_
