#include <IR/IRStatement.h>
#include <Access.h>

CInFrameAccess::CInFrameAccess(int _offset) : offset(_offset) {}

std::shared_ptr<const IR::IExpression> CInFrameAccess::GetExp(std::shared_ptr<const IR::IExpression> framePtr) const
{
	std::shared_ptr<const IR::IExpression> offsetExpression;
	if (offset != 0) {
		offsetExpression = std::make_shared<const IR::CBinaryExpression>(
				IR::O_Plus,
				framePtr,
				std::make_shared<const IR::CConstExpression>(offset)
			);
	}
	else {
		offsetExpression = framePtr;
	}
	return std::make_shared<const IR::CMemExpression>(offsetExpression);
}

CInRegAccess::CInRegAccess(std::shared_ptr<const IR::CTemp> _reg) : reg(_reg) {}

std::shared_ptr<const IR::IExpression> CInRegAccess::GetExp(std::shared_ptr<const IR::IExpression> framePtr) const
{
	return std::make_shared<const IR::CTempExpression>(*reg);
}

CInClassAccess::CInClassAccess(int _offset, std::shared_ptr<const IR::IExpression> _thisExpr)
	:offset(_offset), thisExpr(_thisExpr) {}

std::shared_ptr<const IR::IExpression> CInClassAccess::GetExp(std::shared_ptr<const IR::IExpression> null) const
{
	std::shared_ptr<const IR::IExpression> offsetExpression;
	if (offset != 0) {
		offsetExpression = std::make_shared<const IR::CBinaryExpression>(
			IR::O_Plus,
			thisExpr,
			std::make_shared<const IR::CConstExpression>(offset)
			);
	}
	else {
		offsetExpression = thisExpr;
	}
	return std::make_shared<const IR::CMemExpression>(offsetExpression);
}
