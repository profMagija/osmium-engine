#pragma once 

#include "../matcher.h" 

namespace osmium 
{
namespace matchers 
{
    class blank_sequence : public matcher 
    {
    public: 
        explicit blank_sequence(matcher* next) : matcher(next) {}; 
        bool match(std::vector<ref<value>> target, bindings& matched); 

    };
}
}