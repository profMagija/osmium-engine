#include "atom.h"

using namespace std;

namespace osmium
{
	symbol_expr::symbol_expr(symbol * sym) noexcept 
		: sym_(sym)
	{
	}

	ref<value> symbol_expr::head() const
	{
		return make_shared<symbol_expr>(OS_SYSTEM.Symbol);
	}

	ref<atom> symbol_expr::atom_head() const
	{
		return enable_shared_from_this<symbol_expr>::shared_from_this();
	}
}