//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 9:26)

#ifndef SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_FLAGS_DATA_H
#define SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_FLAGS_DATA_H

#include "System/SystemDll.h"

#include "System/Helper/EnumCast.h"
#include "System/SystemOutput/Fwd/SystemOutputFlagsFwd.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    class SYSTEM_DEFAULT_DECLARE MessageBoxFlagsData final
    {
    public:
        using ClassType = MessageBoxFlagsData;

    public:
        constexpr MessageBoxFlagsData(MessageBoxType messageBoxType, MessageBoxIcon messageBoxIcon, MessageBoxDefault messageBoxDefault, MessageBoxMode messageBoxMode, MessageBoxMisc messageBoxMisc) noexcept
            : m_Type{ messageBoxType }, m_Icon{ messageBoxIcon }, m_Default{ messageBoxDefault }, m_Mode{ messageBoxMode }, m_Misc{ messageBoxMisc }
        {
        }

        [[nodiscard]] constexpr auto GetMessageBoxType() const noexcept
        {
            return m_Type;
        }

        [[nodiscard]] constexpr auto GetMessageBoxIcon() const noexcept
        {
            return m_Icon;
        }

        [[nodiscard]] constexpr auto GetMessageBoxDefault() const noexcept
        {
            return m_Default;
        }

        [[nodiscard]] constexpr auto GetMessageBoxMode() const noexcept
        {
            return m_Mode;
        }

        [[nodiscard]] constexpr auto GetMessageBoxMisc() const noexcept
        {
            return m_Misc;
        }

        [[nodiscard]] constexpr WindowUInt GetFlag() const noexcept
        {
            return EnumCastUnderlying(m_Type) | EnumCastUnderlying(m_Icon) | EnumCastUnderlying(m_Default) |
                   EnumCastUnderlying(m_Mode) | EnumCastUnderlying(m_Misc);
        }

    private:
        MessageBoxType m_Type;
        MessageBoxIcon m_Icon;
        MessageBoxDefault m_Default;
        MessageBoxMode m_Mode;
        MessageBoxMisc m_Misc;
    };
}

#endif  // SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_FLAGS_DATA_H