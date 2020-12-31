//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 12:58)

#ifndef SYSTEM_FILE_MANAGE_FILE_H
#define SYSTEM_FILE_MANAGE_FILE_H

#include "System/SystemDll.h"

#include "Fwd/FileFlagsFwd.h"
#include "Using/CFileUsing.h"
#include "Using/FileUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"
#include "System/Threading/Using/OverlappedToolsUsing.h"

namespace System
{
    // 文件的打开、关闭、创建、读写和删除。

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE RemoveSystemFile(const CFileString& fileName) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE MoveSystemFile(const String& existingFileName, const String& newFileName) noexcept;

    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemFile(const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode,
                                                                       WindowSecurityAttributesPtr securityAttributes, FileHandleCreationDisposition creation, FileHandleAttributes attributes,
                                                                       FileHandleOther other, FileHandleSecurity security, WindowHandle templateFile) noexcept;

    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemFile(const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode, FileHandleCreationDisposition creation) noexcept;

    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemFile(const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode, FileHandleCreationDisposition creation,
                                                                       FileHandleAttributes attributes, FileHandleOther other, FileHandleSecurity security) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CloseSystemFile(WindowHandle file) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsFileHandleValid(WindowHandle file) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetFileLength(WindowHandle file, uint64_t& fileSize) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetFileLength(WindowHandle file, WindowLargeIntegerPtr fileSize) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ReadSystemFile(WindowHandle file, WindowVoidPtr buffer, WindowDWord numberOfBytesToRead, WindowDWordPtr numberOfBytesRead, WindowOverlappedPtr overlapped) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ReadSystemFile(WindowHandle file, WindowVoidPtr buffer, WindowDWord numberOfBytesToRead, WindowDWordPtr numberOfBytesRead) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ReadSystemFile(WindowHandle file, WindowVoidPtr buffer, WindowDWord numberOfBytesToRead,
                                                             WindowOverlappedPtr overlapped, WindowOverlappedCompletionRoutine completionRoutine) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WriteSystemFile(WindowHandle file, WindowConstVoidPtr buffer, WindowDWord numberOfBytesToWrite, WindowDWordPtr numberOfBytesWritten, WindowOverlappedPtr overlapped) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WriteSystemFile(WindowHandle file, WindowConstVoidPtr buffer, WindowDWord numberOfBytesToWrite, WindowDWordPtr numberOfBytesWritten) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE WriteSystemFile(WindowHandle file, WindowConstVoidPtr buffer, WindowDWord numberOfBytesToWrite, WindowOverlappedPtr overlapped, WindowOverlappedCompletionRoutine completionRoutine) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE AppendSystemFile(WindowHandle file, WindowConstVoidPtr buffer, WindowDWord numberOfBytesToWrite, WindowDWordPtr numberOfBytesWritten) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CopySystemFile(const String& existingFileName, const String& newFileName, bool failIfExists) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CopySystemFile(const String& existingFileName, const String& newFileName) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemFilePointer(WindowHandle file, WindowLong distanceToMove, WindowLargeIntegerPtr newFilePointer, FilePointer moveMethod) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemFilePointer(WindowHandle file, WindowLargeInteger distanceToMove, WindowLargeIntegerPtr newFilePointer, FilePointer moveMethod) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetEndOfSystemFile(WindowHandle file) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE FlushSystemFileBuffers(WindowHandle file) noexcept;
}

#endif  // SYSTEM_FILE_MANAGE_FILE_H