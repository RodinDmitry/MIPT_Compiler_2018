#pragma once
#include <set>
#include <deque>
#include <memory>
#include <assert.h>
#include <ErrorTable.h>

class ITree;
class IVisitor;

class ITree {
public:
	virtual void Accept(IVisitor* visitor);

	virtual std::string GetLabel();
	void AddToLabel(std::string adding);

protected:

	std::string labelAddings = "";
};

class CClassVisibilityStart : public ITree {
	virtual void Accept(IVisitor* visitor) override;
};

class CClassVisibilityEnd : public ITree {
	virtual void Accept(IVisitor* visitor) override;
};

class CFunctionVisibilityStart : public ITree {
	virtual void Accept(IVisitor* visitor) override;
};

class CFunctionVisibilityEnd: public ITree {
	virtual void Accept(IVisitor* visitor) override;
};

class CVisibilityBlockStart : public ITree {
	virtual void Accept(IVisitor* visitor) override;
};

class CVisibilityBlockEnd : public ITree {
	virtual void Accept(IVisitor* visitor) override;
};

inline std::string ITree::GetLabel() {
	assert(false);
	return "";
}

inline void ITree::AddToLabel(std::string adding) {
	labelAddings += adding;
}