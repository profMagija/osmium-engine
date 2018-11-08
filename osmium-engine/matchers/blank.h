#pragma once 

#include "../matcher.h"

namespace osmium
{
namespace matchers
{
    class blank : public matcher 
    {
        bool match(ref<value> pattern, std::vector<ref<value>> target) const override;
    };
}
}