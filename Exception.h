#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

class WrongItem : public std::exception
{
public:
    WrongItem(std::string file, std::string func, unsigned line) 
            : m_line(line), m_file(file), m_func(func){} 
    std::string get_info()
    {
        return ("File: "+m_file="\nFunction: "+m_func+"\nLine: "+std::to_string(m_line));
    }
private:
    std::string m_file;
    unsigned m_line;
    std::string m_func;
};

#endif