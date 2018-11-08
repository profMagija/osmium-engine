#pragma once

#include <memory>
#include <vector>
#include "env.h"

#include "value.h"


namespace osmium
{
	

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
	private:
		std::vector<ref<value>> parts_;
		ref<atom> atom_head_;
	};
}
