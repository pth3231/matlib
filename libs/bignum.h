/*
    File:       BIGNUM.h
    Author:     HGanyu
    Date:       5/4/2023
    Lastmod:    5/4/2023 
    Description:
    A C++ header which declare methods for supporting large integers calculation.
    Based on many operation of std::string, which has the dynamically expanding size.
*/

#pragma once
#include <string>

class BigNum {
private:
    std::string _num_A;

    void    _SET_FLOATING_(const uint32_t _PRECISION)
    {
        uint32_t iter = this->_num_A.length() - 1;
        while (_PRECISION) {}
    }

public:
    /*
        CONSTRUCTOR

        1. BigNum() {}
            - A default constructor
            - Time complexity: O(1)
        2. BigNum(std::string)
            - Copy std::string to the local std::string _num_A
            - Time complexity: O(1)
        3. BigNum(int64_t)
            - Copy every digits of the numbers and assigns it to std::string _num_A
            - Time complexity: O(logn) (logarithm base 10) 
    */
    BigNum()
    {
        this->_num_A = "0";
    }
    BigNum(std::string _init_num)
    {
        this->_num_A = _init_num;
    }
    BigNum(double _db_num)
    {
        // Specify the sign of _db_num and choosing the suitable _factor
        int16_t _factor = (_db_num < 0) ? -1 : 1;

        // Built-in std::to_string() to convert double to string
        this->_num_A = std::to_string(_db_num * _factor);
        if (_factor == -1)
            this->_num_A = '-' + this->_num_A;
    }
    /*
        BASIC GET/SET

        1. std::string get()
            - Return back current value of std::string _num_A
            - Time complexity: O(1)
        2. void set(std::string)
            - Change std::string _num_A by copying the value of std::string _set_num to std::string _num_A
            - Time complexity: O(1)
        3. void set(int64_t)
            - Change std::string _num_A by spliting, changing and concatnate back to std::string _num_A
            - Time complexity: O(logn) (logarithm base 10)
        4. void set(double)
            - Change std::string _num_A by using standard function of STL C++
            - Required >C++11
            - Just have 6 floating point decisions
            - Time complexity: depend on std::to_string() time complexity.
        5. BigNum& operator=()
    */
    std::string get()
    {
        return this->_num_A;
    }
    void        set(std::string _set_num)
    {
        this->_num_A = _set_num;
    }
    void        set(double _db_num, bool _IGNORE_FLOATING_POINTS = false)
    {
        // Specify the sign of _db_num and choosing the suitable _factor
        int16_t _factor = (_db_num < 0) ? -1 : 1;

        // Built-in std::to_string() to convert double to string
        this->_num_A = std::to_string(_db_num * _factor);
        if (_factor == -1)
            this->_num_A = '-' + this->_num_A;

        // _IGNORE_FLOATING_POINTS flag = true
        if (_IGNORE_FLOATING_POINTS)
            for (int i = 0; i < 7; i++)
                this->_num_A.pop_back();    // Pop_back() all the six-digit and a point (xxx.123456)
    }
    void        set(BigNum &_BN_num)
    {
        this->_num_A = _BN_num.get();
    }
    
    friend bool operator> (const BigNum &_BN_A, const BigNum &_BN_B)
    {
        uint64_t len_A = _BN_A._num_A.length() - 1;
        uint64_t len_B = _BN_B._num_A.length() - 1;
        if (len_A == len_B)
        {
            for (uint64_t iter = 0; iter < len_A; ++iter)
                if ( (int16_t)(_BN_A._num_A[iter]) - 48 < (int16_t)(_BN_B._num_A[iter]) - 48 )
                    return false;
            return true;
        }
        else return len_A > len_B;
    }
    friend bool operator< (const BigNum &_BN_A, const BigNum &_BN_B)
    {
        uint64_t len_A = _BN_A._num_A.length() - 1;
        uint64_t len_B = _BN_B._num_A.length() - 1;
        if (len_A == len_B)
        {
            for (uint64_t iter = 0; iter < len_A; ++iter)
                if ( (int16_t)(_BN_A._num_A[iter]) - 48 > (int16_t)(_BN_B._num_A[iter]) - 48 )
                    return false;
            return true;
        }
        else return len_A < len_B;
    }
    BigNum&     operator= (const std::string &_set_num)
    {
        this->set(_set_num);
        return *this;
    }
    BigNum&     operator= (const double _db_num)
    {
        this->set(_db_num, false);
        return *this;
    }
    BigNum&     operator= (const BigNum &_BN_result)
    {
        this->_num_A = _BN_result._num_A;
        return *this;
    }
    
    BigNum  BN_max(const BigNum _num_A, const BigNum _num_B) const
    {
        return (_num_A > _num_B) ? _num_A : _num_B;
    }

    /*BigNum add(BigNum *_num_A, BigNum *_num_B)
    {
        BigNum *_BN_result = new BigNum();
        //uint32_t iter = max()
    }*/

    ~BigNum() {}
};