// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:22)

#ifndef SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_FWD_H
#define SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_FWD_H

#include "MemoryToolsFlagsFwd.h"
#include "System/MemoryTools/Using/MemoryHelperUsing.h" 

namespace System
{
	void MemorySet(void* bytes, int value, int byteSize) noexcept;
	void MemoryCopy(void* dst, const void* src, uint32_t count) noexcept;
	void* MallocMemory(size_t size) noexcept;
	void FreeMemory(void* memory) noexcept;

	template<typename T>
	void FillMemoryToZero(T& value) noexcept;

	template <typename T>
	T GetWindowsStructDefaultSize() noexcept;

	bool ReadMemoryOnProcess(WindowHandle process, WindowConstVoidPtr baseAddress, WindowVoidPtr buffer, WindowSize size, WindowSize* numberOfBytesRead) noexcept;
	bool WriteMemoryOnProcess(WindowHandle process, WindowVoidPtr baseAddress, WindowConstVoidPtr buffer, WindowSize size, WindowSize* numberOfBytesWritten) noexcept;
	bool GetProcessWorkingSize(WindowHandle process, WindowSizePtr minimumWorkingSetSize, WindowSizePtr maximumWorkingSetSize, WorkingSetSizesQuotaLimits* flags) noexcept;
	bool SetProcessWorkingSize(WindowHandle process, WindowSize minimumWorkingSetSize, WindowSize maximumWorkingSetSize, WorkingSetSizesQuotaLimits flags) noexcept;
	WindowSize GetMinimumLargePageSize() noexcept;
	WindowHandle CreateMemoryResourceNotificationUseNotificationType(MemoryResourceNotificationType notificationType) noexcept;
	bool QueryMemoryResourceNotificationState(WindowHandle resourceNotificationHandle, bool* resourceState) noexcept;
	bool CloseMemoryResourceNotificationHandle(WindowHandle handle) noexcept;
}

#endif // SYSTEM_MEMORY_TOOLS_MEMORY_HELPER_FWD_H