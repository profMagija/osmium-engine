#include "symbol.h"
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
	bool symbol::operator<(const symbol rhs) const 
	{
		return name() == rhs.name() ? context() < rhs.context() : name() < rhs.name(); 
	}
	bool symbol::operator==(const symbol rhs) const 
	{
		return !(*this < rhs || rhs < *this); 
	}
}