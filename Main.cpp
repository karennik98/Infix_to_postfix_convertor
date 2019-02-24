#include "Convert.h"
#include "Exception.h"

#include <iostream>

int main()
{
    while(true)
    {
        std::string input;
        std::cin>>input;
        Convert convert(input);
        try
        {
            convert.infix_to_postfix();
        }
        catch(WrongItem& e)
        {
            std::cout<<e.get_info()<<std::endl;
            exit(-1);
        }
        std::cout<<convert.getStream().str()<<std::endl;
    }
    return 0;
}