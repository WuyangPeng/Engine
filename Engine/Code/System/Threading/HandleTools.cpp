// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:15)

#include "System/SystemExport.h"

#include "HandleTools.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"
#include "System/EnumOperator/EnumCastDetail.h"

bool System
	::SetThreadHandleInformation(ThreadHandle object, HandleInformation mask, HandleInformation flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetHandleInformation(object, EnumCastUnderlying(mask), EnumCastUnderlying(flags)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(object);
	SYSTEM_UNUSED_ARG(mask);
	SYSTEM_UNUSED_ARG(flags);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetThreadHandleInformation(ThreadHandle object, HandleInformation* flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	WindowDWord information{ 0 };
	if (::GetHandleInformation(object, &information) != g_False)
	{
		UnderlyingCastEnumPtr(information, flags);

		return true;
	}
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(object);
	SYSTEM_UNUSED_ARG(flags);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
	}

bool System
	::DuplicateThreadHandle(WindowHandle sourceProcessHandle, ThreadHandle sourceHandle, WindowHandle targetProcessHandle, ThreadHandlePtr targetHandle,
							WindowDWord desiredAccess, bool inheritHandle, DuplicateOptions options) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::DuplicateHandle(sourceProcessHandle, sourceHandle, targetProcessHandle, targetHandle, desiredAccess, BoolConversion(inheritHandle), EnumCastUnderlying(options)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(sourceProcessHandle);
	SYSTEM_UNUSED_ARG(sourceHandle);
	SYSTEM_UNUSED_ARG(targetProcessHandle);
	SYSTEM_UNUSED_ARG(targetHandle);
	SYSTEM_UNUSED_ARG(desiredAccess);
	SYSTEM_UNUSED_ARG(inheritHandle);
	SYSTEM_UNUSED_ARG(options);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}


