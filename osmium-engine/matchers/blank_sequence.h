#pragma once 

#include "../matcher.h" 

namespace osmium 
{
namespace matchers 
{
    class blank_sequence : public matcher 
    {
    public: 
        explicit blank_sequence(matcher* next, bool allow_null = false) 
            : matcher(next), allow_null_(allow_null) {}; 
        bool match(std::vector<ref<value>> target, bindings& matched); 

    private:
        bool allow_null_; 
    };
}
}