#pragma once

class IAccess {
public:
	virtual ~IAccess() = 0;
};

class CInRegAccess : public IAccess {
public:
	CInRegAccess(int _reg);
	int GetReg() const;
private:
	int reg;
};

class CInFrameAccess : public IAccess {
public:
	CInFrameAccess(int _offset);
	int GetOffset() const;
private:
	int offset;
};