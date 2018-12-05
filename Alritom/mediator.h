#pragma once
#include <list>
#include <map>

class abstractColleage;

using namespace std;
typedef std::list <abstractColleage*> colleageList;
typedef std::map<abstractColleage*, char*> colleageData;
class Mediator
{
protected:
	Mediator();
	~Mediator();
	void noify();
public:
	static Mediator* Instance();
	bool subscriteToMediator(abstractColleage * colleage);
	bool sendMessageWithinPlugin(abstractColleage * source,abstractColleage * dest,char* pdata,size_t pdataSize);
	bool getMessageWithinPlugin(abstractColleage* source, abstractColleage * dest,char* pdata, size_t pdataSize);
private:
	static Mediator* _instance;
	colleageList* _colleage;
	colleageData* _colleageData;
private:
	void cleanInvalidColleage();
};