///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/28 17:14)

#ifndef SYSTEM_FILE_MANAGER_FILE_H
#define SYSTEM_FILE_MANAGER_FILE_H

#include "System/SystemDll.h"

#include "Fwd/FileFlagsFwd.h"
#include "Using/CFileUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

// �ļ��Ĵ򿪡��رա���������д��ɾ����
namespace System
{
    NODISCARD WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemFile(const String& fileName,
                                                                    FileHandleDesiredAccess access,
                                                                    FileHandleShareMode shareMode,
                                                                    WindowSecurityAttributesPtr securityAttributes,
                                                                    FileHandleCreationDisposition creation,
                                                                    FileHandleAttributes attributes,
                                                                    FileHandleOther other,
                                                                    FileHandleSecurity security,
                                                                    WindowsHandle templateFile) noexcept;

    NODISCARD WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemFile(const String& fileName,
                                                                    FileHandleDesiredAccess access,
                                                                    FileHandleShareMode shareMode,
                                                                    FileHandleCreationDisposition creation) noexcept;

    NODISCARD WindowsHandle SYSTEM_DEFAULT_DECLARE CreateSystemFile(const String& fileName,
                                                                    FileHandleDesiredAccess access,
                                                                    FileHandleShareMode shareMode,
                                                                    FileHandleCreationDisposition creation,
                                                                    FileHandleAttributes attributes,
                                                                    FileHandleOther other,
                                                                    FileHandleSecurity security) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE RemoveSystemFile(const CFileString& fileName) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE MoveSystemFile(const String& existingFileName, const String& newFileName) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseSystemFile(WindowsHandle file) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsFileHandleValid(WindowsHandle file) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetFileLength(WindowsHandle file, uint64_t& fileSize) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetFileLength(WindowsHandle file, WindowsLargeIntegerPtr fileSize) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CopySystemFile(const String& existingFileName, const String& newFileName, bool failIfExists) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CopySystemFile(const String& existingFileName, const String& newFileName) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemFilePointer(WindowsHandle file,
                                                               WindowsLong distanceToMove,
                                                               WindowsLargeIntegerPtr newFilePointer,
                                                               FilePointer moveMethod) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemFilePointer(WindowsHandle file,
                                                               WindowsLargeInteger distanceToMove,
                                                               WindowsLargeIntegerPtr newFilePointer,
                                                               FilePointer moveMethod) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetEndOfSystemFile(WindowsHandle file) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FlushSystemFileBuffers(WindowsHandle file) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE ReadSystemFile(WindowsHandle file,
                                                         WindowsVoidPtr buffer,
                                                         WindowsDWord numberOfBytesToRead,
                                                         WindowsDWordPtr numberOfBytesRead,
                                                         WindowOverlappedPtr overlapped) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE ReadSystemFile(WindowsHandle file,
                                                         WindowsVoidPtr buffer,
                                                         WindowsDWord numberOfBytesToRead,
                                                         WindowsDWordPtr numberOfBytesRead) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE ReadSystemFile(WindowsHandle file,
                                                         WindowsVoidPtr buffer,
                                                         WindowsDWord numberOfBytesToRead,
                                                         WindowOverlappedPtr overlapped,
                                                         WindowOverlappedCompletionRoutine completionRoutine) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE WriteSystemFile(WindowsHandle file,
                                                          WindowsConstVoidPtr buffer,
                                                          WindowsDWord numberOfBytesToWrite,
                                                          WindowsDWordPtr numberOfBytesWritten,
                                                          WindowOverlappedPtr overlapped) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE WriteSystemFile(WindowsHandle file,
                                                          WindowsConstVoidPtr buffer,
                                                          WindowsDWord numberOfBytesToWrite,
                                                          WindowsDWordPtr numberOfBytesWritten) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE WriteSystemFile(WindowsHandle file,
                                                          WindowsConstVoidPtr buffer,
                                                          WindowsDWord numberOfBytesToWrite,
                                                          WindowOverlappedPtr overlapped,
                                                          WindowOverlappedCompletionRoutine completionRoutine) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE AppendSystemFile(WindowsHandle file,
                                                           WindowsConstVoidPtr buffer,
                                                           WindowsDWord numberOfBytesToWrite,
                                                           WindowsDWordPtr numberOfBytesWritten) noexcept;
}

#endif  // SYSTEM_FILE_MANAGER_FILE_H