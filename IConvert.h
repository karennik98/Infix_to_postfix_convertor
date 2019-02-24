#ifndef ICONVERT_H
#define ICONVERT_H

class IConvert
{
public:
    virtual void infix_to_postfix() = 0;
    virtual bool is_operator(const char& )const = 0;
    virtual bool is_operand(const char&)const = 0;
    virtual bool is_parenthes(const char&)const = 0;
};

#endif