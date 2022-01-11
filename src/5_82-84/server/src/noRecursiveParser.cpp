#include "noRecursiveParser.h"

namespace Server {
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;

NoRecursiveParser::NoRecursiveParser(): AParser()
{
}

void NoRecursiveParser::direct(std::shared_ptr<Node> link, int space)
{
	auto tmp = link;
	auto s = std::make_shared<std::stack<shared_ptr<Node>>>();
	s->push(link);
	while (! s->empty()) {
		tmp = s->top();
		s->pop();
		if(tmp)tmp->visit(log);
		if(tmp->right()) s->push(tmp->right());
		if(tmp->left()) s->push(tmp->left());
	}
}

void NoRecursiveParser::traverse(std::shared_ptr<Node> link, int space)
{
}

void NoRecursiveParser::reversive(std::shared_ptr<Node> link, int space)
{

}

void NoRecursiveParser::levels(std::shared_ptr<Node> link, int space)
{
	auto tmp = link;
	auto s = std::make_shared<std::queue<shared_ptr<Node>>>();
	s->push(link);
	while (! s->empty()) {
		tmp = s->front();
		s->pop();
		if(tmp)tmp->visit(log);
		if(tmp->left()) s->push(tmp->left());
		if(tmp->right()) s->push(tmp->right());
	}
}

const std::shared_ptr<std::string> NoRecursiveParser::Log() const
{
	return log;
}
}
