#include "mediator.h"
#include "abstractColleage.h"

Mediator* Mediator::_instance = nullptr;

Mediator::Mediator()
{
	_colleage = new colleageList;
	_colleageData = new colleageData;
}

Mediator::~Mediator()
{
	if (_colleage != nullptr)
	{
		_colleage->clear();
		delete _colleage;
		_colleage = nullptr;
	}
	if (_colleageData != nullptr)
	{
		_colleageData->clear();
		delete _colleageData;
		_colleageData = nullptr;
	}
}

void Mediator::noify()
{
}

Mediator * Mediator::Instance()
{
	if (_instance == nullptr)
	{
		_instance = new Mediator;
	}
	
	return _instance;
}

bool Mediator::subscriteToMediator(abstractColleage * colleage)
{
	if (colleage == nullptr)
	{
		return false;
	}
	else
	{
		cleanInvalidColleage();
		_colleage->push_front(colleage);
		_colleageData->insert(make_pair(colleage, nullptr));
		_colleage->unique();
		return true;
	}

}

bool Mediator::sendMessageWithinPlugin(abstractColleage * source,abstractColleage * dest, char * pdata, size_t pdataSize)
{
	if (source == nullptr)
	{
		return false;
	}
    else if (dest == nullptr)
	{
		return false;
	}
	else 
	{
		colleageList::iterator iterSource;
		iterSource = std::find(_colleage->begin(), _colleage->end(), source);
		if (iterSource == _colleage->end())
		{
			return false;
		}
		colleageList::iterator iterDest;
		iterDest = std::find(_colleage->begin(), _colleage->end(), dest);
		if (iterDest != _colleage->end())
		{
			colleageData::iterator iter;
			iter = _colleageData->find(*iterDest);
			if (iter != _colleageData->end())
			{
				char* pData = new char[pdataSize + 1];
				memcpy(pData, pdata, pdataSize);
				pData[pdataSize] = '\0';
				iter->second = pData;
				dest->notify(dest,source,pData,pdataSize);
			}
		}
	}
	return true;
}

bool Mediator::getMessageWithinPlugin(abstractColleage * source, abstractColleage * dest,char * pdata, size_t pdataSize)
{
	if (source == nullptr)
	{
		return false;
	}
	else if (dest == nullptr)
	{
		return false;
	}
	else
	{
		colleageList::iterator iterSource;
		iterSource = std::find(_colleage->begin(), _colleage->end(), source);
		if (iterSource == _colleage->end())
		{
			return false;
		}
		colleageList::iterator iterDest;
		iterDest = std::find(_colleage->begin(), _colleage->end(), dest);
		if (iterDest != _colleage->end())
		{
			colleageData::iterator iter;
			iter = _colleageData->find(*iterSource);
			if (iter != _colleageData->end())
			{
				pdata = iter->second;
			}
			else
			{
				return false;
			}
		}
		
	}
	return true;
}

void Mediator::cleanInvalidColleage()
{
	colleageList::iterator iterColleage;
	iterColleage = std::find(_colleage->begin(), _colleage->end(), nullptr);
	if (iterColleage != _colleage->end())
	{
		_colleage->erase(iterColleage);
	}
	
	colleageData::iterator iterData;
	iterData = _colleageData->find(nullptr);
	if (iterData != _colleageData->end())
	{
		_colleageData->erase(iterData);
	}
}
