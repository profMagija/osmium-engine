#pragma once

#include <memory>
#include <vector>
#include "env.h"

namespace osmium
{
	/**
	 * \brief A reference-counted pointer to a constant object
	 * \tparam T Type of the object pointed to
	 */
	template<class T>
	using ref = std::shared_ptr<const T>;

	class atom;

	/**
	 * \brief Base class for any value in the system
	 */
	class value : std::enable_shared_from_this<value>
	{
	public:
		virtual ~value() = default;
		virtual ref<value> head() const = 0;
		virtual ref<atom> atom_head() const = 0;
		virtual bool is_atomic() const { return false; }
		virtual bool is_number() const { return false; }
		virtual bool is_string() const { return false; }
		virtual bool is_symbol() const { return false; }
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
	private:
		std::vector<ref<value>> parts_;
		ref<atom> atom_head_;
	};
}
