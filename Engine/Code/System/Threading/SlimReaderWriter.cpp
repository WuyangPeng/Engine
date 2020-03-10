// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:16)

#include "System/SystemExport.h"

#include "SlimReaderWriter.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Helper/PragmaWarning.h"

void System
	::InitializeSlimReaderWriterLock(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::InitializeSRWLock(slimReaderWriterLock);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(slimReaderWriterLock);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::ReleaseSlimReaderWriterLockExclusive(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26110) 
		::ReleaseSRWLockExclusive(slimReaderWriterLock);
	#include STSTEM_WARNING_POP

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(slimReaderWriterLock);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::ReleaseSlimReaderWriterLockShared(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::ReleaseSRWLockShared(slimReaderWriterLock);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(slimReaderWriterLock);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::AcquireSlimReaderWriterLockExclusive(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::AcquireSRWLockExclusive(slimReaderWriterLock);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(slimReaderWriterLock);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::AcquireSlimReaderWriterLockShared(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::AcquireSRWLockShared(slimReaderWriterLock);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(slimReaderWriterLock);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::TryAcquireSlimReaderWriterLockExclusive(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::TryAcquireSRWLockExclusive(slimReaderWriterLock) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(slimReaderWriterLock);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::TryAcquireSlimReaderWriterLockShared(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::TryAcquireSRWLockShared(slimReaderWriterLock) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(slimReaderWriterLock);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
