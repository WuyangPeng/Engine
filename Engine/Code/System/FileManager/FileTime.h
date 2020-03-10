// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 14:54)

#ifndef SYSTEM_FILE_MANAGE_FILE_TIME_H
#define SYSTEM_FILE_MANAGE_FILE_TIME_H

#include "System/SystemDll.h" 

#include "Using/FileUsing.h"
#include "Fwd/FileFlagsFwd.h"
#include "System/Threading/Using/ThreadPoolUsing.h" 

namespace System
{
	// �ļ�ʱ��Ļ�ȡ������

	ComparesFileTimeReturn SYSTEM_DEFAULT_DECLARE FileTimeCompare(const FileTime* lhsFileTime, const FileTime* rhsFileTime) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FileTimeConvertLocalFileTime(const FileTime* fileTime, FileTimePtr localFileTime) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetSystemFileTime(WindowHandle file, FileTimePtr creationTime, FileTimePtr lastAccessTime, FileTimePtr lastWriteTime) noexcept;
	bool SYSTEM_DEFAULT_DECLARE LocalFileTimeConvertFileTime(const FileTime* localFileTime, FileTimePtr fileTime) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemFileTime(WindowHandle file, const FileTime* creationTime, const FileTime* lastAccessTime, const FileTime* lastWriteTime) noexcept;
}

#endif // SYSTEM_FILE_MANAGE_FILE_TIME_H