#include "symbol.h"
#include <utility>

using namespace std;

namespace osmium
{
	wstring symbol::name() const
	{
		return name_;
	}

	wstring symbol::context() const
	{
		return context_;
	}

	symbol::symbol(wstring context, wstring name)
		: context_(move(context)), name_(move(name))
	{

	}
}