#ifndef __SEXYAPPFRAMEWORK_COMMON_H__
#define __SEXYAPPFRAMEWORK_COMMON_H__

#ifdef _MSC_VER
#pragma warning(disable:4786)
#pragma warning(disable:4503)
#endif

#ifdef _WIN32
#undef _WIN32_WINNT
#undef WIN32_LEAN_AND_MEAN

#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0500
#undef _UNICODE
#undef UNICODE
#endif

#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <cstdlib>

#ifndef _WIN32
#include <wctype.h>
#include <strings.h>
#include <climits>
#include <cstring>
#include <unistd.h>
#include <cstdarg>
#include <alloca.h>
#endif

#ifdef _WIN32
#define NOMINMAX 1
#include <windows.h>
#include <shellapi.h> 
#include <mmsystem.h>
#else
// Define Windows types for non-Windows platforms
#include <cstdint>
#include <pthread.h>
#include <time.h>

typedef uint8_t BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef int32_t LONG;
typedef uint32_t UINT;
typedef int64_t LONGLONG;
typedef uint64_t QWORD;
typedef long LRESULT;
typedef void* HANDLE;
typedef void* HMODULE;
typedef void* HINSTANCE;
typedef void* HWND;
typedef void* HCURSOR;
typedef void* HKEY;
typedef void* HICON;
typedef void* LPDIRECTSOUNDBUFFER;
typedef void* LPDIRECTSOUND;
typedef void* LPGUID;
typedef void* LPVOID;
typedef void* HFONT;
typedef const char* LPCTSTR;
typedef void* LPWIN32_FIND_DATA;
typedef void* LPDIRECTDRAWSURFACE;
typedef void* LPDIRECTDRAWSURFACE7;
typedef void* LPDIRECTDRAW;
typedef void* LPDIRECTDRAW7;
typedef void* LPDIRECT3D7;
typedef void* LPDIRECT3DDEVICE7;
typedef void* LPDIRECTDRAWPALETTE;
typedef void* HBITMAP;
typedef void* LPDDPIXELFORMAT;
typedef long HRESULT;
enum class _GET_FILEEX_INFO_LEVELS {
    GetFileExInfoStandard = 0
};

// Define FILETIME structure (needed by _WIN32_FILE_ATTRIBUTE_DATA)
struct FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
};

typedef FILETIME _FILETIME;

struct _WIN32_FILE_ATTRIBUTE_DATA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
};

// DirectDraw structures
struct DDSURFACEDESC {
    char dummy[sizeof(void*)];
};

struct DDSURFACEDESC2 {
    char dummy[sizeof(void*)];
};

struct DDPIXELFORMAT {
    char dummy[sizeof(void*)];
};

// Direct3D types
typedef int D3DTEXTURESTAGESTATETYPE;
typedef int D3DTEXTUREADDRESS;
struct D3DVIEWPORT7 {
    char dummy[sizeof(void*)];
};
typedef int BOOL;
typedef uintptr_t WPARAM;
typedef intptr_t LPARAM;
typedef int64_t __time64_t;

// LARGE_INTEGER structure
union LARGE_INTEGER {
    struct {
        DWORD LowPart;
        LONG HighPart;
    };
    LONGLONG QuadPart;
};

#define WINAPI
#define CALLBACK
#define TRUE 1
#define FALSE 0
#define MB_OK 0
#define HKEY_CURRENT_USER ((HKEY)(uintptr_t)0x80000001)
#define _cdecl
#define __cdecl
#define ANSI_CHARSET 0
#define INVALID_HANDLE_VALUE ((HANDLE)(intptr_t)-1)
#define PAGE_READWRITE 0x04
#define FILE_MAP_ALL_ACCESS 0xF001F

// Windows API functions for Linux
inline DWORD GetTickCount() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (DWORD)(ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

inline __time64_t _time64(__time64_t* timer) {
    __time64_t t = time(nullptr);
    if (timer) *timer = t;
    return t;
}

inline int _localtime64_s(struct tm* result, const __time64_t* time) {
    time_t t = *time;
    struct tm* tmp = localtime_r(&t, result);
    return (tmp == nullptr) ? -1 : 0;
}

#define stricmp strcasecmp
#define _stricmp strcasecmp
#define strnicmp strncasecmp
#define _alloca alloca
#define _vsnprintf vsnprintf
#define __stdcall

// Windows API function stubs for Linux
inline DWORD GetCurrentProcessId() {
    return (DWORD)getpid();
}

inline BOOL QueryPerformanceCounter(LARGE_INTEGER* lpPerformanceCount) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    lpPerformanceCount->QuadPart = (int64_t)ts.tv_sec * 1000000000LL + ts.tv_nsec;
    return TRUE;
}

inline BOOL QueryPerformanceFrequency(LARGE_INTEGER* lpFrequency) {
    lpFrequency->QuadPart = 1000000000LL; // nanoseconds
    return TRUE;
}

inline HANDLE CreateFileMappingA(HANDLE hFile, void* lpAttributes, DWORD flProtect, DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow, const char* lpName) {
    // Stub implementation - not used on Linux
    (void)hFile; (void)lpAttributes; (void)flProtect; (void)dwMaximumSizeHigh; (void)dwMaximumSizeLow; (void)lpName;
    return nullptr;
}

inline LPVOID MapViewOfFile(HANDLE hFileMappingObject, DWORD dwDesiredAccess, DWORD dwFileOffsetHigh, DWORD dwFileOffsetLow, size_t dwNumberOfBytesToMap) {
    // Stub implementation - not used on Linux
    (void)hFileMappingObject; (void)dwDesiredAccess; (void)dwFileOffsetHigh; (void)dwFileOffsetLow; (void)dwNumberOfBytesToMap;
    return nullptr;
}

inline BOOL FindNextFile(HANDLE hFindFile, LPWIN32_FIND_DATA lpFindFileData) {
    // Stub implementation - not used on Linux
    (void)hFindFile; (void)lpFindFileData;
    return FALSE;
}

inline BOOL FindClose(HANDLE hFindFile) {
    // Stub implementation - not used on Linux
    (void)hFindFile;
    return FALSE;
}

inline HANDLE FindFirstFile(LPCTSTR lpFileName, LPWIN32_FIND_DATA lpFindFileData) {
    // Stub implementation - not used on Linux
    (void)lpFileName; (void)lpFindFileData;
    return INVALID_HANDLE_VALUE;
}

inline BOOL GetFileAttributesEx(LPCTSTR lpFileName, _GET_FILEEX_INFO_LEVELS fInfoLevelId, void* lpFileInformation) {
    // Stub implementation - not used on Linux
    (void)lpFileName; (void)fInfoLevelId; (void)lpFileInformation;
    return FALSE;
}

// Define RECT structure
struct RECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
};

// Define MSG structure
struct MSG {
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    int pt_x;
    int pt_y;
};

// Define GUID structure
struct GUID {
    uint32_t Data1;
    uint16_t Data2;
    uint16_t Data3;
    uint8_t Data4[8];
};

// Define CRITICAL_SECTION
struct CRITICAL_SECTION {
    pthread_mutex_t mutex;
};

inline int CompareFileTime(const FILETIME* lpFileTime1, const FILETIME* lpFileTime2) {
    // Stub implementation - not used on Linux
    (void)lpFileTime1; (void)lpFileTime2;
    return 0;
}

// Provide a reasonable MAX_PATH for non-Windows builds
#ifndef MAX_PATH
#define MAX_PATH 260
#endif

// These will be defined by bass.h, but we declare them here for other uses
// Note: bass.h will redefine these as DWORD, which is compatible
#ifndef BASS_H
typedef DWORD HFX;
typedef DWORD HSYNC;
typedef DWORD HMUSIC;
typedef DWORD HSTREAM;
typedef DWORD HPLUGIN;
typedef DWORD HSAMPLE;
#endif
#endif
#include "misc/ModVal.h"

// fallback if NOMINMAX fails (somehow?)
#undef min
#undef max

// Define unreachable()
#ifdef _MSC_VER
#define unreachable std::unreachable
#else
#define unreachable __builtin_unreachable
#endif

// Removed wide string support
typedef std::string			SexyString;
#define _S(x)				x

#define sexystrncmp			strncmp
#define sexystrcmp			strcmp
#ifdef _WIN32
#define sexystricmp			stricmp
#else
#define sexystricmp			strcasecmp
#endif
#define sexysscanf			sscanf
#define sexyatoi			atoi
#define sexystrcpy			strcpy
#define sexystrlen			strlen
#define sexyisdigit			isdigit
#define sexyisalnum			isalnum
#define sexystrchr			strchr

#define SexyStringToStringFast(x)	(x)
#define SexyStringToWStringFast(x)	StringToWString(x)
#define StringToSexyStringFast(x)	(x)
#define WStringToSexyStringFast(x)	WStringToString(x)

#define LONG_BIGE_TO_NATIVE(l) (((l >> 24) & 0xFF) | ((l >> 8) & 0xFF00) | ((l << 8) & 0xFF0000) | ((l << 24) & 0xFF000000))
#define WORD_BIGE_TO_NATIVE(w) (((w >> 8) & 0xFF) | ((w << 8) & 0xFF00))
#define LONG_LITTLEE_TO_NATIVE(l) (l)
#define WORD_LITTLEE_TO_NATIVE(w) (w)

#define LENGTH(anyarray) (sizeof(anyarray) / sizeof(anyarray[0]))

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
#ifdef _MSC_VER
typedef __int64 int64;
#else
typedef long long int64;
#endif

typedef std::map<std::string, std::string>		DefinesMap;
typedef std::map<std::wstring, std::wstring>	WStringWStringMap;
typedef SexyString::value_type					SexyChar;
#define HAS_SEXYCHAR

namespace Sexy
{

const ulong SEXY_RAND_MAX = 0x7FFFFFFF;

extern bool			gDebug;
#ifdef _WIN32
extern HINSTANCE	gHInstance;
#endif

int					Rand();
int					Rand(int range);
float				Rand(float range);
void				SRand(ulong theSeed);
extern std::string	vformat(const char* fmt, va_list argPtr);
extern std::wstring	vformat(const wchar_t* fmt, va_list argPtr);
extern std::string	StrFormat(const char* fmt ...);
extern std::wstring	StrFormat(const wchar_t* fmt ...);
bool				CheckFor98Mill();
bool				CheckForVista();
std::string			GetAppDataFolder();
void				SetAppDataFolder(const std::string& thePath);
std::string			URLEncode(const std::string& theString);
std::string			StringToUpper(const std::string& theString);
std::wstring		StringToUpper(const std::wstring& theString);
std::string			StringToLower(const std::string& theString);
std::wstring		StringToLower(const std::wstring& theString);
std::wstring		StringToWString(const std::string &theString);
std::string			WStringToString(const std::wstring &theString);
SexyString			StringToSexyString(const std::string& theString);
SexyString			WStringToSexyString(const std::wstring& theString);
std::string			SexyStringToString(const SexyString& theString);
std::wstring		SexyStringToWString(const SexyString& theString);
std::string			Upper(const std::string& theData);
std::wstring		Upper(const std::wstring& theData);
std::string			Lower(const std::string& theData);
std::wstring		Lower(const std::wstring& theData);
std::string			Trim(const std::string& theString);
std::wstring		Trim(const std::wstring& theString);
bool				StringToInt(const std::string theString, int* theIntVal);
bool				StringToDouble(const std::string theString, double* theDoubleVal);
bool				StringToInt(const std::wstring theString, int* theIntVal);
bool				StringToDouble(const std::wstring theString, double* theDoubleVal);
int					StrFindNoCase(const char *theStr, const char *theFind);
bool				StrPrefixNoCase(const char *theStr, const char *thePrefix, int maxLength = 10000000);
SexyString			CommaSeperate(int theValue);
std::string			Evaluate(const std::string& theString, const DefinesMap& theDefinesMap);
std::string			XMLDecodeString(const std::string& theString);
std::string			XMLEncodeString(const std::string& theString);
std::wstring		XMLDecodeString(const std::wstring& theString);
std::wstring		XMLEncodeString(const std::wstring& theString);

bool				Deltree(const std::string& thePath);
bool				FileExists(const std::string& theFileName);
void				MkDir(const std::string& theDir);
std::string			GetFileName(const std::string& thePath, bool noExtension = false);
std::string			GetFileDir(const std::string& thePath, bool withSlash = false);
std::string			RemoveTrailingSlash(const std::string& theDirectory);
std::string			AddTrailingSlash(const std::string& theDirectory, bool backSlash = false);
time_t				GetFileDate(const std::string& theFileName);
std::string			GetCurDir();
std::string			GetFullPath(const std::string& theRelPath);
std::string			GetPathFrom(const std::string& theRelPath, const std::string& theDir);
bool				AllowAllAccess(const std::string& theFileName);
std::wstring		UTF8StringToWString(const std::string theString);

// Read memory and then move the pointer
void				SMemR(void*& _Src, void* _Dst, size_t _Size);
void				SMemRStr(void*& _Src, std::string& theString);
// Write memory and then move the pointer
void				SMemW(void*& _Dst, const void* _Src, size_t _Size);
void				SMemWStr(void*& _Dst, const std::string& theString);

inline void			inlineUpper(std::string &theData)
{
    //std::transform(theData.begin(), theData.end(), theData.begin(), toupper);

	int aStrLen = (int) theData.length();
	for (int i = 0; i < aStrLen; i++)
	{
		theData[i] = toupper(theData[i]);
	}
}

inline void			inlineUpper(std::wstring &theData)
{
    //std::transform(theData.begin(), theData.end(), theData.begin(), toupper);

	int aStrLen = (int) theData.length();
	for (int i = 0; i < aStrLen; i++)
	{
		theData[i] = towupper(theData[i]);
	}
}

inline void			inlineLower(std::string &theData)
{
    std::transform(theData.begin(), theData.end(), theData.begin(), tolower);
}

inline void			inlineLower(std::wstring &theData)
{
    std::transform(theData.begin(), theData.end(), theData.begin(), tolower);
}

inline void			inlineLTrim(std::string &theData, const std::string& theChars = " \t\r\n")
{
    theData.erase(0, theData.find_first_not_of(theChars));
}

inline void			inlineLTrim(std::wstring &theData, const std::wstring& theChars = L" \t\r\n")
{
    theData.erase(0, theData.find_first_not_of(theChars));
}


inline void			inlineRTrim(std::string &theData, const std::string& theChars = " \t\r\n")
{
    theData.resize(theData.find_last_not_of(theChars) + 1);
}

inline void			inlineTrim(std::string &theData, const std::string& theChars = " \t\r\n")
{
	inlineRTrim(theData, theChars);
	inlineLTrim(theData, theChars);
}

struct StringLessNoCase { 
	bool operator()(const std::string &s1, const std::string &s2) const { 
#ifdef _WIN32
		return _stricmp(s1.c_str(),s2.c_str())<0; 
#else
		return strcasecmp(s1.c_str(),s2.c_str())<0;
#endif
	} 
};

}

#endif //__SEXYAPPFRAMEWORK_COMMON_H__
