#include "Biginteger.h"

BigInteger ::BigInteger()
{
    data_ = NULL;
    size_ = 0;
}

BigInteger ::BigInteger(const string &number)
{
    data_ = NULL;
    size_ = 0;
    data_ = new int[number.size()];
    int j = 0;
    for (int i = number.size() - 1; i >= 0; i--)
    {
        data_[j] = number[i] - '0';
        j++;
    }
    size_ = number.size();
}

BigInteger ::BigInteger(const BigInteger &other)
{
    data_ = NULL;
    size_ = other.size_;
    data_ = new int[size_];
    for (int i = 0; i < size_; i++)
    {
        data_[i] = other.data_[i];
    }
}

BigInteger operator+(const BigInteger &left,
                     const BigInteger &right)
{
    BigInteger copy;
    if (left.size_ < right.size_)
    {
        copy.size_ = right.size_ + 1;
        copy.data_ = new int[copy.size_];
        copy.data_[copy.size_ - 1] = 0;
        for (int i = 0; i < right.size_; i++)
        {
            if (i < left.size_)
            {
                copy.data_[i] = left.data_[i] + right.data_[i];
            }
            else
            {
                copy.data_[i] = right.data_[i];
            }
        }
        for (int i = 0; i < right.size_; i++)
        {
            if (copy.data_[i] >= 10)
            {
                copy.data_[i + 1]++;
                copy.data_[i] -= 10;
            }
        }
    }
    else
    {
        copy.size_ = left.size_ + 1;
        copy.data_ = new int[copy.size_];
        copy.data_[copy.size_ - 1] = 0;
        for (int i = 0; i < left.size_; i++)
        {
            if (i < right.size_)
            {
                copy.data_[i] = left.data_[i] + right.data_[i];
            }
            else
            {
                copy.data_[i] = left.data_[i];
            }
        }
        for (int i = 0; i < left.size_; i++)
        {
            if (copy.data_[i] >= 10)
            {
                copy.data_[i + 1]++;
                copy.data_[i] -= 10;
            }
        }
    }
    return copy;
}

// promise left >= right
BigInteger operator-(const BigInteger &left,
                     const BigInteger &right)
{
    BigInteger copy;
    copy.size_ = left.size_;
    copy.data_ = new int[left.size_];
    for (int i = 0; i < left.size_; i++)
    {
        if (i < right.size_)
        {
            copy.data_[i] = left.data_[i] - right.data_[i];
        }
        else
        {
            copy.data_[i] = left.data_[i];
        }
    }
    for (int i = 0; i < left.size_; i++)
    {
        if (copy.data_[i] < 0)
        {
            copy.data_[i + 1]--;
            copy.data_[i] += 10;
        }
    }
    return copy;
}

ostream &operator<<(ostream &out, const BigInteger &Bint)
{
    int key = 0;
    for (int i = Bint.size_ - 1; i >= 0; i--)
    {
        if (Bint.data_[i] != 0)
            key = 1;
        if (Bint.data_[i] == 0 && key == 0)
            continue;
        out << Bint.data_[i];
    }
    int j;
    for (j = 0; j < Bint.size_; j++)
    {
        if (Bint.data_[j] != 0)
            break;
    }
    if (j == Bint.size_)
    {
        out << 0;
    }
    return out;
}

BigInteger ::~BigInteger()
{
    if (data_ != NULL)
        delete[] data_;
}