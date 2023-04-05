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
    std::string _num_A;

public:
    /*
        Constructors

        BigNum() {}
        -> A default constructor
        BigNum(std::string)
        -> Copy std::string to the local std::string _num_A
        BigNum(int32_)

        Format
    */
    BigNum() {}
    BigNum(std::string _init_num)
    {
        this->_num_A = _init_num;
    }
    BigNum(int64_t _i64_num) 
    {
        while (_i64_num != 0)
        {
            int8_t __digit = _i64_num % 10;
            this->_num_A = char(__digit + (int8_t)(48)) + this->_num_A;
            _i64_num /= 10;
        }
    }

    std::string get()
    {
        return this->_num_A;
    }

    ~BigNum() {}
};