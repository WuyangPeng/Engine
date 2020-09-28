//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 10:51)

#ifndef SYSTEM_WINDOW_WINDOW_REGISTRY_FLAGS_H
#define SYSTEM_WINDOW_WINDOW_REGISTRY_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class RegistrySpecificAccess
    {
        QueryValue = KEY_QUERY_VALUE,
        SetValue = KEY_SET_VALUE,
        CreateSubKey = KEY_CREATE_SUB_KEY,
        EnumerateSubKeys = KEY_ENUMERATE_SUB_KEYS,
        Notify = KEY_NOTIFY,
        CreateLink = KEY_CREATE_LINK,
        Wow64_32key = KEY_WOW64_32KEY,
        Wow64_64key = KEY_WOW64_64KEY,
        Wow64Res = KEY_WOW64_RES,

        Read = KEY_READ,
        Write = KEY_WRITE,
        Execute = KEY_EXECUTE,
        AllAccess = KEY_ALL_ACCESS,
    };

    enum class RegistryOpenCreateOptions
    {
        Reserved = REG_OPTION_RESERVED,
        NonVolatile = REG_OPTION_NON_VOLATILE,
        Volatile = REG_OPTION_VOLATILE,
        CreateLink = REG_OPTION_CREATE_LINK,
        BackupRestore = REG_OPTION_BACKUP_RESTORE,
        OpenLink = REG_OPTION_OPEN_LINK,
        RegLegalOption = REG_LEGAL_OPTION,

        RegOpenLegalOption = REG_OPEN_LEGAL_OPTION,
    };

    enum class RegistryPredefinedValue
    {
        None = REG_NONE,
        Sz = REG_SZ,
        ExpandSz = REG_EXPAND_SZ,
        Binary = REG_BINARY,
        Dword = REG_DWORD,
        DwordLittleEndian = REG_DWORD_LITTLE_ENDIAN,
        DwordBigEndian = REG_DWORD_BIG_ENDIAN,
        Link = REG_LINK,
        MultiSz = REG_MULTI_SZ,
        ResourceList = REG_RESOURCE_LIST,
        FullResourceDescriptor = REG_FULL_RESOURCE_DESCRIPTOR,
        ResourceRequirementsList = REG_RESOURCE_REQUIREMENTS_LIST,
        QWord = REG_QWORD,
        QWordLittleEndian = REG_QWORD_LITTLE_ENDIAN,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class RegistrySpecificAccess
    {
        QueryValue = (0x0001),
        SetValue = (0x0002),
        CreateSubKey = (0x0004),
        EnumerateSubKeys = (0x0008),
        Notify = (0x0010),
        CreateLink = (0x0020),
        Wow64_32key = (0x0200),
        Wow64_64key = (0x0100),
        Wow64Res = (0x0300),

        Read = ((0x00020000L | QueryValue | EnumerateSubKeys | Notify) & (~0x00100000L)),

        Write = ((0x00020000L | QueryValue | CreateSubKey) & (~0x00100000L)),

        Execute = ((Read) & (~0x00100000L)),

        AllAccess = ((0x00020000L | QueryValue | SetValue | CreateSubKey | EnumerateSubKeys | Notify | CreateLink) & (~0x00100000L)),
    };

    enum class RegistryOpenCreateOptions
    {
        Reserved = (0x00000000L),
        NonVolatile = (0x00000000L),
        Volatile = (0x00000001L),
        CreateLink = (0x00000002L),
        BackupRestore = (0x00000004L),
        OpenLink = (0x00000008L),
        RegLegalOption = (Reserved | NonVolatile | Volatile | CreateLink | BackupRestore | OpenLink),

        RegOpenLegalOption = (Reserved | BackupRestore | OpenLink),
    };

    enum class RegistryPredefinedValue
    {
        None = (0),
        Sz = (1),
        ExpandSz = (2),
        Binary = (3),
        Dword = (4),
        DwordLittleEndian = (4),
        DwordBigEndian = (5),
        Link = (6),
        Multi_sz = (7),
        Resource_List = (8),
        FullResourceDescriptor = (9),
        ResourceRequirementsList = (10),
        QWord = (11),
        QWordLittleEndian = (11),
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_WINDOW_WINDOW_REGISTRY_FLAGS_H
