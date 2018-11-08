#pragma once

#include <string>

namespace osmium 
{
    class symbol
	{
	public:
		std::string name() const;
		std::string context() const;

	protected:
		symbol(std::string context, std::string name);

		friend class symbol_table;
	private:
		std::string context_;
		std::string name_;
	};

}