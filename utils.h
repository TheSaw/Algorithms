#ifndef ALGORITHMS_UTILITIES_H_
#define ALGORITHMS_UTILITIES_H_

#include <chrono>
#include <cmath>
#include <list>
#include <random>
#include <vector>

namespace utilities 
{

int getDigit(int n, int k) {
    int temp = (n % (int)std::pow(10, k) / std::pow(10, k - 1));
    return temp;
}

int random(int min, int max) {
  std::random_device rd;
  std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(min, max);

	return dist(mt);
}

template <typename T>
void vector_permuteRandom(std::vector<T> &v) {
	for (int i = 0; i < v.size() - 1; ++i) 	{
		std::swap(v[i], v[random(i, v.size() - 1)]);
	}
}

template <typename T>
void vector_fillRandom(std::vector<T> &v, int min, int max, int count) {
  v.resize(count);
	for (int i = 0; i < count; ++i) 	{
		v[i] = (random(min, max));
	}
}

template <typename T>
void vector_fillSorted(std::vector<T> &v, int count) {
    v.resize(count);
	for (int i = 0; i < count; ++i) {
		v[i] = i;
	}
}

template <typename T>
bool vector_checksorted(const std::vector<T> &v) {
	for (auto it = v.begin(); it != v.end() - 1; ++it) {
		if (*it > *(it + 1)) {
			return false;
		}
	}

	return true;
}

template <typename T>
void vector_print(const std::vector<T> &v) {
	for (auto i = v.begin(); i != v.end(); i++) 	{
		std::cout << *i << "  ";
	}
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
	for (int i = 0; i < v.size(); ++i) 	{
		if (v[i] == key) {
			return i;
		}
	}

	return -1;
}



////////////////
} //namespace

#endif ALGORITHMS_UTILITIES_H_
