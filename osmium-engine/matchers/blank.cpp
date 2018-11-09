#include "blank.h"

namespace osmium 
{
namespace matchers 
{
    bool blank::match(std::vector<ref<value>> target, bindings matched) const  
    {
        if (target.empty()) return false; 
        for (auto& it : matched)
        {
            if (it.first == sym_) 
            {
                if (it.second->compare(target.at(0))!=0) return false; 
            }
        }
        matched.push_back(std::make_pair(sym_, target.at(0)));
        target.erase(target.begin(), target.begin() + 1);
        return next()->match(target, matched);
    }
}
}