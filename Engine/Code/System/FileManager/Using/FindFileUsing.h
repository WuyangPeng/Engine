// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:53)

#ifndef SYSTEM_FILE_MANAGE_FIND_FILE_USING_H
#define SYSTEM_FILE_MANAGE_FIND_FILE_USING_H

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	using FileWin32FindData = WIN32_FIND_DATA;
	using FileWin32FindDataPtr = LPWIN32_FIND_DATA;
	using FileInfoLevels = FINDEX_INFO_LEVELS;
	using FileSearchOps = FINDEX_SEARCH_OPS;

#else // !SYSTEM_PLATFORM_WIN32		

	struct FileWin32FindData
	{
		uint32_t dwFileAttributes;
		FileTime ftCreationTime;
		FileTime ftLastAccessTime;
		FileTime ftLastWriteTime;
		uint32_t nFileSizeHigh;
		uint32_t nFileSizeLow;
		uint32_t dwReserved0;
		uint32_t dwReserved1;
		TChar cFileName[260];
		TChar cAlternateFileName[14];
	};

	using FileWin32FindDataPtr = FileWin32FindData*;

	enum FileInfoLevels
	{
		FindExInfoStandard,
		FindExInfoBasic,
		FindExInfoMaxInfoLevel,
	};

	enum FileSearchOps
	{
		FindExSearchNameMatch,
		FindExSearchLimitToDirectories,
		FindExSearchLimitToDevices,
		FindExSearchMaxSearchOp
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_FILE_MANAGE_FIND_FILE_USING_H