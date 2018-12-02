#pragma once 

#include <utility>
#include "../matcher.h"

namespace osmium
{
namespace matchers
{
    class blank : public matcher 
    {
    public:
		blank(ref<value> head, matcher* next);
		explicit blank(matcher* next) : blank(nullptr, next) {}
        bool match(const std::vector<ref<value>> &target, bindings& matched) override; 
        std::shared_ptr<matcher> clone(matcher* next) const override; 
        
    private:
        ref<value> head_; 
    };
}
}