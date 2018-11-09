
#include "repeated.h"

#include "lambda_matcher.h"

namespace osmium 
{
namespace matchers 
{
    bool repeated::match(const std::vector<ref<value>> &target, bindings& matched) 
    {
        pattern_->set_next(this);
        if (! pattern_->match(target, matched)) return next()->match(target, matched);
        else 
        {
            return true;
        }
    }
}
}