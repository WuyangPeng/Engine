// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 0:11)

#include "System/SystemExport.h"

#include "MemoryHelper.h" 
#include "Using/VirtualToolsUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Window/WindowSystem.h"
#include "System/Window/Using/WindowUsing.h"

#include <cstdlib>

bool System
	::ReadMemoryOnProcess(WindowHandle process, WindowConstVoidPtr baseAddress, WindowVoidPtr buffer, WindowSize size, WindowSize* numberOfBytesRead) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::ReadProcessMemory(process, baseAddress, buffer, size, numberOfBytesRead) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(baseAddress);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(size);
	SYSTEM_UNUSED_ARG(numberOfBytesRead);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WriteMemoryOnProcess(WindowHandle process, WindowVoidPtr baseAddress, WindowConstVoidPtr buffer, WindowSize size, WindowSize* numberOfBytesWritten) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::WriteProcessMemory(process, baseAddress, buffer, size, numberOfBytesWritten) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(baseAddress);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(size);
	SYSTEM_UNUSED_ARG(numberOfBytesWritten);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowSize System
	::GetMinimumLargePageSize() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::GetLargePageMinimum();
#else // !SYSTEM_PLATFORM_WIN32
	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetProcessWorkingSize(WindowHandle process, WindowSizePtr minimumWorkingSetSize, WindowSizePtr maximumWorkingSetSize, WorkingSetSizesQuotaLimits* flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	WindowDWord workingSetSizesFlags{ 0 };
	const auto result = ::GetProcessWorkingSetSizeEx(process, minimumWorkingSetSize, maximumWorkingSetSize, &workingSetSizesFlags);

	if (result != g_False)
	{
		UnderlyingCastEnumPtr(workingSetSizesFlags, flags);

		return true;
	}
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(minimumWorkingSetSize);
	SYSTEM_UNUSED_ARG(maximumWorkingSetSize);
	SYSTEM_UNUSED_ARG(flags);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetProcessWorkingSize(WindowHandle process, WindowSize minimumWorkingSetSize, WindowSize maximumWorkingSetSize, WorkingSetSizesQuotaLimits flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::SetProcessWorkingSetSizeEx(process, minimumWorkingSetSize, maximumWorkingSetSize, EnumCastUnderlying(flags)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(minimumWorkingSetSize);
	SYSTEM_UNUSED_ARG(maximumWorkingSetSize);
	SYSTEM_UNUSED_ARG(flags);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::CreateMemoryResourceNotificationUseNotificationType(MemoryResourceNotificationType notificationType) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::CreateMemoryResourceNotification(notificationType);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(notificationType);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::QueryMemoryResourceNotificationState(WindowHandle resourceNotificationHandle, bool* resourceState) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	WindowBool resourceStateResult{ };
	if (::QueryMemoryResourceNotification(resourceNotificationHandle, &resourceStateResult) != g_False)
	{
		BoolConversion(resourceStateResult, resourceState);

		return true;
	}
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(resourceNotificationHandle);
	SYSTEM_UNUSED_ARG(resourceState);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CloseMemoryResourceNotificationHandle(WindowHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::CloseHandle(handle) == 0)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::MemorySet(void* bytes, int value, int byteSize) noexcept
{
	::memset(bytes, value, byteSize);
}

void System
	::MemoryCopy(void* dst, const void* src, uint32_t count) noexcept
{
	::memcpy(dst, src, count);
}

void* System
	::MallocMemory(size_t size) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26408)
	return ::malloc(size);
#include STSTEM_WARNING_POP
}

void System
	::FreeMemory(void* memory) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26408)
	::free(memory);
#include STSTEM_WARNING_POP
}
