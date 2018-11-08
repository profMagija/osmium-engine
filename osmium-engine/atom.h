#pragma once
#include "expr.h"

namespace osmium
{
	class atom : public value, std::enable_shared_from_this<atom>
	{
	public:
		bool is_atomic() const override { return true; }
	};

	
}
