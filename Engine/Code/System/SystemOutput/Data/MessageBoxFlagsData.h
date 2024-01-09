/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 16:24)

#ifndef SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_FLAGS_DATA_H
#define SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_FLAGS_DATA_H

#include "System/SystemDll.h"

#include "System/Helper/EnumCast.h"
#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    class SYSTEM_DEFAULT_DECLARE MessageBoxFlagsData final
    {
    public:
        using ClassType = MessageBoxFlagsData;

    public:
        constexpr MessageBoxFlagsData(const MessageBoxType messageBoxType, const MessageBoxIcon messageBoxIcon, const MessageBoxDefault messageBoxDefault, const MessageBoxMode messageBoxMode, const MessageBoxMisc messageBoxMisc) noexcept
            : messageBoxType{ messageBoxType }, messageBoxIcon{ messageBoxIcon }, messageBoxDefault{ messageBoxDefault }, messageBoxMode{ messageBoxMode }, messageBoxMisc{ messageBoxMisc }
        {
        }

        NODISCARD constexpr auto GetMessageBoxType() const noexcept
        {
            return messageBoxType;
        }

        NODISCARD constexpr auto GetMessageBoxIcon() const noexcept
        {
            return messageBoxIcon;
        }

        NODISCARD constexpr auto GetMessageBoxDefault() const noexcept
        {
            return messageBoxDefault;
        }

        NODISCARD constexpr auto GetMessageBoxMode() const noexcept
        {
            return messageBoxMode;
        }

        NODISCARD constexpr auto GetMessageBoxMisc() const noexcept
        {
            return messageBoxMisc;
        }

        NODISCARD constexpr WindowsUInt GetFlag() const noexcept
        {
            return EnumCastUnderlying(messageBoxType) |
                   EnumCastUnderlying(messageBoxIcon) |
                   EnumCastUnderlying(messageBoxDefault) |
                   EnumCastUnderlying(messageBoxMode) |
                   EnumCastUnderlying(messageBoxMisc);
        }

    private:
        MessageBoxType messageBoxType;
        MessageBoxIcon messageBoxIcon;
        MessageBoxDefault messageBoxDefault;
        MessageBoxMode messageBoxMode;
        MessageBoxMisc messageBoxMisc;
    };
}

#endif  // SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_FLAGS_DATA_H