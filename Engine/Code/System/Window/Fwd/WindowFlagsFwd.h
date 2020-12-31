//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 10:51)

#ifndef SYSTEM_WINDOW_WINDOW_FWD_H
#define SYSTEM_WINDOW_WINDOW_FWD_H

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

    // WindowClassStyle
    enum class WindowClassStyle;

    // WindowCreate
    enum class SystemMenuCommand;
    enum class MenuItem;

    // WindowDisplay
    enum class WindowDisplay;

    // Window
    enum class WindowPointUse;
    enum class WindowStyles : uint32_t;

    // WindowMessages
    enum class WindowMessages;

    // WindowNamedPipe
    enum class WindowOpenMode;

    // WindowPictorial
    enum class WindowBrushTypes : uint32_t;

    // WindowProcess
    enum class PeekMessageOptions;

    // WindowRegistry
    enum class RegistrySpecificAccess;
    enum class RegistryOpenCreateOptions;
    enum class RegistryPredefinedValue;

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

#endif  // SYSTEM_WINDOW_WINDOW_FWD_H