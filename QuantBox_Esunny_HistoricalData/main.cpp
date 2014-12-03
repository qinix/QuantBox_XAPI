#include "stdafx.h"
#include "../include/ApiHeader.h"
#include "../include/QueueEnum.h"
#include "HistoricalDataApi.h"

inline CHistoricalDataApi* GetApi(void* pApi)
{
	return static_cast<CHistoricalDataApi*>(pApi);
}

void* __stdcall XRequest(char type, void* pApi1, void* pApi2, double double1, double double2, void* ptr1, int size1, void* ptr2, int size2, void* ptr3, int size3)
{
	RequestType rt = (RequestType)type;
	switch (rt)
	{
	case GetApiType:
		return (void*)(ApiType::HistoricalData | ApiType::Instrument);
	case GetApiVersion:
		return "0.1";
	case GetApiName:
		return "Esunny";
	case Create:
		return new CHistoricalDataApi();
	default:
		break;
	}

	if (pApi1 == nullptr)
	{
		return nullptr;
	}

	CHistoricalDataApi* pApi = GetApi(pApi1);

	switch (rt)
	{
	case Release:
		delete pApi;
		return nullptr;
	case Register:
		pApi->Register(ptr1);
		break;
	case Connect:
		pApi->Connect((const char*)ptr3, (ServerInfoField*)ptr1, (UserInfoField*)ptr2);
		break;
	case Disconnect:
		pApi->Disconnect();
		break;
	//case ReqQryHistoricalTicks:
	//	pApi->RequestTrace();
	//	break;
	//case ReqQryHistoricalBars:
	//	pApi->RequestHistory();
		break;
	default:
		break;
	}

	return pApi1;
}