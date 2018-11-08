#pragma once

#include <string>
#include "symbol.h"
namespace osmium
{

	class symbol_table
	{
	public:
		symbol * get_symbol(std::string context, std::string name, bool create = true);	};

}