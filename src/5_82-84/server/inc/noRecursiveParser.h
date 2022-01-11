#pragma once

#include <stack>
#include <queue>

#include "aparser.h"

namespace Server {
	/// Парсер не использующий рекурсию
	class NoRecursiveParser: public AParser
	{
		public:
			NoRecursiveParser();
			virtual ~NoRecursiveParser() override = default;
			/// Прямой обход: узел, левое поддерево, правое поддерево
			virtual void direct(std::shared_ptr <Node> link, int space) override ;
			/// Поперечный обход: левое дерево, узел, правое дерево
			virtual void traverse(std::shared_ptr <Node> link, int space) override;
			/// Обратный обход: левое поддерево, правое поддерево, узел
			virtual void reversive(std::shared_ptr <Node> link, int space) override;
			/// Обход по уровням
			void levels(std::shared_ptr <Node> link, int space);
			/// Отображение дерева в строку
			virtual const std::shared_ptr<std::string> Log() const override;
	};
}
