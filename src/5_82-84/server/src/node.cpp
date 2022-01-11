#include "node.h"


namespace Server {

	using std::cout;
	using std::endl;
	using std::string;
	using std::shared_ptr;

	Node::Node(std::shared_ptr<Item> it, std::shared_ptr<Node> left, std::shared_ptr<Node> right):
		it_(it),
		left_(left),
		right_(right)
	{}

	Node::Node(string name, std::shared_ptr<Node> left, std::shared_ptr<Node> right):
		left_(left),
		right_(right)
	{
		it_ = std::make_shared<Item> (name);
	}

	void Node::visit(std::shared_ptr<string> log)
	{
		it_->print(log);
	}

	const shared_ptr<Node> Node::left() const
	{
		return left_;
	}

	const shared_ptr<Node> Node::right() const
	{
		return right_;
	}






}
