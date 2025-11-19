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
#include <time.h>
#include <strings.h>
#include <cwctype>
#include <unistd.h>
#endif

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
#ifdef _WIN32
#include <windows.h>
#include <shellapi.h> 
#include <mmsystem.h>
#else
// Platform-independent definitions for types used by the codebase
#include <stdint.h>
typedef void* HINSTANCE;
typedef void* HWND;
typedef void* HICON;
typedef void* HMODULE;
typedef void* HANDLE;
typedef void* HKEY;
typedef void* HCURSOR;
typedef void* HFONT;
typedef uint32_t UINT;
typedef long LONG;
typedef intptr_t WPARAM;
typedef intptr_t LPARAM;
typedef intptr_t LRESULT;
typedef int64_t __time64_t;
#ifndef DWORD
typedef uint32_t DWORD;
#endif
#ifndef BOOL
typedef int BOOL;
#endif
#ifndef BYTE
typedef unsigned char BYTE;
#endif
#ifndef WORD
typedef unsigned short WORD;
#endif
typedef float FLOAT;
typedef FLOAT *PFLOAT;
typedef BOOL *PBOOL;
typedef BOOL *LPBOOL;
typedef BYTE *PBYTE;
typedef BYTE *LPBYTE;
typedef int *PINT;
typedef int *LPINT;
typedef WORD *PWORD;
typedef WORD *LPWORD;
typedef long *LPLONG;
typedef DWORD *PDWORD;
typedef DWORD *LPDWORD;
typedef void *LPVOID;
typedef const void *LPCVOID;
typedef void *LPDIRECTSOUNDBUFFER;
typedef void *LPEXCEPTION_POINTERS;
typedef void *LPDIRECT3DDEVICE7;
typedef void *LPDIRECTDRAW7;
typedef void *LPDIRECTDRAWSURFACE7;
typedef void *LPDIRECT3D7;
typedef void *LPDDPIXELFORMAT;
typedef void *LPDIRECTDRAWSURFACE;
typedef void *LPDIRECTDRAW;
typedef void *LPDIRECTDRAWPALETTE;
typedef void *HBITMAP;
typedef long HRESULT;
typedef struct {
    int unused;
} D3DVIEWPORT7;
typedef struct {
    int unused;
} DDPIXELFORMAT;
typedef struct {
    int unused;
} DDSURFACEDESC;
typedef struct {
    int unused;
} DDSURFACEDESC2;

// GUID structure
typedef struct _GUID {
    uint32_t Data1;
    uint16_t Data2;
    uint16_t Data3;
    uint8_t  Data4[8];
} GUID;

// FILETIME structure
typedef struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME;

// WIN32_FIND_DATA structure
typedef struct _WIN32_FIND_DATAA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
} WIN32_FIND_DATAA, *LPWIN32_FIND_DATA;

typedef const char* LPCTSTR;

// RECT structure  
typedef struct tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT;

// Windows message structure
typedef struct tagMSG {
    HWND   hwnd;
    UINT   message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD  time;
    int    pt_x;
    int    pt_y;
} MSG;

// File attribute data
typedef struct _WIN32_FILE_ATTRIBUTE_DATA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
} WIN32_FILE_ATTRIBUTE_DATA, *LPWIN32_FILE_ATTRIBUTE_DATA;

typedef enum _GET_FILEEX_INFO_LEVELS {
    GetFileExInfoStandard = 0
} GET_FILEEX_INFO_LEVELS;

// Critical section
typedef struct {
    void* unused[6];
} CRITICAL_SECTION;

// Large integer type
typedef struct {
    DWORD LowPart;
    long HighPart;
#ifdef _WIN32
    int64_t QuadPart;
#endif
} LARGE_INTEGER;

// Calling conventions
#define _cdecl
#define __cdecl
#define __stdcall
#define CALLBACK
#define WINAPI

// Registry constants
#define HKEY_CURRENT_USER ((HKEY)0x80000001)

// MessageBox constants
#define MB_OK 0x00000000L

// Character set constants
#define ANSI_CHARSET 0

// Time function compatibility
#define _time64(x) time(x)

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

// File mapping constants and functions
#define INVALID_HANDLE_VALUE ((HANDLE)-1)
#define PAGE_READWRITE 0x04
#define FILE_MAP_ALL_ACCESS 0xF001F

// Stub implementations for file mapping
inline DWORD GetCurrentProcessId() { return (DWORD)getpid(); }
inline HANDLE CreateFileMappingA(HANDLE hFile, void* lpAttributes, DWORD flProtect, 
                                  DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow, const char* lpName) {
    (void)hFile; (void)lpAttributes; (void)flProtect; 
    (void)dwMaximumSizeHigh; (void)dwMaximumSizeLow; (void)lpName;
    return nullptr;
}
inline void* MapViewOfFile(HANDLE hFileMappingObject, DWORD dwDesiredAccess, 
                            DWORD dwFileOffsetHigh, DWORD dwFileOffsetLow, size_t dwNumberOfBytesToMap) {
    (void)hFileMappingObject; (void)dwDesiredAccess; 
    (void)dwFileOffsetHigh; (void)dwFileOffsetLow; (void)dwNumberOfBytesToMap;
    return nullptr;
}
inline HANDLE FindFirstFile(const char* lpFileName, LPWIN32_FIND_DATA lpFindFileData) {
    (void)lpFileName; (void)lpFindFileData;
    return INVALID_HANDLE_VALUE;
}
inline BOOL FindNextFile(HANDLE hFindFile, LPWIN32_FIND_DATA lpFindFileData) {
    (void)hFindFile; (void)lpFindFileData;
    return FALSE;
}
inline BOOL FindClose(HANDLE hFindFile) {
    (void)hFindFile;
    return TRUE;
}
inline BOOL GetFileAttributesEx(const char* lpFileName, GET_FILEEX_INFO_LEVELS fInfoLevelId, LPVOID lpFileInformation) {
    (void)lpFileName; (void)fInfoLevelId; (void)lpFileInformation;
    return FALSE;
}
inline LONG CompareFileTime(const FILETIME* lpFileTime1, const FILETIME* lpFileTime2) {
    (void)lpFileTime1; (void)lpFileTime2;
    return 0;
}

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
#define _stricmp			stricmp
#define stricmp				_stricmp
#define strnicmp			_strnicmp
#define _vsnprintf			vsnprintf
#define _alloca				alloca
#else
#define sexystricmp			strcasecmp
#define _stricmp			strcasecmp
#define stricmp				strcasecmp
#define strnicmp			strncasecmp
#define _vsnprintf			vsnprintf
#define _alloca				alloca
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
#ifdef _WIN32
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

// Platform-independent GetTickCount
#ifndef _WIN32
inline DWORD GetTickCount() {
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (DWORD)((ts.tv_sec * 1000) + (ts.tv_nsec / 1000000));
}
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
