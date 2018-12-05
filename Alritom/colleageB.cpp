#include "stdafx.h"
#include "colleageB.h"
#include "mediator.h"

colleageB::colleageB()
{
	subscriteToMediator();
}


colleageB::~colleageB()
{
}

void colleageB::notify(abstractColleage * source, abstractColleage * dest, char * pdata, size_t pdataSize)
{
	printf("B:%s\n",pdata);
	delete[] pdata;
}
void colleageB::subscriteToMediator()
{
	Mediator* mediator = Mediator::Instance();
	mediator->subscriteToMediator(this);
}