///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 16:46)

#ifndef SYSTEM_FILE_MANAGER_FILE_FLAGS_H
#define SYSTEM_FILE_MANAGER_FILE_FLAGS_H

#include "System/Helper/EnumOperator.h"
#include "System/Helper/Platform.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class FileHandleDesiredAccess : uint32_t
    {
        Read = GENERIC_READ,
        Write = GENERIC_WRITE,
        Execute = GENERIC_EXECUTE,
        ReadWrite = Read | Write,
        All = GENERIC_ALL,
        Delete = DELETE,
    };

    enum class FileHandleShareMode
    {
        Prevents = 0x00000000,
        ShareDelete = FILE_SHARE_DELETE,
        ShareRead = FILE_SHARE_READ,
        ShareWrite = FILE_SHARE_WRITE,
        ReadWrite = ShareRead | ShareWrite,
    };

    enum class FileHandleCreationDisposition
    {
        /// 创建新文件，如果指定文件已经存在则失败。
        CreateNew = CREATE_NEW,

        /// 创建新文件，如果指定文件已经存在时覆盖它。
        CreateAlways = CREATE_ALWAYS,

        /// 打开现有文件，如果文件不存在则失败。
        OpenExisting = OPEN_EXISTING,

        /// 打开现有文件，如果文件不存在则创建它。
        OpenAlways = OPEN_ALWAYS,

        /// 将文件长度置为0，
        /// DesiredAccess必须至少指定GENERIC_WRITE访问，
        /// 如果指定的文件存在的话所有内容都会被销毁，
        /// 如果文件不存在则失败。
        TruncateExisting = TRUNCATE_EXISTING,
    };

    enum class FileHandleAttributes
    {
        ReadOnly = FILE_ATTRIBUTE_READONLY,
        Hidden = FILE_ATTRIBUTE_HIDDEN,
        System = FILE_ATTRIBUTE_SYSTEM,
        Directory = FILE_ATTRIBUTE_DIRECTORY,
        Archive = FILE_ATTRIBUTE_ARCHIVE,
        Device = FILE_ATTRIBUTE_DEVICE,
        Normal = FILE_ATTRIBUTE_NORMAL,
        Temporary = FILE_ATTRIBUTE_TEMPORARY,
        SparseFile = FILE_ATTRIBUTE_SPARSE_FILE,
        ReparsePoint = FILE_ATTRIBUTE_REPARSE_POINT,
        Compressed = FILE_ATTRIBUTE_COMPRESSED,
        Offline = FILE_ATTRIBUTE_OFFLINE,
        NotContentIndexed = FILE_ATTRIBUTE_NOT_CONTENT_INDEXED,
        Encrypted = FILE_ATTRIBUTE_ENCRYPTED,
        IntegrityStream = FILE_ATTRIBUTE_INTEGRITY_STREAM,
        Virtual = FILE_ATTRIBUTE_VIRTUAL,
        NoScrubData = FILE_ATTRIBUTE_NO_SCRUB_DATA,
        Ea = FILE_ATTRIBUTE_EA,
        Pinned = FILE_ATTRIBUTE_PINNED,
        Unpinned = FILE_ATTRIBUTE_UNPINNED,
        RecallOnOpen = FILE_ATTRIBUTE_RECALL_ON_OPEN,
        RecallOnDataAccess = FILE_ATTRIBUTE_RECALL_ON_DATA_ACCESS,
    };

    enum class FileHandleOther : uint32_t
    {
        Default = 0x00000000,
        WriteThrough = FILE_FLAG_WRITE_THROUGH,
        Overlapped = FILE_FLAG_OVERLAPPED,
        NoBuffering = FILE_FLAG_NO_BUFFERING,
        RandomAccess = FILE_FLAG_RANDOM_ACCESS,
        SequentialScan = FILE_FLAG_SEQUENTIAL_SCAN,
        DeleteOnClose = FILE_FLAG_DELETE_ON_CLOSE,
        BackupSemantics = FILE_FLAG_BACKUP_SEMANTICS,
        PosixSemantics = FILE_FLAG_POSIX_SEMANTICS,
        OpenReparsePoint = FILE_FLAG_OPEN_REPARSE_POINT,
        OpenNoRecall = FILE_FLAG_OPEN_NO_RECALL,
        FirstPipeInstance = FILE_FLAG_FIRST_PIPE_INSTANCE,
    };

    enum class FileHandleSecurity
    {
        Default = 0x00000000,
        Anonymous = SECURITY_ANONYMOUS,
        Identification = SECURITY_IDENTIFICATION,
        Impersonation = SECURITY_IMPERSONATION,
        Delegation = SECURITY_DELEGATION,

        ContextTracking = SECURITY_CONTEXT_TRACKING,
        EffectiveOnly = SECURITY_EFFECTIVE_ONLY,

        SqosPresent = SECURITY_SQOS_PRESENT,
        ValidSqosFlags = SECURITY_VALID_SQOS_FLAGS,
    };

    enum class FilePointer
    {
        Begin = FILE_BEGIN,
        Current = FILE_CURRENT,
        End = FILE_END,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class FileHandleDesiredAccess : uint32_t
    {
        Read = 0x80000000L,
        Write = 0x40000000L,
        Execute = 0x20000000L,
        ReadWrite = Read | Write,
        All = 0x10000000L,
    };

    enum class FileHandleShareMode
    {
        Prevents = 0x00000000,
        ShareDelete = 0x00000004,
        ShareRead = 0x00000001,
        ShareWrite = 0x00000002,
    };

    enum class FileHandleCreationDisposition
    {
        CreateNew = 1,
        CreateAlways = 2,
        OpenExisting = 3,
        OpenAlways = 4,
        TruncateExisting = 5,
    };

    enum class FileHandleAttributes
    {
        ReadOnly = 0x00000001,
        Hidden = 0x00000002,
        System = 0x00000004,
        Directory = 0x00000010,
        Archive = 0x00000020,
        Device = 0x00000040,
        Normal = 0x00000080,
        Temporary = 0x00000100,
        SparseFile = 0x00000200,
        ReparsePoint = 0x00000400,
        Compressed = 0x00000800,
        Offline = 0x00001000,
        NotContentIndexed = 0x00002000,
        Encrypted = 0x00004000,
        IntegrityStream = 0x00008000,
        Virtual = 0x00010000,
        NoScrubData = 0x00020000,
        Ea = 0x00040000,
        Pinned = 0x00080000,
        Unpinned = 0x00100000,
        RecallOnOpen = 0x00040000,
        RecallOnDataAccess = 0x00400000,
    };

    enum class FileHandleOther : uint32_t
    {
        Default = 0x00000000,
        WriteThrough = 0x80000000,
        Overlapped = 0x40000000,
        NoBuffering = 0x20000000,
        RandomAccess = 0x10000000,
        SequentialScan = 0x08000000,
        DeleteOnClose = 0x04000000,
        BackupSemantics = 0x02000000,
        PosixSemantics = 0x01000000,
        OpenReparsePoint = 0x00200000,
        OpenNoRecall = 0x00100000,
        FirstPipeInstance = 0x00080000,
    };

    enum class FileHandleSecurity
    {
        Default = 0x00000000,
        Anonymous = (SecurityAnonymous << 16),
        Identification = (SecurityIdentification << 16),
        Impersonation = (SecurityImpersonation << 16),
        Delegation = (SecurityDelegation << 16),

        ContextTracking = 0x00040000,
        EffectiveOnly = 0x00080000,

        SqosPresent = 0x00100000,
        ValidSqosFlags = 0x001F0000,
    };

    enum class FilePointer
    {
        Begin = 0,
        Current = 1,
        End = 2,
    };

#endif  // SYSTEM_PLATFORM_WIN32

}

#endif  // SYSTEM_FILE_MANAGER_FILE_FLAGS_H
