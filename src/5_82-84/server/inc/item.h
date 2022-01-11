#pragma once

#include <string>
#include <memory>
namespace Server {
/// Объект хранящий информацию
class Item
{
	public:
		Item(std::string name );
		/// Передать данные экземпляра в строку
		void print(std::shared_ptr <std::string> log);

	protected:

		std::string name_;
};
}
