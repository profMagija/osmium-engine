#pragma once

#include <vector>

#include "value.h"

namespace osmium 
{
    class matcher 
    {
    public:
        matcher(matcher* next) : next_(next) {}
        virtual bool match(ref<value> pattern, std::vector<ref<value>> target) const =0;
    private:
        matcher* next_;
    }
}