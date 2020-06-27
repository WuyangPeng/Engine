// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:57)

#include "System/SystemExport.h"

#include "FileTime.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Helper/EnumCast.h"

System::ComparesFileTimeReturn System
	::FileTimeCompare(const FileTime* lhsFileTime, const FileTime* rhsFileTime) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return UnderlyingCastEnum<ComparesFileTimeReturn>(::CompareFileTime(lhsFileTime, rhsFileTime));
#else // !SYSTEM_PLATFORM_WIN32
	if (lhsFileTime->dwHighDateTime < rhsFileTime->dwHighDateTime)
		return ComparesFileTimeReturn::Earlier;
	else if (rhsFileTime->dwHighDateTime < lhsFileTime->dwHighDateTime)
		return ComparesFileTimeReturn::Later;
	else if (lhsFileTime->dwLowDateTime < rhsFileTime->dwLowDateTime)
		return ComparesFileTimeReturn::Earlier;
	else if (rhsFileTime->dwLowDateTime < lhsFileTime->dwLowDateTime)
		return ComparesFileTimeReturn::Later;
	else
		return ComparesFileTimeReturn::Equal;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FileTimeConvertLocalFileTime(const FileTime* fileTime, FileTimePtr localFileTime) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::FileTimeToLocalFileTime(fileTime, localFileTime) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fileTime);
	SYSTEM_UNUSED_ARG(localFileTime);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemFileTime(WindowHandle file, FileTimePtr creationTime, FileTimePtr lastAccessTime, FileTimePtr lastWriteTime) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::GetFileTime(file, creationTime, lastAccessTime, lastWriteTime) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(creationTime);
	SYSTEM_UNUSED_ARG(lastAccessTime);
	SYSTEM_UNUSED_ARG(lastWriteTime);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::LocalFileTimeConvertFileTime(const FileTime* localFileTime, FileTimePtr fileTime) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::LocalFileTimeToFileTime(localFileTime, fileTime) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(localFileTime);
	SYSTEM_UNUSED_ARG(fileTime);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemFileTime(WindowHandle file, const FileTime* creationTime, const FileTime* lastAccessTime, const FileTime* lastWriteTime) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::SetFileTime(file, creationTime, lastAccessTime, lastWriteTime) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(creationTime);
	SYSTEM_UNUSED_ARG(lastAccessTime);
	SYSTEM_UNUSED_ARG(lastWriteTime);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

