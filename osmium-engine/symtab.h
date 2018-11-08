#pragma once

#include <string>
#include "symbol.h"

#include <map>

namespace osmium
{
	class symbol_table
	{
	public:
		/**
		 * \brief Gets the symbol from the table, opptionaly creating it if it doesn't exist
		 * \param context Context of the symbol, with a trailing '`'
		 * \param name Name of the symbol
		 * \param create true (default) to create the symbol if it's missing, false to return null instead
		 * \return The symbol, or null if it doesn't exist and \a create is false
		 */
		symbol * get_symbol(std::wstring context, std::wstring name, bool create = true);	

	private:
		std::map<std::wstring, std::map<std::wstring, symbol*>> table_;
	};
}