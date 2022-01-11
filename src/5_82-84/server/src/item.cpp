#include "item.h"
#include <iostream>

namespace Server {
	using std::cout;
	using std::endl;
	using std::string;
	using std::shared_ptr;

	Item::Item(string name):
		name_(name)
	{

	}

	void Item::print(shared_ptr<std::string> log)
	{
		if(log)	log->append(name_);
	}

}
