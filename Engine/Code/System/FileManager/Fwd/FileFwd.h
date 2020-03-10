// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:52)

#ifndef SYSTEM_FILE_MANAGE_FILE_FWD_H
#define SYSTEM_FILE_MANAGE_FILE_FWD_H  

#include "FileFlagsFwd.h"
#include "System/Threading/Using/OverlappedToolsUsing.h"

namespace System
{
	bool RemoveSystemFile(const CFileString& fileName) noexcept;
	bool MoveSystemFile(const String& existingFileName, const String& newFileName) noexcept;

	WindowHandle CreateSystemFile(const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode,
								  WindowSecurityAttributesPtr securityAttributes, FileHandleCreationDisposition creation, FileHandleAttributes attributes,
								  FileHandleOther other, FileHandleSecurity security, WindowHandle templateFile) noexcept;

	WindowHandle CreateSystemFile(const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode, FileHandleCreationDisposition creation) noexcept;

	WindowHandle CreateSystemFile(const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode, FileHandleCreationDisposition creation,
								  FileHandleAttributes attributes, FileHandleOther other, FileHandleSecurity security) noexcept;

	bool CloseSystemFile(WindowHandle file) noexcept;
	bool IsFileHandleValid(WindowHandle file) noexcept;

	bool GetFileLength(WindowHandle file, uint64_t& fileSize) noexcept;
	bool GetFileLength(WindowHandle file, WindowLargeIntegerPtr fileSize) noexcept;

	bool ReadSystemFile(WindowHandle file, WindowVoidPtr buffer, WindowDWord numberOfBytesToRead, WindowDWordPtr numberOfBytesRead, WindowOverlappedPtr overlapped) noexcept;
	bool ReadSystemFile(WindowHandle file, WindowVoidPtr buffer, WindowDWord numberOfBytesToRead, WindowDWordPtr numberOfBytesRead) noexcept;
	bool ReadSystemFile(WindowHandle file, WindowVoidPtr buffer, WindowDWord numberOfBytesToRead, WindowOverlappedPtr overlapped, WindowOverlappedCompletionRoutine completionRoutine) noexcept;
	bool WriteSystemFile(WindowHandle file, WindowConstVoidPtr buffer, WindowDWord numberOfBytesToWrite, WindowDWordPtr numberOfBytesWritten, WindowOverlappedPtr overlapped) noexcept;
	bool WriteSystemFile(WindowHandle file, WindowConstVoidPtr buffer, WindowDWord numberOfBytesToWrite, WindowDWordPtr numberOfBytesWritten) noexcept;
	bool WriteSystemFile(WindowHandle file, WindowConstVoidPtr buffer, WindowDWord numberOfBytesToWrite, WindowOverlappedPtr overlapped, WindowOverlappedCompletionRoutine completionRoutine) noexcept;
	bool AppendSystemFile(WindowHandle file, WindowConstVoidPtr buffer, WindowDWord numberOfBytesToWrite, WindowDWordPtr numberOfBytesWritten) noexcept;

	bool CopySystemFile(const String& existingFileName, const String& newFileName, bool failIfExists) noexcept;
	bool CopySystemFile(const String& existingFileName, const String& newFileName) noexcept;
	bool SetSystemFilePointer(WindowHandle file, WindowLong distanceToMove, WindowLargeIntegerPtr newFilePointer, FilePointer moveMethod) noexcept;
	bool SetSystemFilePointer(WindowHandle file, WindowLargeInteger distanceToMove, WindowLargeIntegerPtr newFilePointer, FilePointer moveMethod) noexcept;

	bool SetEndOfSystemFile(WindowHandle file) noexcept;
	bool FlushSystemFileBuffers(WindowHandle file) noexcept;
}

#endif // SYSTEM_FILE_MANAGE_FILE_FWD_H