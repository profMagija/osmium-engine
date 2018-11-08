#include "symtab.h"
#include <utility>

using namespace std;

namespace osmium
{
	symbol * symbol_table::get_symbol(std::wstring context, std::wstring name, bool create)
	{
		auto ctx = table_.find(context);
		if (ctx == table_.end()) {
			if (!create) 
				return nullptr;
			ctx = table_.emplace(context, map<wstring, symbol*>()).first;
		}

		auto sym = ctx->second.find(name);
		if (sym == ctx->second.end()) {
			if (!create) 
				return nullptr;
			return ctx->second.emplace(name, new symbol(context, name)).first->second;
		}

		return sym->second;
	}
}