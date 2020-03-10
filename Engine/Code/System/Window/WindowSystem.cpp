// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:40)

#include "System/SystemExport.h"

#include "WindowSystem.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"

#ifdef SYSTEM_PLATFORM_WIN32
	#include <ImageHlp.h>
	#include <WindowsX.h>
#endif // SYSTEM_PLATFORM_WIN32

#include <cstdlib>

using std::system;

void System
	::GetWindowSystemInfo(WindowSystemInfo& systemInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::GetSystemInfo(&systemInfo);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(systemInfo);
#endif // SYSTEM_PLATFORM_WIN32	
}

void System
	::DebugBreak() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::__debugbreak();
#else // !SYSTEM_PLATFORM_WIN32

#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::Exit() noexcept
{
	::exit(0);
}

bool System
	::GetNumaProcessorNodeNumber(WindowUChar processor, WindowUCharPtr nodeNumber) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetNumaProcessorNode(processor, nodeNumber) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(processor);
	SYSTEM_UNUSED_ARG(nodeNumber);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

int System
	::SystemCommand(const char* command) noexcept
{
	return system(command);
}

bool System
	::SetSystemCurrentDirectory(const TChar* pathName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetCurrentDirectory(pathName) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(pathName);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemUserName(TChar* buffer, WindowDWord* bufferCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetUserName(buffer, bufferCount) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(bufferCount);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSystemCurrentDirectory(WindowDWord bufferLength, TChar* buffer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetCurrentDirectory(bufferLength, buffer);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(bufferLength);
	SYSTEM_UNUSED_ARG(buffer);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowBool System
	::BoolConversion(bool value) noexcept
{
	if (value)
		return g_True;
	else
		return g_False;
}

void System
	::BoolConversion(WindowBool value, bool* result) noexcept
{
	if (result != nullptr)
	{
		*result = ((value != g_False) ? true : false);
	}
}

