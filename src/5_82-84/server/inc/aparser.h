#pragma once

#include "node.h"

namespace Server {
	/// Абстрактный класс парсера дерева
	class AParser
	{
		public:
			AParser();
			virtual ~AParser() = default;

			/// Прямой обход: узел, левое поддерево, правое поддерево
			virtual void pre_order(std::shared_ptr <Node> link, int space) = 0;
			/// Поперечный обход: левое дерево, узел, правое дерево
			virtual void in_order(std::shared_ptr <Node> link, int space) = 0;
			/// Обратный обход: левое поддерево, правое поддерево, узел
			virtual void post_order(std::shared_ptr <Node> link, int space) = 0;
			/// Отображение дерева в строку
			virtual const std::shared_ptr<std::string> Log() const = 0;
		protected:
			std::shared_ptr <std::string> log;

	};
}
