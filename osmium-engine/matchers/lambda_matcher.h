#pragma once 

#include "../matcher.h"

#include <functional>

namespace osmium 
{
namespace matchers 
{
    class lambda_matcher : public matcher 
    {
    public:
        explicit lambda_matcher(
                std::function<bool (matcher*, const std::vector<ref<value>>&, bindings&)> fun, 
                matcher* next) 
            : matcher(next) 
        {
            this->fun_ = fun; 
        } 
        bool match(const std::vector<ref<value>> &target, bindings& matched) override 
        {
            return fun_(next(), target, matched);
        }
        std::shared_ptr<matcher> clone(matcher* next) const override
        {
            return std::shared_ptr<matcher>(new lambda_matcher(this->fun_, next));
        }
    private:
        std::function<bool (matcher*, const std::vector<ref<value>>&, bindings&)> fun_; 
    };

}
}