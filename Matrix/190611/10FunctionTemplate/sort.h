#include <algorithm>

template <typename T, typename fun>
bool mySort(T f, T s, fun cmp)
{
    for (T i = f; i != s; i++)
        for (T j = i; j != s; j++)
        {
            if (!cmp(*i, *j))
                std::swap(*i, *j);
        }
}

template <typename T>
bool mySort(T f, T s)
{
    for (T i = f; i != s; i++)
        for (T j = i; j != s; j++)
        {
            if (*i > *j)
                std::swap(*i, *j);
        }
}