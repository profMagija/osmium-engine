
#include "repeated.h"

#include "lambda_matcher.h"

namespace osmium 
{
namespace matchers 
{
    bool repeated::match(const std::vector<ref<value>> &target, bindings& matched) 
    {
        std::shared_ptr<matcher> current;
        std::shared_ptr<matcher> old = nullptr; 
        if (allow_null_) 
        {
            current = next()->clone(next()->next());
        }
        else 
        {
            current = pattern_->clone(this->next());
        }
        while (current->match(target, matched)) 
        {
            old = current; 
            if (old) 
            {
                auto already_matched = get_matched();
                already_matched.insert(already_matched.end(),
                    old->get_matched().begin(), 
                    old->get_matched().end()
                );
                set_matched(already_matched);
            }
            current = current->clone(current.get());
        }
        if (old) return true; 
        else return false; 

    }
    std::shared_ptr<matcher> repeated::clone(matcher* next) const 
    {
        return std::shared_ptr<matcher>(new repeated(this->pattern_, next, this->allow_null_));
    }
}
}