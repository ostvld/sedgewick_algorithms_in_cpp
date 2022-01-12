#include "noRecursiveParser.h"

namespace Server {
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;

NoRecursiveParser::NoRecursiveParser(): AParser()
{
}

void NoRecursiveParser::pre_order(std::shared_ptr<Node> link, int space)
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

void NoRecursiveParser::in_order(std::shared_ptr<Node> link, int space)
{
	auto tmp = link;
	auto s = std::make_shared<std::stack<shared_ptr<Node>>>();
	while ( !s->empty() || tmp) {
		if (tmp) {
			s->push(tmp);
			tmp = tmp->left();
		} else {
			tmp = s->top();
			s->pop();
			tmp->visit(log);
			tmp = tmp->right();
		}
	}
}

void NoRecursiveParser::post_order(shared_ptr<Node> link, int space)
{
	auto tmp = link;
	auto s = std::make_shared<std::stack<shared_ptr<Node>>>();
	shared_ptr <Node> lnp = nullptr;
	shared_ptr<Node> peekn = nullptr;

	while (! s->empty() || tmp) {
		if (tmp) {
			s->push(tmp);
			tmp = tmp->left();
		} else {
			peekn = s->top();
			if (peekn->right() && lnp != peekn->right()) {
				tmp = peekn->right();
			} else {
				s->pop();
				peekn->visit(log);
				lnp = peekn;
			}
		}
	}
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
