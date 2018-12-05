#pragma once
#include "abstractColleage.h"

class colleageB :
	public abstractColleage
{
public:
	colleageB();
	~colleageB();
	void subscriteToMediator();
private:
	virtual void notify(abstractColleage * source, abstractColleage * dest, char * pdata, size_t pdataSize);

};

