///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/17 21:57)

#ifndef SYSTEM_FILE_MANAGE_FILE_TOOLS_FLAGS_H
#define SYSTEM_FILE_MANAGE_FILE_TOOLS_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class DefineDosDeviceControllable
    {
        RawTargetPath = DDD_RAW_TARGET_PATH,
        RemoveDefinition = DDD_REMOVE_DEFINITION,
        ExactMatchOnRemove = DDD_EXACT_MATCH_ON_REMOVE | RemoveDefinition,
        NoBroadcastSystem = DDD_NO_BROADCAST_SYSTEM,
        LuidBroadcastDrive = DDD_LUID_BROADCAST_DRIVE,
    };

    enum class Drive
    {
        Unknow = DRIVE_UNKNOWN,
        NoRootDir = DRIVE_NO_ROOT_DIR,
        Removealbe = DRIVE_REMOVABLE,
        Fixed = DRIVE_FIXED,
        Remote = DRIVE_REMOTE,
        Cdrom = DRIVE_CDROM,
        Ramdisk = DRIVE_RAMDISK,
    };

    enum class FileType
    {
        Unknown = FILE_TYPE_UNKNOWN,
        Disk = FILE_TYPE_DISK,
        Char = FILE_TYPE_CHAR,
        Pipe = FILE_TYPE_PIPE,
        Remote = FILE_TYPE_REMOTE,
    };

    enum class GetFinalPathName
    {
        VolumeNameDos = VOLUME_NAME_DOS,  // 默认
        VolumeNameGuid = VOLUME_NAME_GUID,
        VolumeNameNt = VOLUME_NAME_NT,
        VolumeNameNone = VOLUME_NAME_NONE,

        FileNameNormalized = FILE_NAME_NORMALIZED,  // 默认
        FileNameOpened = FILE_NAME_OPENED,
    };

    enum class LockFile
    {
        FailImmediately = LOCKFILE_FAIL_IMMEDIATELY,
        ExclusiveLock = LOCKFILE_EXCLUSIVE_LOCK,
    };

    enum class FileSystem
    {
        CaseSensitiveSearch = FILE_CASE_SENSITIVE_SEARCH,
        CasePreservedNames = FILE_CASE_PRESERVED_NAMES,
        UnicodeOnDisk = FILE_UNICODE_ON_DISK,
        PersistentAcls = FILE_PERSISTENT_ACLS,
        FileCompression = FILE_FILE_COMPRESSION,
        VolumeQuotas = FILE_VOLUME_QUOTAS,
        SupportsSparseFiles = FILE_SUPPORTS_SPARSE_FILES,
        SupportsReparsePoints = FILE_SUPPORTS_REPARSE_POINTS,
        SupportsRemoteStorage = FILE_SUPPORTS_REMOTE_STORAGE,
        VolumeIsCompressed = FILE_VOLUME_IS_COMPRESSED,
        SupportsObjectIds = FILE_SUPPORTS_OBJECT_IDS,
        SupportsEncryption = FILE_SUPPORTS_ENCRYPTION,
        NamedStreams = FILE_NAMED_STREAMS,
        ReadOnlyVolume = FILE_READ_ONLY_VOLUME,
        SequentialWriteOnce = FILE_SEQUENTIAL_WRITE_ONCE,
        SupportsTransactions = FILE_SUPPORTS_TRANSACTIONS,
        FileSupportsHardLinks = FILE_SUPPORTS_HARD_LINKS,
        SupportsExtendedAttributes = FILE_SUPPORTS_EXTENDED_ATTRIBUTES,
        SupportsOpenByFileID = FILE_SUPPORTS_OPEN_BY_FILE_ID,
        SupportsUsnJournal = FILE_SUPPORTS_USN_JOURNAL,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class DefineDosDeviceControllable
    {
        RawTargetPath = 0x00000001,
        RemoveDefinition = 0x00000002,
        ExactMatchOnRemove = 0x00000004 | RemoveDefinition,
        NoBroadcastSystem = 0x00000008,
        LuidBroadcastDrive = 0x00000010,
    };

    enum class Drive
    {
        Unknow = 0,
        NoRootDir = 1,
        Removealbe = 2,
        Fixed = 3,
        Remote = 4,
        Cdrom = 5,
        Ramdisk = 6,
    };

    enum class FileType
    {
        Unknown = 0x0000,
        Disk = 0x0001,
        Char = 0x0002,
        Pipe = 0x0003,
        Remote = 0x8000,
    };

    enum class GetFinalPathName
    {
        VolumeNameDos = 0x0,
        VolumeNameGuid = 0x1,
        VolumeNameNt = 0x2,
        VolumeNameNone = 0x4,

        FileNameNormalized = 0x0,
        FileNameOpened = 0x8,
    };

    enum class LockFile
    {
        FailImmediately = 0x00000001,
        ExclusiveLock = 0x00000002,
    };

    enum class FileSystem
    {
        CaseSensitiveSearch = 0x00000001,
        CasePreservedNames = 0x00000002,
        UnicodeOnDisk = 0x00000004,
        PersistentAcls = 0x00000008,
        FileCompression = 0x00000010,
        VolumeQuotas = 0x00000020,
        SupportsSparseFiles = 0x00000040,
        SupportsReparsePoints = 0x00000080,
        SupportsRemoteStorage = 0x00000100,
        VolumeIsCompressed = 0x00008000,
        SupportsObjectIds = 0x00010000,
        SupportsEncryption = 0x00020000,
        NamedStreams = 0x00040000,
        ReadOnlyVolume = 0x00080000,
        SequentialWriteOnce = 0x00100000,
        SupportsTransactions = 0x00200000,
        FileSupportsHardLinks = 0x00400000,
        SupportsExtendedAttributes = 0x00800000,
        SupportsOpenByFileID = 0x01000000,
        SupportsUsnJournal = 0x02000000,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_FILE_MANAGE_FILE_TOOLS_FLAGS_H
