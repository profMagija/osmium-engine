#pragma once 

#include "../matcher.h"

namespace osmium
{
namespace matchers
{
    class blank : public matcher 
    {
    public:
        blank(symbol sym, matcher* next) : matcher(next), sym_(sym) {} 
        bool match(std::vector<ref<value>> target, bindings matched) const override;
    private:
        symbol sym_; 
    };
}
}