#pragma once

#include <iostream>
#include <memory>
#include "item.h"

namespace Server {
	/// Нода дерева
	class Node
	{
		public:
			explicit Node(std::shared_ptr <Item> it,
			std::shared_ptr <Node> left = nullptr,
			std::shared_ptr <Node> right = nullptr);

			explicit Node( std::string name,
			std::shared_ptr<Node> left = nullptr,
			std::shared_ptr <Node> right = nullptr);
			/// Посещение ноды дерева
			void visit(std::shared_ptr <std::string> log);
			/// Отдает левую дочернюю ноду
			const std::shared_ptr<Node> left() const;
			/// Отдает правую дочернюю ноду
			const std::shared_ptr<Node> right() const;

		protected:
			std::shared_ptr <Item> it_;
			/// Левая дочерняя нода
			std::shared_ptr <Node> left_;
			/// Правая дочерняя нода
			std::shared_ptr <Node> right_;
	};
}
