#include "symbol_expr.h"

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
	int symbol_expr::compare(ref<value> rhs) const 
	{
		if (rhs->is_number() || rhs->is_string()) return 1;
		else if (rhs->is_symbol()) 
		{
			auto symbol_exppression_casted = std::static_pointer_cast<const symbol_expr>(rhs);
			if (get_symbol() <  symbol_exppression_casted->get_symbol()) return -1;
			else if (get_symbol() > symbol_exppression_casted->get_symbol()) return 1;
			else return 0;
		}
		else return -1;
	}
}