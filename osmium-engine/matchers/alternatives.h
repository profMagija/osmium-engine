#pragma once 

#include "../matcher.h"

namespace osmium 
{
namespace matchers 
{
    class alternatives : public matcher 
    {
    public:
        explicit alternatives(std::vector<matcher*> patterns, matcher* next) 
            : matcher(next), patterns_(patterns) {}; 
        bool match(const std::vector<ref<value>>&, bindings&);
        std::shared_ptr<matcher> clone(matcher* next) const override;
    private: 
        std::vector<matcher*> patterns_; 
    };
}
}