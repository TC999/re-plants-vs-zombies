#ifndef __TODDEBUG_H__
#define __TODDEBUG_H__

#include "../SexyAppFramework/Common.h"

#define NOMINMAX 1
#ifdef _WIN32
#include <windows.h>
#else
// Platform-independent alternatives for debugging
inline bool IsDebuggerPresent() { return false; }
#ifdef __GNUC__
#define __debugbreak() __builtin_trap()
#else
inline void __debugbreak() {}
#endif
#endif

class TodHesitationBracket
{
public:
	char			mMessage[256];
	int				mBracketStartTime;

public:
	TodHesitationBracket(const char* /*theFormat*/, ...) { ; }
	~TodHesitationBracket() { ; }

	inline void		EndBracket() { ; }
};

void				TodLog(const char* theFormat, ...);
void				TodLogString(const char* theMsg);
void				TodTrace(const char* theFormat, ...);
void				TodTraceMemory();
void				TodTraceAndLog(const char* theFormat, ...);
void				TodTraceWithoutSpamming(const char* theFormat, ...);
void				TodHesitationTrace(...);
#ifdef _WIN32
void				TodReportError(LPEXCEPTION_POINTERS exceptioninfo, const char* theMessage);
#else
void				TodReportError(void* exceptioninfo, const char* theMessage);
#endif
void				TodAssertFailed(const char* theCondition, const char* theFile, int theLine, const char* theMsg = "", ...);
/*inline*/ void		TodErrorMessageBox(const char* theMessage, const char* theTitle);
#ifdef _WIN32
long __stdcall		TodUnhandledExceptionFilter(LPEXCEPTION_POINTERS exceptioninfo);
#else
long				TodUnhandledExceptionFilter(void* exceptioninfo);
#endif

/*inline*/ void*	TodMalloc(int theSize);
/*inline*/ void		TodFree(void* theBlock);
void				TodAssertInitForApp();

#ifdef _DEBUG
#define TOD_ASSERT(condition, ...) { \
if (!bool(condition)) { TodAssertFailed(""#condition, __FILE__, __LINE__, ##__VA_ARGS__); \
TodTraceMemory(); }\
}
#else
#define TOD_ASSERT(condition, ...)
#endif

#endif
