// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:24)

#include "System/SystemExport.h"

#include "VirtualTools.h" 
#include "Flags/VirtualToolsFlags.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"

System::WindowVoidPtr System
	::AllocateVirtual(WindowVoidPtr address, WindowSize size, MemoryAllocation allocationType, MemoryProtect protect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::VirtualAlloc(address, size, EnumCastUnderlying(allocationType), EnumCastUnderlying(protect));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(address);
	SYSTEM_UNUSED_ARG(size);
	SYSTEM_UNUSED_ARG(allocationType);
	SYSTEM_UNUSED_ARG(protect);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System
	::AllocateVirtual(WindowHandle process, WindowVoidPtr address, WindowSize size, MemoryAllocation allocationType, MemoryProtect protect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::VirtualAllocEx(process, address, size, EnumCastUnderlying(allocationType), EnumCastUnderlying(protect));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(address);
	SYSTEM_UNUSED_ARG(size);
	SYSTEM_UNUSED_ARG(allocationType);
	SYSTEM_UNUSED_ARG(protect);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FreeVirtual(WindowVoidPtr address) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	constexpr auto freeType = EnumCastUnderlying(MemoryAllocation::Release);

	if (::VirtualFree(address, 0, freeType) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(address);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FreeVirtual(WindowHandle process, WindowVoidPtr address) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	constexpr auto freeType = EnumCastUnderlying(MemoryAllocation::Release);

	if (::VirtualFreeEx(process, address, 0, freeType) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(address);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetVirtualProtect(WindowVoidPtr address, WindowSize size, MemoryProtect newProtect, MemoryProtect* oldProtect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	WindowDWord oldMemory{ 0 };
	const auto result = ::VirtualProtect(address, size, EnumCastUnderlying(newProtect), &oldMemory);

	if (result != g_False)
	{
		UnderlyingCastEnumPtr(oldMemory, oldProtect);

		return true;
	}
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(address);
	SYSTEM_UNUSED_ARG(size);
	SYSTEM_UNUSED_ARG(newProtect);
	SYSTEM_UNUSED_ARG(oldProtect);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetVirtualProtect(WindowHandle process, WindowVoidPtr address, WindowSize size, MemoryProtect newProtect, MemoryProtect* oldProtect) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	WindowDWord oldMemory{ 0 };
	const auto result = ::VirtualProtectEx(process, address, size, EnumCastUnderlying(newProtect), &oldMemory);

	if (result != g_False)
	{
		UnderlyingCastEnumPtr(oldMemory, oldProtect);

		return true;
	}
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(address);
	SYSTEM_UNUSED_ARG(size);
	SYSTEM_UNUSED_ARG(newProtect);
	SYSTEM_UNUSED_ARG(oldProtect);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetVirtualQuery(WindowVoidPtr address, MemoryBasicInformationPtr buffer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	constexpr auto memoryBasicInformationSize = sizeof(MemoryBasicInformation);

	const auto size = ::VirtualQuery(address, buffer, memoryBasicInformationSize);

	if (size == memoryBasicInformationSize)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(address);
	SYSTEM_UNUSED_ARG(buffer);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetVirtualQuery(WindowHandle process, WindowVoidPtr address, MemoryBasicInformationPtr buffer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	constexpr auto memoryBasicInformationSize = sizeof(MemoryBasicInformation);
	const auto size = ::VirtualQueryEx(process, address, buffer, memoryBasicInformationSize);

	if (size == memoryBasicInformationSize)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(address);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(process);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::LockVirtual(WindowVoidPtr address, WindowSize size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::VirtualLock(address, size) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(address);
	SYSTEM_UNUSED_ARG(size);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::UnlockVirtual(WindowVoidPtr address, WindowSize size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::VirtualUnlock(address, size) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(address);
	SYSTEM_UNUSED_ARG(size);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System
	::GetVirtualAllocNuma(WindowHandle process, WindowVoidPtr address, WindowSize size, MemoryAllocation allocationType, MemoryProtect protect, WindowDWord preferred) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::VirtualAllocExNuma(process, address, size, EnumCastUnderlying(allocationType), EnumCastUnderlying(protect), preferred);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(address);
	SYSTEM_UNUSED_ARG(size);
	SYSTEM_UNUSED_ARG(allocationType);
	SYSTEM_UNUSED_ARG(protect);
	SYSTEM_UNUSED_ARG(preferred);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}
