// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 12:54)

#include "System/SystemExport.h"

#include "InitOnce.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"

void System
	::SystemInitOnceInitialize(InitOncePtr initOnce) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::InitOnceInitialize(initOnce);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(initOnce);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SystemInitOnceExecuteOnce(InitOncePtr initOnce, InitOnceFunction initFunction, WindowVoidPtr parameter, WindowVoidPtr* context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::InitOnceExecuteOnce(initOnce, initFunction, parameter, context) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(initOnce);
	SYSTEM_UNUSED_ARG(initFunction);
	SYSTEM_UNUSED_ARG(parameter);
	SYSTEM_UNUSED_ARG(context);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SystemInitOnceBeginInitialize(InitOncePtr initOnce, InitOnceBeginInitialize flags, WindowBoolPtr pending, WindowVoidPtr* context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::InitOnceBeginInitialize(initOnce, EnumCastUnderlying(flags), pending, context) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(initOnce);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(pending);
	SYSTEM_UNUSED_ARG(context);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SystemInitOnceComplete(InitOncePtr initOnce, InitOnceBeginInitialize flags, WindowVoidPtr context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::InitOnceComplete(initOnce, EnumCastUnderlying(flags), context) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(initOnce);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(context);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
