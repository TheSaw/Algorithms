#ifndef ALGORITHMS_SELECT_H_
#define ALGORITHMS_SELECT_H_

#include <vector>

#include "sort.h"

namespace select {

template <typename T>
T select_quick(std::vector<T> &v, int p, int r, int i) {
    if (p == r) {
        return v[p];
    }

    int q = sort::_rand_partition(v, p, r);

    if (i == q) {
        return v[q];
    }
    else if (i < q) {
        return select_quick(v, p, q - 1, i);
    }
    else
        return select_quick(v, q + 1, r, i);
}

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



} // namespace select

#endif ALGORITHMS_SELECT_H_