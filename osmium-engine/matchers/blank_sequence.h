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
        bool match(const std::vector<ref<value>> &target, bindings& matched) override; 
        std::shared_ptr<matcher> clone(matcher* next) const override; 
    private:
        bool allow_null_; 
    };
}
}