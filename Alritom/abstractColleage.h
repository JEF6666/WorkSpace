#pragma once
class abstractColleage
{
public:
	virtual void notify(abstractColleage * source, abstractColleage * dest, char * pdata, size_t pdataSize) = 0;
	virtual void subscriteToMediator() = 0;
};