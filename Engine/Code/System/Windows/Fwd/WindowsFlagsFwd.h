/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 16:09)

#ifndef SYSTEM_WINDOWS_WINDOWS_FWD_H
#define SYSTEM_WINDOWS_WINDOWS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    /// Exception
    enum class Exception;

    /// PlatformError
    enum class Severity;
    enum class ErrorMode;
    enum class Facility;
    enum class WindowError;

    /// WindowsClassStyle
    enum class WindowsClassStyle;

    /// WindowsCreate
    enum class SystemMenuCommand;
    enum class MenuItem;

    /// WindowsDisplay
    enum class WindowsDisplay;

    /// Windows
    enum class WindowsPointUse;
    enum class WindowsStyles : uint32_t;

    /// WindowsMessages
    enum class WindowsMessages;

    /// WindowsPictorial
    enum class WindowsBrushTypes : uint32_t;

    /// WindowsProcess
    enum class PeekMessageOptions : int8_t;

    /// WindowsKeyCodes
    enum class WindowsKeyCodes;
    enum class WindowsModifiersCodes : int8_t;
}

#endif  // SYSTEM_WINDOWS_WINDOWS_FWD_H