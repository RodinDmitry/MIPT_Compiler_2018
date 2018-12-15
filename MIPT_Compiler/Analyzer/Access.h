#pragma once

class IAccess {
public:
	virtual ~IAccess() {};
};

class CInRegAccess : public IAccess {
public:
	CInRegAccess(int _reg);
	int GetReg() const;

	~CInRegAccess() {};
private:
	int reg;
};

class CInFrameAccess : public IAccess {
public:
	CInFrameAccess(int _offset);
	int GetOffset() const;

	~CInFrameAccess() {};
private:
	int offset;
};