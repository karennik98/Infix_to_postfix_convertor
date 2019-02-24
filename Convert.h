#ifndef CONVERT_H
#define CONVERT_H

#include "IConvert.h"

#include <string>
#include <stack>
#include <sstream>

namespace
{
    enum class Operators : char
    {
        Plus   = '+',
        Minus  = '-',
        Divide = '/',
        Add    = '*',
        Deegre = '^',
    };

    enum class Parenthes : char
    {
        Open  = '(',
        Close = ')',
    };
}

class Convert : public IConvert
{
public:
    Convert() = default;
    Convert(std::string str) : m_Str(str){}
    void infix_to_postfix();
    const std::ostringstream& getStream()const;
private:
    bool is_operator(const char& )const;
    bool is_operand(const char&)const;
    bool is_parenthes(const char&)const;
    int  op_value(const char& )const;
private:
    std::string m_Str;
    std::ostringstream m_stream;
    std::stack<char> m_opStack;
};

#endif 