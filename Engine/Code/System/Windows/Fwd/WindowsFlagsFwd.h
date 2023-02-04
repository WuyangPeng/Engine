///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.1 (2023/02/02 14:38)

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