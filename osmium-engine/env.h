#pragma once

#include "symtab.h"


namespace osmium
{
	class environment;

	class system_context
	{
	public:
#define SYMBOL(name, strname) symbol * name;
#include "system.inc"
#undef SYMBOL

		void init(environment * env);
	};

	class environment
	{
	public:
		symbol_table symtab;
		system_context system;

		
	};


	environment * get_env();
	void set_env(environment * env);

#define OS_ENV (osmium::get_env())
#define OS_SYMTAB (OS_ENV->symtab)
#define OS_SYSTEM (OS_ENV->system)

}
