#include "blank.h"

using namespace std;

namespace osmium 
{
namespace matchers 
{
	blank::blank(ref<value> head, matcher * next)
		: matcher(next), head_(move(head))
	{
	}

	bool blank::match(const vector<ref<value>>& target, bindings& matched)
    {
		if (target.empty()) {
			set_matched(nullptr);
			return false;
		}

		if (head_ && head_->compare(target[0]->head()) != 0)
		{
			set_matched(nullptr);
			return false;
		}

		set_matched(target[0]);

		return next()->match(vector<ref<value>>(target.begin() + 1, target.end()), matched);
    }
}
}