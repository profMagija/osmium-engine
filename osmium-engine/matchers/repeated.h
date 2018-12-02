#pragma once 

#include "../matcher.h" 

namespace osmium 
{
namespace matchers 
{
    class repeated : public matcher 
    {
    public:
        explicit repeated(matcher* pattern, matcher* next, bool allow_null = false) 
            : pattern_(pattern), matcher(next), allow_null_(allow_null) {}

        bool match(const std::vector<ref<value>>&, bindings& matched);
        std::shared_ptr<matcher> clone(matcher* next) const override; 
    private:
        matcher* pattern_;
        bool allow_null_;
    };
}
}