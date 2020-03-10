// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 14:54)

#ifndef SYSTEM_FILE_MANAGE_FILE_H
#define SYSTEM_FILE_MANAGE_FILE_H

#include "System/SystemDll.h"

#include "Using/FileUsing.h"
#include "Using/CFileUsing.h"
#include "Fwd/FileFlagsFwd.h"
#include "System/Threading/Using/OverlappedToolsUsing.h" 
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
	// 文件的打开、关闭、创建、读写和删除。

	bool SYSTEM_DEFAULT_DECLARE RemoveSystemFile(const CFileString& fileName) noexcept;
	bool SYSTEM_DEFAULT_DECLARE MoveSystemFile(const String& existingFileName, const String& newFileName) noexcept;

	WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemFile(const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode,
														 WindowSecurityAttributesPtr securityAttributes, FileHandleCreationDisposition creation, FileHandleAttributes attributes,
														 FileHandleOther other, FileHandleSecurity security, WindowHandle templateFile) noexcept;

	WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemFile(const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode, FileHandleCreationDisposition creation) noexcept;

	WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemFile(const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode, FileHandleCreationDisposition creation,
														 FileHandleAttributes attributes, FileHandleOther other, FileHandleSecurity security) noexcept;

	bool SYSTEM_DEFAULT_DECLARE CloseSystemFile(WindowHandle file) noexcept;
	bool SYSTEM_DEFAULT_DECLARE IsFileHandleValid(WindowHandle file) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetFileLength(WindowHandle file, uint64_t& fileSize) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetFileLength(WindowHandle file, WindowLargeIntegerPtr fileSize) noexcept;

	bool SYSTEM_DEFAULT_DECLARE ReadSystemFile(WindowHandle file, WindowVoidPtr buffer, WindowDWord numberOfBytesToRead, WindowDWordPtr numberOfBytesRead, WindowOverlappedPtr overlapped) noexcept;
	bool SYSTEM_DEFAULT_DECLARE ReadSystemFile(WindowHandle file, WindowVoidPtr buffer, WindowDWord numberOfBytesToRead, WindowDWordPtr numberOfBytesRead) noexcept;
	bool SYSTEM_DEFAULT_DECLARE ReadSystemFile(WindowHandle file, WindowVoidPtr buffer, WindowDWord numberOfBytesToRead,
											   WindowOverlappedPtr overlapped, WindowOverlappedCompletionRoutine completionRoutine) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WriteSystemFile(WindowHandle file, WindowConstVoidPtr buffer, WindowDWord numberOfBytesToWrite, WindowDWordPtr numberOfBytesWritten, WindowOverlappedPtr overlapped) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WriteSystemFile(WindowHandle file, WindowConstVoidPtr buffer, WindowDWord numberOfBytesToWrite, WindowDWordPtr numberOfBytesWritten) noexcept;
	bool SYSTEM_DEFAULT_DECLARE WriteSystemFile(WindowHandle file, WindowConstVoidPtr buffer, WindowDWord numberOfBytesToWrite, WindowOverlappedPtr overlapped, WindowOverlappedCompletionRoutine completionRoutine) noexcept;
	bool SYSTEM_DEFAULT_DECLARE AppendSystemFile(WindowHandle file, WindowConstVoidPtr buffer, WindowDWord numberOfBytesToWrite, WindowDWordPtr numberOfBytesWritten) noexcept;

	bool SYSTEM_DEFAULT_DECLARE CopySystemFile(const String& existingFileName, const String& newFileName, bool failIfExists) noexcept;
	bool SYSTEM_DEFAULT_DECLARE CopySystemFile(const String& existingFileName, const String& newFileName) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemFilePointer(WindowHandle file, WindowLong distanceToMove, WindowLargeIntegerPtr newFilePointer, FilePointer moveMethod) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemFilePointer(WindowHandle file, WindowLargeInteger distanceToMove, WindowLargeIntegerPtr newFilePointer, FilePointer moveMethod) noexcept;

	bool SYSTEM_DEFAULT_DECLARE SetEndOfSystemFile(WindowHandle file) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FlushSystemFileBuffers(WindowHandle file) noexcept;
}

#endif // SYSTEM_FILE_MANAGE_FILE_H