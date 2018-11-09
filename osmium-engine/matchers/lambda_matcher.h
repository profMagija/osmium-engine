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
    private:
        std::function<bool (matcher*, const std::vector<ref<value>>&, bindings&)> fun_; 
    };

}
}