#include "blank.h"

namespace osmium 
{
namespace matchers 
{
    bool blank::match(ref<value> pattern, std::vector<ref<value>> target) const  
    {
        return false; // TODO needs to be implemented
    }
}
}