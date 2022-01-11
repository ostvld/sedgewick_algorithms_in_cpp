#include "recursiveParser.h"

namespace Server {

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;


	RecursiveParser::RecursiveParser() : AParser()
	{
	}

	void RecursiveParser::direct(std::shared_ptr<Node> link, int space)
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
		direct(link->left(),space);
		direct(link->right(),space);
	}

	void RecursiveParser::traverse(std::shared_ptr<Node> link, int space)
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
		traverse(link->left(),space);
		link->visit(log);
		traverse(link->right(),space);
	}

	void RecursiveParser::reversive(std::shared_ptr<Node> link, int space)
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
		reversive(link->left(),space);
		reversive(link->right(),space);
		link->visit(log);
	}

	const shared_ptr<string> RecursiveParser::Log() const
	{
		return log;
	}













}
