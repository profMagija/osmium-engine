#pragma once
#include "expr.h"

namespace osmium
{
	class atom : public value, std::enable_shared_from_this<atom>
	{
	public:
		bool is_atomic() const override { return true; }
	};

	class symbol_expr : public atom, std::enable_shared_from_this<symbol_expr>
	{
	public:
		explicit symbol_expr(symbol* sym) noexcept;
		bool is_symbol() const override { return true; }
		ref<value> head() const override;
		ref<atom> atom_head() const override;
		const symbol* sym() const { return sym_; }

	private:
		symbol* sym_;
	};
}
