
#include "repeated.h"

#include "lambda_matcher.h"

namespace osmium 
{
namespace matchers 
{
    bool repeated::match(const std::vector<ref<value>> &target, bindings& matched) 
    {
        // TODO still does not work properly 
        if (allow_null_)
        {

            pattern_->set_next(this);
            if (! pattern_->match(target, matched)) 
                return next()->match(target, matched);
            else 
            {
                set_matched(pattern_->get_matched());
                return true;
            }

        } else {
            
        }
    }
}
}