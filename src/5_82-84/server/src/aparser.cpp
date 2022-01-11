#include "aparser.h"

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;

Server::AParser::AParser() {
	log = std::make_shared<string>();
}
