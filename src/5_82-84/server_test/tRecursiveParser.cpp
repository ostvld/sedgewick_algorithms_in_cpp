#include "tRecursiveParser.h"
#include "recursiveParser.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "node.h"
#include <iostream>
#include <string>

TEST(RecursiveParser, in_order)
{
	//    arrange
	auto lA3= std::make_shared <Server::Node>("\n+++A");
	auto rC3= std::make_shared <Server::Node>("\n+++C");
	auto lB2 = std::make_shared <Server::Node>("\n++B",lA3, rC3);
	auto lD1 = std::make_shared <Server::Node>("\n+D", lB2);
	auto rG3 = std::make_shared <Server::Node>("\n+++G");
	auto lF2 = std::make_shared <Server::Node>("\n++F",nullptr,rG3);
	auto rH1 = std::make_shared <Server::Node>("\n+H",lF2);
	auto root = std::make_shared <Server::Node>("E",lD1,rH1);
	auto parser = Server::RecursiveParser();
	auto etalon = std::make_shared<std::string>("\n+++A\n++B\n+++C\n+DE\n++F\n+++G\n+H");
	//    act
	parser.in_order(root,0);
	auto log = parser.Log();
	//    assert
	EXPECT_EQ(*log,*etalon);
}

TEST(RecursiveParser, pre_order)
{
	//    arrange
	auto right2 = std::make_shared <Server::Node>("\n+++C");
	auto left2= std::make_shared <Server::Node>("\n+++A");
	auto left1 = std::make_shared <Server::Node>("\n++B",left2,right2);
	auto left = std::make_shared <Server::Node>("\n+D",left1);
	auto G3 = std::make_shared <Server::Node>("\n+++G");
	auto F2 = std::make_shared <Server::Node>("\n++F",nullptr,G3);
	auto right = std::make_shared <Server::Node>("\n+H",F2);
	auto root = std::make_shared <Server::Node>("E",left,right);
	auto parser = Server::RecursiveParser();
	auto etalon = std::make_shared<std::string>("E\n+D\n++B\n+++A\n+++C\n+H\n++F\n+++G");
	//    act
	parser.pre_order(root,0);
	auto log = parser.Log();
	//    assert
	EXPECT_EQ(*log,*etalon);
}

TEST(RecursiveParser, post_order)
{
	//    arrange
	auto lA3= std::make_shared <Server::Node>("\n+++A");
	auto rC3= std::make_shared <Server::Node>("\n+++C");
	auto lB2 = std::make_shared <Server::Node>("\n++B",lA3, rC3);
	auto lD1 = std::make_shared <Server::Node>("\n+D", lB2);
	auto rG3 = std::make_shared <Server::Node>("\n+++G");
	auto lF2 = std::make_shared <Server::Node>("\n++F",nullptr,rG3);
	auto rH1 = std::make_shared <Server::Node>("\n+H",lF2);
	auto root = std::make_shared <Server::Node>("E",lD1,rH1);
	auto parser = Server::RecursiveParser();
	auto etalon = std::make_shared<std::string>("\n+++A\n+++C\n++B\n+D\n+++G\n++F\n+HE");
	//    act
	parser.post_order(root,0);
	auto log = parser.Log();
	//    assert
	EXPECT_EQ(*log,*etalon);
}
