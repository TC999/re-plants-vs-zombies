#ifdef _MSC_VER
#pragma warning( disable : 4786 )
#endif

#include "CritSect.h"
#define NOMINMAX 1
#ifdef _WIN32
#include <windows.h>
#endif

using namespace Sexy;

////////////////////////////////////////////////////////////////////////////////

CritSect::CritSect(void)
{
	InitializeCriticalSection(&mCriticalSection);
}

////////////////////////////////////////////////////////////////////////////////

CritSect::~CritSect(void)
{
	DeleteCriticalSection(&mCriticalSection);
}
