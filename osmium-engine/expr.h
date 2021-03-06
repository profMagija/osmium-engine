#pragma once

#include <memory>
#include <vector>
#include "env.h"

#include "value.h"
#include "value_iterator.h"
#include <utility>

namespace osmium
{
	class expr_parts_iterator : public value_iterator 
	{
		int start_; 
		int end_;
		int curr_; 
		int step_;
		std::vector<ref<value>> parts_; 
	public:
		expr_parts_iterator(const std::vector<ref<value>> &parts, int start, int end, int step) 
			: start_(start), parts_(parts), end_(end), curr_(start-1), step_(step)
		{}

		expr_parts_iterator(const expr_parts_iterator&) = default;

		bool next() override 
		{
			curr_ += step_; 
			bool x = ! (curr_ < start_ || curr_ >= end_);
			return step_ > 0 ? x : !x;
		}
		ref<value> get() override
		{
			return parts_[curr_];
		}
		value_iterator* clone() const override 
		{
			return new expr_parts_iterator(*this);
		}
		

	};

	/**
	 * \brief A compound expression
	 */
	class expr : public value
	{
	public:
		expr(const ref<value> &head, const std::vector<ref<value>> &args) noexcept;
		explicit expr(std::vector<ref<value>> parts) noexcept;
		ref<value> head() const override;
		ref<atom> atom_head() const override;
		expr clone() const;
		value_iterator* parts(int start, int end, int step) const;
		/*
		\brief Returns vector of children including head of expression 
		*/
		std::vector<ref<value>> children() const; 
		expr take(int) const; 
		int compare(ref<value>) const override; 

	private:
		std::vector<ref<value>> parts_;
		ref<atom> atom_head_;
	};
}
