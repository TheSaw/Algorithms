#ifndef ALGORITHMS_SELECT_H_
#define ALGORITHMS_SELECT_H_

namespace select {

template <typename T>
int search_binary(const std::vector<T> &v, T key, int left, int right) {
    if (left > right) {
        return -1;
    }

    int middle = left + ((right - left) / 2);

    if (key == middle) {
        return middle;
    }

    if (key < middle) {
        return search_binary(v, key, left, middle - 1);
    }
    else if (key > middle) {
        return search_binary(v, key, middle + 1, right);
    }
}

template <typename T>
int search_linear(const std::vector<T> &v, T key) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == key) {
            return i;
        }
    }

    return -1;
}

}

#endif ALGORITHMS_SELECT_H_