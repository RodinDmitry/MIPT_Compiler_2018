#pragma once

#include <string>

namespace IR {

	class CTemp {
	public:
		CTemp() : name("Temp" + std::to_string(counter++)) {}
		CTemp(const std::string& _name) : name(_name) {}

		const std::string& const Get() { return name; }
	private:
		std::string name;
		static int counter;
	};

}
