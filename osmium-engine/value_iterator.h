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


    };
}