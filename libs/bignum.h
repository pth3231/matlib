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
    BigNum() {}
    BigNum(std::string _init_num)
    {
        this->_num_A = _init_num;
    }
    BigNum(int64_t _i64_num) 
    {
        // Emptying string
        this->_num_A = "";
        
        // Specify the sign of that number and choosing the _factor
        int16_t _factor = ((_i64_num % 10) < 0) ? -1 : 1;

        // Iterate until _i64_num == 0
        while (_i64_num != 0)
        {
            int16_t _digit = _i64_num % 10 * _factor;           // Split the first digit of _i64_num
            this->_num_A = char(_digit + 48) + this->_num_A;    // Convert and concatnate to the std::string _num_A
            _i64_num /= 10;                                     // Remove current digit of _i64_num
        }

        // Adding the sign '-' based on _factor's value
        if (_factor == -1)
            this->_num_A = '-' + this->_num_A;
    }
    BigNum(double _db_num)
    {
        this->_num_A = std::to_string(_db_num);
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
    */
    std::string get()
    {
        return this->_num_A;
    }
    void        set(std::string _set_num)
    {
        this->_num_A = _set_num;
    }
    void        set(int64_t _i64_num)
    {
        // Emptying string
        this->_num_A = "";
        
        // Specify the sign of that number and choosing the _factor
        int16_t _factor = (_i64_num < 0) ? -1 : 1;

        // Iterate until _i64_num == 0
        while (_i64_num != 0)
        {
            int16_t _digit = _i64_num % 10 * _factor;           // Split the first digit of _i64_num
            this->_num_A = char(_digit + 48) + this->_num_A;    // Convert and concatnate to the std::string _num_A
            _i64_num /= 10;                                     // Remove current digit of _i64_num
        }

        // Adding the sign '-' based on _factor's value
        if (_factor == -1)
            this->_num_A = '-' + this->_num_A;
    }
    void        set(double _db_num)
    {
        // Specify the sign of _db_num and choosing the suitable _factor
        int16_t _factor = (_db_num < 0) ? -1 : 1;

        // Built-in std::to_string() to convert double to string
        this->_num_A = std::to_string(_db_num * _factor);
        if (_factor == -1)
            this->_num_A = '-' + this->_num_A;
    }

    /*BigNum add(BigNum *_num_A, BigNum *_num_B)
    {

    }*/

    ~BigNum() {}
};