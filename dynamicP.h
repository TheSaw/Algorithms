#ifndef ALGORITHMS_DYNAMICP_H_
#define ALGORITHMS_DYNAMICP_H_

#include <unordered_map>
#include <algorithm>

long long fib_recursive(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return fib_recursive(n - 1) + fib_recursive(n - 2);
    }
}

long long fib_DP_helper(int n, std::unordered_map<int, long long> &m)
{
    auto got = m.find(n);
    if (got == m.end())
    {
        long long result = 0;
        if (n <= 2) 
        {
            result = 1;
        }
        else
        {
            result = fib_DP_helper(n - 1, m) + fib_DP_helper(n - 2, m);
        }
         
        m.insert(std::make_pair(n, result));
        return result;
    }
    else
    {
        return got->second;
    }
}

long long fib_DP_memo(int n)
{
    std::unordered_map<int, long long> m;
    return fib_DP_helper(n, m);
}

long long fib_DP_bottomup(int n)
{
    std::unordered_map<int, long long> m;
    
    for (int i = 1; i <= n; ++i)
    {
        if (i <= 2)
        {
            m.insert(std::make_pair(i, 1));
        }
        else
        {
            auto prev1 = m.find(i - 1);
            auto prev2 = m.find(i - 2);
            long long newnum = prev1->second + prev2->second;
            m.insert(std::make_pair(i, newnum));

            if (i == n)
            {
                return newnum;
            }
        }        
    }

    return -1;
}

int bestCut(const std::vector<int> &prices, int n)
{
    int max = -1;
    static std::unordered_map<int, int> best;    

    if (n == 0)
    {
        return 0;
    }
    else
    {        
        auto got = best.find(n);
        if (got != best.end())
        {
            return got->second;
        }

        for (int i = 0; i < n; ++i)
        {
            max = std::max(max, prices[i] + bestCut(prices, n - i - 1));
        }
    }
    
    best.insert(std::make_pair(n, max));
    return max;
}

int bestCut_bottomup(const std::vector<int> &prices, int n)
{
    int max = INT_MIN;
    std::vector<int> best;
    best.resize(n);
    best[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        best[i] = prices[n - i] + best[i];
    }

    return -1;
    // todo
}

template <typename T>
int LongestIncreasingSubsequence(const std::vector<T> &v)
{
    std::vector<int> a;
    a.resize(v.size(), 1);    
    int max = -1;

    for (int i = 1; i < v.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (v[j] < v[i])
            {
                a[i] = std::max(a[i], a[j] + 1);
                max = std::max(max, a[i]);
            }
        }
    }

    return max;
}

template <typename T>
std::pair<int, int> maxValueSequence(const std::vector<T> &v)
{
    for (int i = 1; i < v.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            std::cout << "Sum of " << j << " --> " << i << std::endl;
        }
    }

    return std::pair<int, int>(1, 2);
}

#endif ALGORITHMS_DYNAMICP_H_