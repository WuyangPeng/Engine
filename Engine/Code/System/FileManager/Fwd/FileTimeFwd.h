// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:52)

#ifndef SYSTEM_FILE_MANAGE_FILE_TIME_FWD_H
#define SYSTEM_FILE_MANAGE_FILE_TIME_FWD_H  

#include "FileFlagsFwd.h"

namespace System
{
	ComparesFileTimeReturn FileTimeCompare(const FileTime* lhsFileTime, const FileTime* rhsFileTime) noexcept;
	bool FileTimeConvertLocalFileTime(const FileTime* fileTime, FileTimePtr localFileTime) noexcept;
	bool GetSystemFileTime(WindowHandle file, FileTimePtr creationTime, FileTimePtr lastAccessTime, FileTimePtr lastWriteTime) noexcept;
	bool LocalFileTimeConvertFileTime(const FileTime* localFileTime, FileTimePtr fileTime) noexcept;
	bool SetSystemFileTime(WindowHandle file, const FileTime* creationTime, const FileTime* lastAccessTime, const FileTime* lastWriteTime) noexcept;
}

#endif // SYSTEM_FILE_MANAGE_FILE_TOOLS_FWD_H