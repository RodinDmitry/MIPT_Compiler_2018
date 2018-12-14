#pragma once

#include <string>

namespace IR {

class CLabel {
public:
	CLabel() : label(std::to_string(totalLabels++)) {}
	CLabel(const std::string& _label) : label(_label) {}
	const std::string& GetLabel() const { return label; }

private:
	static int totalLabels;
	std::string label;
};

} // namespace IR