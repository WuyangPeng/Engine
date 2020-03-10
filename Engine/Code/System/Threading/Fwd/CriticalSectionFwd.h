// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:09)

#ifndef SYSTEM_THREADING_CRITICAL_SECTION_FWD_H
#define SYSTEM_THREADING_CRITICAL_SECTION_FWD_H  

#include "ThreadingFlagsFwd.h"
#include "System/Threading/Using/CriticalSectionUsing.h"

namespace System
{
	bool InitializeSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection, WindowDWord spinCount, CriticalSectionInfo flags) noexcept;
	bool InitializeSystemCriticalSectionAndSpinCount(ThreadingCriticalSectionPtr criticalSection, WindowDWord spinCount) noexcept;
	bool InitializeSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept;

	void DeleteSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept;
	void EnterSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept;
	void LeaveSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept;
	bool TryEnterSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept;
	WindowDWord SetSystemCriticalSectionSpinCount(ThreadingCriticalSectionPtr criticalSection, WindowDWord spinCount) noexcept;
}

#endif // SYSTEM_THREADING_CRITICAL_SECTION_FWD_H