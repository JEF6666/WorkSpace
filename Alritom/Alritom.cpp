// Alritom.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include "colleageA.h"
#include "colleageB.h"
#include "mediator.h"
int main()
{
	colleageA A;
	colleageB B;
	colleageB C;
	colleageB D;
	colleageB E;
	Mediator* mediator = Mediator::Instance();
	mediator->sendMessageWithinPlugin(&A, &B, "123", 4);
	mediator->sendMessageWithinPlugin(&B, &E, "1234", 5);
	mediator->sendMessageWithinPlugin(&D, &C, "12345", 10);
	mediator->sendMessageWithinPlugin(&D, &A, "12345", 10);
    return 0;
}

