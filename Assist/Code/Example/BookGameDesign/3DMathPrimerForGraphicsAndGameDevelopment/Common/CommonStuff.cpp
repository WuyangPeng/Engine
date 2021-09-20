/////////////////////////////////////////////////////////////////////////////
//
// 3D Math Primer for Games and Graphics Development
//
// CommonStuff.cpp - Miscelaneous code that doesn't belong elsewhere.
//
// Visit gamemath.com for the latest version of this file.
//
/////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <cstdio>
#include <cstdarg>
#include <cstring>

#include "CommonStuff.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(4996)
#include SYSTEM_WARNING_DISABLE(26477)
#include SYSTEM_WARNING_DISABLE(26481)   
#include SYSTEM_WARNING_DISABLE(26492) 
#ifdef WIN32
	#include <windows.h>
#endif

namespace ThreeDMathPrimerForGraphicsAndGameDevelopment
{
	const char* abortSourceFile = "(unknown)";
	int abortSourceLine;

	/////////////////////////////////////////////////////////////////////////////
	//
	// global code
	//
	/////////////////////////////////////////////////////////////////////////////

	//---------------------------------------------------------------------------
	// areWeBeingDebugged()
	//
	// Return true if we are running under the debugger

	bool areWeBeingDebugged() noexcept
	{
	#ifdef WIN32

		// This routine is in kernel32.  Acquire access to the
		// DLL

		HINSTANCE h = LoadLibraryA("kernel32.dll");
		if (h == nullptr)
		{
			return false;
		}

		// Fetch the code

		FARPROC func = GetProcAddress(h, "IsDebuggerPresent");
		if (func == nullptr)
		{
			return false;
		}

		// Actually call the routine

		const bool result = (func() != FALSE);

		// Don't hang on to any resources we don't need

		FreeLibrary(h);

		// Return the result

		return result;
	#else

		// For now, let's assume we are being debugged
		// in a debug build, and otherwise we're not being
		// debugged

	#ifdef _DEBUG
		return true;
	#else
		return false;
	#endif

	#endif
	}

	//---------------------------------------------------------------------------
	// reallyAbort
	//
	// Fatal error.  Usually called through the ABORT macro

	void reallyAbort(const char* fmt, ...)
	{

		// Format the error message into our buffer

		char errMsg[1024]{}; 
		va_list ap = nullptr;
		va_start(ap, fmt);
		vsprintf(&errMsg[0], fmt, ap);
		va_end(ap);

		// Tack on the source file and line number

		sprintf(strchr(&errMsg[0], '\0'), "\n%s line %d", abortSourceFile, abortSourceLine);

		// Windows?  Dump message box

	#ifdef WIN32

		// Check if we're under the debugger

		if (areWeBeingDebugged())
		{

			// Dump error message to the debug console

			OutputDebugStringA("FATAL ERROR: ");
			OutputDebugStringA(&errMsg[0]);
			OutputDebugStringA("\n");

			// Break the program, so we can check out what was going on.

// 			_asm {
// 
// 				// HELLO! If you hit this breakpoint, then look at the debug
// 				// console, and go up the call stack to see what went wrong!
// 
// 				int 3;
// 			}

			// You can try to keep running, if you want...

		}
		else
		{

			// Just dump a message box and terminate the app

			MessageBoxA(nullptr, &errMsg[0], "FATAL ERROR", MB_OK | MB_ICONERROR);
			ExitProcess(1);
		}
	#else

		// Just dump it to printf and use exit.  On most OSs,
		// this is basically useless for debugging, so you'd
		// want to do better, especially under the debugger

		printf("FATAL ERROR: %s\n", errMsg);
		exit(1);

	#endif
	}
}
#include STSTEM_WARNING_POP