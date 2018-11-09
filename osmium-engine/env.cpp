#include "env.h"

#include <string>

using namespace std;

#if defined(_MSC_VER)
#define THREAD_LOCAL __declspec(thread)
#elif defined(__GNUC__)
#define THREAD_LOCAL __thread
#endif

namespace osmium
{
	THREAD_LOCAL environment* current_env;

	environment* get_env()
	{
		return current_env;
	}

	void set_env(environment* env)
	{
		current_env = env;
	}

	void system_context::init(environment * env)
	{
#define SYMBOL(name, strname) \
	name = env->symtab.get_symbol(wstring(L"System`"), wstring(strname));
#include "system.inc"
#undef SYMBOL
#undef LSTR
	}
}
