// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.2.0.0 (2020/05/09 13:44)

#include "System/SystemExport.h"

#include "LibraryTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

System::DynamicLinkModule System
	::GetDynamicLinkHandle(const DynamicLinkCharType* moduleName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetModuleHandle(moduleName);
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetDynamicLinkFileName(DynamicLinkModule module, DynamicLinkCharType* filename, WindowDWord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetModuleFileName(module, filename, size);
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetDynamicLinkHandle(GetModuleHandle flags, const DynamicLinkCharType* moduleName, DynamicLinkModule* module) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetModuleHandleEx(EnumCastUnderlying(flags), moduleName, module) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

