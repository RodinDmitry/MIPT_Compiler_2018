#pragma once

#include <string>

namespace IR {

	class CTemp {
	public:
		CTemp() : name("Temp" + std::to_string(counter++)) {}
		CTemp(const std::string& _name) : name(_name) {}

		std::string const Get() const { return name; }
	private:
		std::string name;
		static int counter;
	};

}
