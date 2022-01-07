///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/12 21:05)

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
        constexpr MessageBoxFlagsData(MessageBoxType messageBoxType, MessageBoxIcon messageBoxIcon, MessageBoxDefault messageBoxDefault, MessageBoxMode messageBoxMode, MessageBoxMisc messageBoxMisc) noexcept
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