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
	    virtual ~matcher() = default;
	    explicit matcher(matcher* next) : next_(next), matched_(nullptr) {}
        matcher* next() const {return next_;}
        virtual bool match(const std::vector<ref<value>>& target, bindings& matched) = 0;
		ref<value> get_matched() const { return matched_; }
		void set_matched(const ref<value>& matched) { matched_ = matched; }
    private:
        matcher* next_;
		ref<value> matched_;
    };
}