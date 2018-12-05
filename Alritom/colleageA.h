#pragma once
#include "abstractColleage.h"
class colleageA :
	public abstractColleage
{
public:
	colleageA();
	virtual ~colleageA();
	void subscriteToMediator();
private:
	virtual void notify(abstractColleage * source, abstractColleage * dest, char * pdata, size_t pdataSize);

};

