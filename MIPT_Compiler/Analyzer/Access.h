#pragma once

class IAccess {
public:
	virtual ~IAccess() = 0;
};

class CInRegAccess : public IAccess {

};

class CInFrameAccess : public IAccess {

};