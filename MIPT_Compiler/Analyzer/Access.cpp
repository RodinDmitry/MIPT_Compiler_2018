#include "Access.h"

CInFrameAccess::CInFrameAccess(int _offset) : offset(_offset) {}

std::shared_ptr<const IR::IExpression> CInFrameAccess::GetExp(std::shared_ptr<const IR::IExpression> framePtr) const
{
	std::shared_ptr<const IR::IExpression> offsetExpression;
	if (offset != 0) {
		offsetExpression = std::move(std::make_shared<const IR::CBinaryExpression>(
				IR::O_Plus,
				framePtr,
				std::make_shared<const IR::CConstExpression>(offset)
			));
	}
	else {
		offsetExpression = std::move(framePtr);
	}
	return std::move(std::make_shared<const IR::CMemExpression>(std::move(offsetExpression)));
}

CInRegAccess::CInRegAccess(std::shared_ptr<const IR::CTemp> _reg) : reg(_reg) {}

std::shared_ptr<const IR::IExpression> CInRegAccess::GetExp(std::shared_ptr<const IR::IExpression> framePtr) const
{
	return std::make_shared<const IR::CTempExpression>(reg);
}
