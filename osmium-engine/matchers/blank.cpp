#include "blank.h"

namespace osmium 
{
namespace matchers 
{
    bool blank::match(std::vector<ref<value>> target, bindings matched) const  
    {
        if (target.size() == 0) return false; 
        for (auto it = matched.begin(); it != matched.end(); ++it) 
        {
            if (it->first == sym_) 
            {
                if (it->second->compare(target.at(0))!=0) return false; 
            }
        }
        matched.push_back(std::make_pair(sym_, target.at(0)));
        target.erase(target.begin(), target.begin() + 1);
        return next()->match(target, matched);
    }
}
}