#include "expr.h"
#include <utility>

namespace osmium {

	expr::expr(const ref<value>& head, const std::vector<ref<value>>& args) noexcept
		: atom_head_(head->atom_head())
	{
		parts_.reserve(1 + args.size());
		parts_.push_back(head);
		parts_.insert(parts_.end(), args.begin(), args.end());
	}

	expr::expr(std::vector<ref<value>> parts) noexcept
		: parts_(std::move(parts)), atom_head_(parts_[0]->atom_head())
	{
		_ASSERTE(parts_.size() > 0); // must not create empty expr
	}

	ref<value> expr::head() const
	{
		return parts_[0];
	}

	ref<atom> expr::atom_head() const
	{
		return atom_head_;
	}

}
