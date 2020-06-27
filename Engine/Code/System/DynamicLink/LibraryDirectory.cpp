// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.2.0.0 (2020/05/09 13:43)

#include "System/SystemExport.h"

#include "LibraryDirectory.h"
#include "System/Helper/WindowsMacro.h"

bool System
	::SetLibraryDirectory(const DynamicLinkCharType* pathName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetDllDirectory(pathName) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetLibraryDirectory(WindowDWord bufferLength, DynamicLinkCharType* buffer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetDllDirectory(bufferLength, buffer);
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
