#include "alternatives.h" 


namespace osmium
{

namespace matchers
{

    bool alternatives::match(const std::vector<ref<value>> &target, bindings& matched) 
    {
        for (auto& it : patterns_) 
        {
            it->set_next(next()); 
            if (it->match(target, matched)) 
            {
                set_matched(it->get_matched()); 
                return true; 
            }
        }
        return false; 
    }

} // matchers

} // osmium
