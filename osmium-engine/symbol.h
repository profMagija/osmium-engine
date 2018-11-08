#pragma once

#include <string>

namespace osmium 
{
    class symbol
	{
	public:
		std::wstring name() const;
		std::wstring context() const;

	protected:
		symbol(std::wstring context, std::wstring name);

		friend class symbol_table;
	private:
		std::wstring context_;
		std::wstring name_;
	};

}