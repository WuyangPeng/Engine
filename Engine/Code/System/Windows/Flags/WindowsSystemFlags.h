///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/22 17:30)

#ifndef SYSTEM_WINDOWS_WINDOWS_SYSTEM_FLAGS_H
#define SYSTEM_WINDOWS_WINDOWS_SYSTEM_FLAGS_H

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32

    #include <TlHelp32.h>

#endif  // SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class ToolHelp32
    {
        SnapHeapList = TH32CS_SNAPHEAPLIST,
        SnapProcess = TH32CS_SNAPPROCESS,
        SnapThread = TH32CS_SNAPTHREAD,
        SnapModule = TH32CS_SNAPMODULE,
        SnapModule32 = TH32CS_SNAPMODULE32,
        SnapAll = TH32CS_SNAPALL,
        Inherit = TH32CS_INHERIT,
    };

    enum class DirectoryEntries
    {
        Export = IMAGE_DIRECTORY_ENTRY_EXPORT,
        Import = IMAGE_DIRECTORY_ENTRY_IMPORT,
        Resource = IMAGE_DIRECTORY_ENTRY_RESOURCE,
        Exception = IMAGE_DIRECTORY_ENTRY_EXCEPTION,
        Security = IMAGE_DIRECTORY_ENTRY_SECURITY,
        BaseRelocation = IMAGE_DIRECTORY_ENTRY_BASERELOC,
        Debug = IMAGE_DIRECTORY_ENTRY_DEBUG,
        Architecture = IMAGE_DIRECTORY_ENTRY_ARCHITECTURE,
        GlobalPtr = IMAGE_DIRECTORY_ENTRY_GLOBALPTR,
        Tls = IMAGE_DIRECTORY_ENTRY_TLS,
        LoadConfig = IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG,
        BoundImport = IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT,
        Iat = IMAGE_DIRECTORY_ENTRY_IAT,
        DelayImport = IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT,
        ComDescriptor = IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR,
    };

    enum class ComboBoxNotification
    {
        ErrorSpace = CBN_ERRSPACE,
        SelectionChange = CBN_SELCHANGE,
        DoubleClick = CBN_DBLCLK,
        SetFocus = CBN_SETFOCUS,
        KillFocus = CBN_KILLFOCUS,
        EditChange = CBN_EDITCHANGE,
        EditUpdate = CBN_EDITUPDATE,
        Dropdown = CBN_DROPDOWN,
        Closeup = CBN_CLOSEUP,
        SelectEndOk = CBN_SELENDOK,
        SelectEndCancel = CBN_SELENDCANCEL,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class Toolhelp32
    {
        SnapHeapList = 0x00000001,
        SnapProcess = 0x00000002,
        SnapThread = 0x00000004,
        SnapModule = 0x00000008,
        SnapModule32 = 0x00000010,
        SnapAll = SnapHeapList | SnapProcess | SnapThread | SnapModule,
        Inherit = 0x80000000,
    };

    enum class DirectoryEntries
    {
        Export = 0,
        Import = 1,
        Resource = 2,
        Exception = 3,
        Security = 4,
        BaseRelocation = 5,
        Debug = 6,
        Architecture = 7,
        GlobalPtr = 8,
        Tls = 9,
        LoadConfig = 10,
        BoundImport = 11,
        Iat = 12,
        DelayImport = 13,
        ComDescriptor = 14,
    };

    enum class ComboBoxNotification
    {
        ErrorSpace = -1,
        SelectionChange = 1,
        DoubleClick = 2,
        SetFocus = 3,
        KillFocus = 4,
        EditChange = 5,
        EditUpdate = 6,
        Dropdown = 7,
        Closeup = 8,
        SelectEndOk = 9,
        SelectEndCancel = 10,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_WINDOWS_WINDOWS_SYSTEM_FLAGS_H
