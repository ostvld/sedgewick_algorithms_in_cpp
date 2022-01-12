#include "recursiveParser.h"

namespace Server {

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;


	RecursiveParser::RecursiveParser() : AParser()
	{
	}

	void RecursiveParser::pre_order(std::shared_ptr<Node> link, int space)
	{
		if(!link)
		{
			return;
		}
//		if(0!=space)
//		{
//			log->append("\n");
//		}
//		for(int it = 0 ; it < space; ++it)
//		{
//			log->append("+");
//		}
		link->visit(log);
		++space;
		pre_order(link->left(),space);
		pre_order(link->right(),space);
	}

	void RecursiveParser::in_order(std::shared_ptr<Node> link, int space)
	{
		if(!link)
		{
			return;
		}
		if(0!=space)
		{
			//					log->append("\n");
		}
		for(int it = 0 ; it < space; ++it)
		{
			//					log->append("+");
		}
		++space;
		in_order(link->left(),space);
		link->visit(log);
		in_order(link->right(),space);
	}

	void RecursiveParser::post_order(std::shared_ptr<Node> link, int space)
	{
		if(!link)
		{
			return;
		}
		if(0!=space)
		{
//			log->append("\n");
		}
		for(int it = 0 ; it < space; ++it)
		{
//			log->append("+");
		}
		++space;
		post_order(link->left(),space);
		post_order(link->right(),space);
		link->visit(log);
	}

	const shared_ptr<string> RecursiveParser::Log() const
	{
		return log;
	}













}
