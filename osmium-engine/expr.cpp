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
	}

	ref<value> expr::head() const
	{
		return parts_[0];
	}

	ref<atom> expr::atom_head() const
	{
		return atom_head_;
	}

	expr expr::clone()  const 
	{
		return expr(this->parts_);
	}

	value_iterator*  expr::parts(int start, int end, int step) const 
	{
		return new expr_parts_iterator(parts_, start, end, step);
	}

	std::vector<ref<value>> expr::children() const 
	{
		return parts_; 
	}

	expr expr::take(int count) const 
	{
		auto current = clone();
		auto childs = current.children();
		childs.erase(childs.begin(), childs.begin()+count);
		return expr(childs);
	}
	int expr::compare(ref<value> rhs) const
	{
		if (rhs->is_atomic()) return 1;
		else 
		{
			int res(head()->compare(rhs->head()) == 0);
			return res; // TODO we need to further compare expressions 
			// maybe we should add is_expression function to value? 
		}
	}
}
