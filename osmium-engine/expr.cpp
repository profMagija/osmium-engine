#include "expr.h"
#include <utility>
#include <algorithm>
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
			auto comp_less = [] (ref<value> x, ref<value> y) {return x->compare(y) < 0;}; 
			auto comp_equal = [] (ref<value> x, ref<value> y) {return x->compare(y) == 0;};
			// if rhs is not atomic, it is expression 
			auto rhs_expr = std::static_pointer_cast<const expr>(rhs);
			auto start = parts_.begin(); 
			auto end = parts_.end();
			auto start_rhs = rhs_expr->children().begin();
			auto end_rhs = rhs_expr->children().end();
			if (std::equal(start, end, start_rhs, end_rhs, comp_equal)) return 0;
			else if (std::lexicographical_compare(start, end, start_rhs, end_rhs, comp_less)) return -1;
			else return 1; 
		}
	}
}
