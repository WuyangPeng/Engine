///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/12 12:44)

#ifndef SYSTEM_WINDOWS_WINDOWS_FWD_H
#define SYSTEM_WINDOWS_WINDOWS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    // Exception
    enum class Exception;

    // PlatformError
    enum class Severity;
    enum class ErrorMode;
    enum class Facility;
    enum class WindowError;

    // WindowsClassStyle
    enum class WindowsClassStyle;

    // WindowssCreate
    enum class SystemMenuCommand;
    enum class MenuItem;

    // WindowsDisplay
    enum class WindowsDisplay;

    // Windows
    enum class WindowsPointUse;
    enum class WindowsStyles : uint32_t;

    // WindowsMessages
    enum class WindowsMessages;

    // WindowsNamedPipe
    enum class WindowsOpenMode;

    // WindowsPictorial
    enum class WindowsBrushTypes : uint32_t;

    // WindowsProcess
    enum class PeekMessageOptions;

    // WindowsKeyCodes
    enum class WindowsKeyCodes;
    enum class WindowsModifiersCodes;

    // WindowSystem
    enum class Toolhelp32;
    enum class DirectoryEntries;
    enum class ComboBoxNotification;

    // IUnknown
    enum class ClsContext;
    enum class RegCls;
}

#endif  // SYSTEM_WINDOWS_WINDOWS_FWD_H