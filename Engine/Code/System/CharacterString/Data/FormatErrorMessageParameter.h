///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/26 0:57)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_PARAMETER_H
#define SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_PARAMETER_H

#include "System/SystemDll.h"

#include "System/CharacterString/Flags/FormatMessageFlags.h"
#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"
#include "System/SystemOutput/Data/LanguageIDData.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"

namespace System
{
    class FormatErrorMessageParameter final
    {
    public:
        using ClassType = FormatErrorMessageParameter;

    public:
        explicit constexpr FormatErrorMessageParameter(FormatMessageOption formatMessageOption)
            : formatMessageOption{ formatMessageOption }
        {
        }

        NODISCARD constexpr LanguageIDData GetLanguageIDData() const noexcept
        {
            return LanguageIDData{};
        }

        NODISCARD constexpr FormatMessageOption GetOption() const noexcept
        {
            return formatMessageOption;
        }

        NODISCARD constexpr FormatMessageWidth GetWidth() const noexcept
        {
            return FormatMessageWidth::NoRestrictions;
        }

        NODISCARD constexpr WindowError GetWindowError() const noexcept
        {
            return WindowError::Success;
        }

    private:
        FormatMessageOption formatMessageOption;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_PARAMETER_H