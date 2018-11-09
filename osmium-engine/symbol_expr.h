#pragma once

#include "atom.h"

namespace osmium 
{
    class symbol_expr : public atom, std::enable_shared_from_this<symbol_expr>
	{
	public:
		explicit symbol_expr(symbol* sym) noexcept;
		bool is_symbol() const override { return true; }
		ref<value> head() const override;
		ref<atom> atom_head() const override;
		const symbol* get_symbol() const { return sym_; }
		int compare(ref<value>) const override; 

	private:
		symbol* sym_;
	};
}