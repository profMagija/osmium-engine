#pragma once

#include <vector>
#include <list>
#include <utility>
#include "value.h"
#include "symbol.h"

namespace osmium 
{
    using bindings = std::list<std::pair<symbol, ref<value>>>;
    class matcher 
    {
    public:
        matcher(matcher* next) : next_(next) {}
        matcher* next() const {return next_;}
        virtual bool match(std::vector<ref<value>> target, bindings matched) const =0;
    private:
        matcher* next_;
    };
}