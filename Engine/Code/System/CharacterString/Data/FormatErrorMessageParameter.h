/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:03)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_PARAMETER_H
#define SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_PARAMETER_H

#include "System/SystemDll.h"

#include "System/CharacterString/Flags/FormatMessageFlags.h"
#include "System/SystemOutput/Data/LanguageIdData.h"
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

        NODISCARD constexpr static LanguageIdData GetLanguageIdData() noexcept
        {
            return LanguageIdData{};
        }

        NODISCARD constexpr FormatMessageOption GetOption() const noexcept
        {
            return formatMessageOption;
        }

        NODISCARD constexpr static FormatMessageWidth GetWidth() noexcept
        {
            return FormatMessageWidth::NoRestrictions;
        }

        NODISCARD constexpr static WindowError GetWindowError() noexcept
        {
            return WindowError::Success;
        }

    private:
        FormatMessageOption formatMessageOption;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_PARAMETER_H