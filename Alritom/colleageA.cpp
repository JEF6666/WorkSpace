#include "stdafx.h"
#include "colleageA.h"
#include "mediator.h"

colleageA::colleageA()
{
	subscriteToMediator();
}


colleageA::~colleageA()
{
}

void colleageA::notify(abstractColleage * source, abstractColleage * dest, char * pdata, size_t pdataSize)
{
	printf("A:%s", pdata);
	delete[] pdata;
}
void colleageA::subscriteToMediator()
{
	Mediator* mediator = Mediator::Instance();
	mediator->subscriteToMediator(this);
}