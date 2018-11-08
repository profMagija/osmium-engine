#include "env.h"

#if defined(_MSC_VER)
#define THREAD_LOCAL __declspec(thread)
#elif defined(__GNUC__)
#define THREAD_LOCAL __thread
#endif

namespace osmium
{
	THREAD_LOCAL environment* __env;

	environment* get_env()
	{
		return __env;
	}

	void set_env(environment* env)
	{
		__env = env;
	}

	void system_context::init(environment * env)
	{
#define SYMBOL(name) name = env->symtab.get(string("System`"), string(#name))
#include "system.inc"
#undef SYMBOL
	}
}
