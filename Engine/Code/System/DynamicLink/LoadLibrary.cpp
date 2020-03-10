// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:48)

#include "System/SystemExport.h"

#include "LoadLibrary.h"
#include "Flags/LoadLibraryFlags.h"
#include "System/Helper/WindowsMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"

System::DynamicLinkModule System
	::LoadDynamicLibrary(const DynamicLinkCharType* fileName, LoadLibrary flag) noexcept
{
	if (flag == LoadLibrary::NoFlags)
	{
		flag = LoadLibrary::Zero;
	}

#ifdef SYSTEM_PLATFORM_WIN32
	return ::LoadLibraryEx(fileName, nullptr, EnumCastUnderlying(flag));
#else // !SYSTEM_PLATFORM_WIN32
	return ::dlopen(fileName, flag);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FreeDynamicLibrary(DynamicLinkModule module) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::FreeLibrary(module) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	if (::dlclose(module) != 0)
		return false;
	else
		return true;
#endif // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkProcess System
	::GetProcessAddress(DynamicLinkModule module, const char* processName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetProcAddress(module, processName);
#else // !SYSTEM_PLATFORM_WIN32
	return ::dlsym(module, procName);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::DisableThreadDynamicLibraryCalls(DynamicLinkModule module) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::DisableThreadLibraryCalls(module) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
