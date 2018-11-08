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

	class symbol_table
	{
	public:
		symbol * get(std::string context, std::string name, bool create = true);
	};
}