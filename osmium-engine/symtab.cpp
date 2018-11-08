#include "symtab.h"
#include <utility>

using namespace std;

namespace osmium
{
	string symbol::name() const
	{
		return name_;
	}

	string symbol::context() const
	{
		return context_;
	}

	symbol::symbol(string context, string name)
		: context_(move(context)), name_(move(name))
	{

	}
	symbol * symbol_table::get(std::string context, std::string name, bool create)
	{

	}
}