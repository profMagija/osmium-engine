#pragma once 

#include <memory>

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
}