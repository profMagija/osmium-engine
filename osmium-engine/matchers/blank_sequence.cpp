
#include "blank_sequence.h" 

namespace osmium 
{
namespace matchers 
{
    bool blank_sequence::match(std::vector<ref<value>> target, bindings& matched) 
    {
        auto it = allow_null_ ? target.begin() : target.begin()+1; 
        while (it != target.end()) 
        {
            bool m = next()->match(std::vector<ref<value>>(it, target.end()), matched);
            if (m)
            {
                set_matched(std::vector<ref<value>>(target.begin(), it));
                return true; 
            }
            it++; 

        }
        return false; 
        

    }
}
}