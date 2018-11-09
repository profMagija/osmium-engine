#pragma once 

#include "value.h"
#include <optional>

namespace osmium 
{
    class value_iterator 
    {
    public:
        virtual bool next() = 0; 
        virtual ref<value> get() = 0; 
        virtual value_iterator* clone() const =0;
        value_iterator* clone_next() const 
        {
            auto res = clone();
            if (res->next()) return res;
            else 
            {
                delete res; 
                return nullptr;
            }
        }


    };
}