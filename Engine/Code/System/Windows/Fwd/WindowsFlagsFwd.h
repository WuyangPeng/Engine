/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/23 23:38)

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

    // WindowsCreate
    enum class SystemMenuCommand;
    enum class MenuItem;

    // WindowsDisplay
    enum class WindowsDisplay;

    // Windows
    enum class WindowsPointUse;
    enum class WindowsStyles : uint32_t;

    // WindowsMessages
    enum class WindowsMessages;

    // WindowsPictorial
    enum class WindowsBrushTypes : uint32_t;

    // WindowsProcess
    enum class PeekMessageOptions;

    // WindowsKeyCodes
    enum class WindowsKeyCodes;
    enum class WindowsModifiersCodes;
}

#endif  // SYSTEM_WINDOWS_WINDOWS_FWD_H