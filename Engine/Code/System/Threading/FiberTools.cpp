// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:15)

#include "System/SystemExport.h"

#include "FiberTools.h"    
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"

System::WindowDWord System
	::SystemFlsAlloc(FlsCallbackFunction callback) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::FlsAlloc(callback);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(callback);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System
	::GetFlsValue(WindowDWord flsIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::FlsGetValue(flsIndex);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(flsIndex);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetFlsValue(WindowDWord flsIndex, WindowVoidPtr flsData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::FlsSetValue(flsIndex, flsData) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(flsIndex);
	SYSTEM_UNUSED_ARG(flsData);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SystemFlsFree(WindowDWord flsIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::FlsFree(flsIndex) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(flsIndex);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsSystemThreadAFiber() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::IsThreadAFiber() != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::SwitchToSystemFiber(WindowVoidPtr fiber) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::SwitchToFiber(fiber);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fiber);
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System
	::ConvertThreadToSystemFiber(WindowVoidPtr parameter) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::ConvertThreadToFiber(parameter);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(parameter);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::DeleteSystemFiber(WindowVoidPtr fiber) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::DeleteFiber(fiber);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fiber);
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System
	::CreateSystemFiber(WindowSize stackSize, FiberStartRoutine startAddress, WindowVoidPtr parameter) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateFiber(stackSize, startAddress, parameter);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(stackSize);
	SYSTEM_UNUSED_ARG(startAddress);
	SYSTEM_UNUSED_ARG(parameter);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::ConvertSystemFiberToThread() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::ConvertFiberToThread() != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
