#ifndef ALGORITHMS_SORTING_H_
#define ALGORITHMS_SORTING_H_

#include <chrono>
#include <cmath>
#include <list>
#include <random>
#include <vector>

#include "utils.h"

namespace sorting {

template <typename T>
void sort_insertion(std::vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = i; j > 0 && v[j] < v[j - 1]; j--) {
            std::swap(v[j], v[j - 1]);
        }
    }
}

template <typename T>
void _mergearrays(const std::vector<T> &left, const std::vector<T> &right, std::vector<T> &v) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            v[k++] = left[i++];
        }
        else {
            v[k++] = right[j++];
        }
    }

    while (i < left.size()) {
        v[k++] = left[i++];
    }

    while (j < right.size()) {
        v[k++] = right[j++];
    }
}

template <typename T>
void sort_merge(std::vector<T> &v) {
    if (v.size() < 2) {
        return;
    }

    int mid = v.size() / 2;
    std::vector<T> left(v.begin(), v.begin() + mid);
    std::vector<T> right(v.begin() + mid, v.begin() + (v.size()));

    sort_merge(left);
    sort_merge(right);
    _mergearrays(left, right, v);
}

template <typename T>
void _siftDown(std::vector<T> &v, int start, int end) {
    int root = start;
    while (root * 2 + 1 <= end) {
        int child = root * 2 + 1;
        int swap = root;
        if (v[swap] < v[child]) {
            swap = child;
        }
        if (child + 1 <= end && v[swap] < v[child + 1]) {
            swap = child + 1;
        }
        if (swap == root) {
            return;
        }
        else {
            std::swap(v[root], v[swap]);
            root = swap;
        }
    }
}

template <typename T>
void _heapify(std::vector<T> &v) {
    int start = std::ceil((v.size() - 1) / 2);
    while (start >= 0) {
        siftDown(v, start, v.size() - 1);
        start--;
    }
}

template <typename T>
void sort_heap(std::vector<T> &v) {
    heapify(v);
    int end = v.size() - 1;
    while (end > 0) {
        std::swap(v[end], v[0]);
        end--;
        siftDown(v, 0, end);
    }
}

template <typename T>
int _partition(std::vector<T> &v, int p, int r) {
    int i = p - 1;
    std::swap(v[r], v[utilities::random(p, r)]);
    for (int j = p; j < r; j++) {
        if (v[j] < v[r]) {
            std::swap(v[++i], v[j]);
        }
    }

    std::swap(v[i + 1], v[r]);
    return i + 1;
}

template <typename T>
void sort_quick(std::vector<T> &v, int p, int r) {
    if (p < r) {
        int q = _partition(v, p, r);
        sort_quick(v, p, q - 1);
        sort_quick(v, q + 1, r);
    }
}

template <typename T>
void _limitedquick(std::vector<T> &v, int p, int r, int k) {
    if (r - p > k) {
        int q = partition(v, p, r);
        _limitedquick(v, p, q - 1, k);
        _limitedquick(v, q + 1, r, k);
    }
}

template <typename T>
void sort_quickinsertion(std::vector<T> &v, int p, int r) {
    const int k = 500; // treshold 
    limitedquick(v, p, r, k);
    sort_insertion(v);
}

template <typename T>
void sort_radix(std::vector<T> &v) {
    const int maxdig = 10;

    for (int k = 1; k <= maxdig; ++k) {
        std::vector<std::list<int>> temp;
        temp.resize(10);

        for (int i = 0; i < v.size(); ++i) {
            temp[getDigit(v[i], k)].push_back(v[i]);
        }

        v.clear();

        for (int i = 0; i <= 9; ++i) {
            for (auto j : temp[i]) {
                v.push_back(j);
            }
        }
    }
}


} // namespace sorting

#endif ALGORITHMS_SORTING_H_
