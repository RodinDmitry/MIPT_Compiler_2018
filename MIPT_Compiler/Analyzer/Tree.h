#pragma once
#include <set>
#include <deque>
#include <memory>
#include <assert.h>
#include <ErrorTable.h>

class IFrame;
class ITree;
class IVisitor;

class ITree {
public:
	ITree() = default;
	virtual ~ITree();
	ITree(int line);

	virtual void Accept(IVisitor* visitor);

	virtual const std::string& GetLabel() const;
	void AddToLabel(const std::string& adding);

	int GetLine() const;

	IFrame* GetFrame();
	void SetFrame(std::shared_ptr<IFrame> frame);
protected:
	std::shared_ptr<IFrame> frame;
	std::string labelAddings = "";
	int line = -1;
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

inline const std::string& ITree::GetLabel() const {
	assert(false);
	return "";
}

inline void ITree::AddToLabel(const std::string& adding) {
	labelAddings += adding;
}