///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/12 23:44)

#include "System/SystemExport.h"

#include "FormatErrorMessage.h"
#include "Flags/FormatMessageFlags.h"
#include "System/Helper/PragmaWarning.h"
#include "System/SystemOutput/Data/LanguageIDData.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"

namespace System
{
    TChar* ReinterpretCast(WindowsHLocal& errorMessage) noexcept
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        return reinterpret_cast<TChar*>(&errorMessage);

#include STSTEM_WARNING_POP
    }

    va_list* ReinterpretCast(WindowsPtrDWord* arguments) noexcept
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        return reinterpret_cast<va_list*>(arguments);

#include STSTEM_WARNING_POP
    }
}

System::WindowsDWord System::FormatErrorMessage(FormatMessageOption flag,
                                                FormatMessageWidth widthFlag,
                                                WindowsConstVoidPtr source,
                                                WindowError messageID,
                                                const LanguageIDData& languageID,
                                                TChar* buffer,
                                                WindowsDWord size,
                                                va_list* arguments) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::FormatMessage(EnumCastUnderlying(flag) | EnumCastUnderlying(widthFlag), source, EnumCastUnderlying(messageID), languageID.GetLanguageID(), buffer, size, arguments);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(flag, widthFlag, source, messageID, languageID, buffer, size, arguments);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FormatErrorMessage(WindowsHLocal& errorMessage, WindowError lastError) noexcept
{
    constexpr LanguageIDData languageID{};
    constexpr auto messageOption = FormatMessageOption::FromSystem | FormatMessageOption::IgnoreInserts | FormatMessageOption::AllocateBuffer;
    constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;

    const auto size = FormatErrorMessage(messageOption, messageWidth, nullptr, lastError, languageID, ReinterpretCast(errorMessage), 0, nullptr);

    return size != 0;
}

System::WindowsDWord System::FormatErrorMessage(WindowError lastError, TChar* buffer, WindowsDWord size) noexcept
{
    constexpr LanguageIDData languageID{};
    constexpr auto messageOption = FormatMessageOption::FromSystem | FormatMessageOption::IgnoreInserts;
    constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;

    return FormatErrorMessage(messageOption, messageWidth, nullptr, lastError, languageID, buffer, size, nullptr);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)

bool System::FormatErrorMessage(WindowsHLocal& errorMessage, DynamicLinkModule module, WindowError lastError) noexcept
{
    constexpr LanguageIDData languageID{};
    constexpr auto messageOption = FormatMessageOption::FromHModule | FormatMessageOption::IgnoreInserts | FormatMessageOption::AllocateBuffer;
    constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;

    const auto size = FormatErrorMessage(messageOption, messageWidth, module, lastError, languageID, ReinterpretCast(errorMessage), 0, nullptr);

    return size != 0;
}

System::WindowsDWord System::FormatErrorMessage(DynamicLinkModule module, WindowError lastError, TChar* buffer, WindowsDWord size) noexcept
{
    constexpr LanguageIDData languageID{};
    constexpr auto messageOption = FormatMessageOption::FromHModule | FormatMessageOption::IgnoreInserts;
    constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;

    return FormatErrorMessage(messageOption, messageWidth, module, lastError, languageID, buffer, size, nullptr);
}

#include STSTEM_WARNING_POP

System::WindowsDWord System::FormatStringMessage(const TChar* message, TChar* buffer, WindowsDWord size, WindowsPtrDWord* arguments) noexcept
{
    constexpr LanguageIDData languageID{};
    constexpr auto messageOption = FormatMessageOption::FromString | FormatMessageOption::ArgumentArray;
    constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;
    constexpr auto windowError = WindowError::Success;

    return FormatErrorMessage(messageOption, messageWidth, message, windowError, languageID, buffer, size, ReinterpretCast(arguments));
}

System::WindowsDWord System::FormatStringMessage(const TChar* message, TChar* buffer, WindowsDWord size, va_list* arguments) noexcept
{
    constexpr LanguageIDData languageID{};
    constexpr auto messageOption = FormatMessageOption::FromString;
    constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;
    constexpr auto windowError = WindowError::Success;

    return FormatErrorMessage(messageOption, messageWidth, message, windowError, languageID, buffer, size, arguments);
}

System::WindowsDWord System::FormatStringMessage(const TChar* message, WindowsHLocal& resultMessage, WindowsPtrDWord* arguments) noexcept
{
    constexpr LanguageIDData languageID{};
    constexpr auto messageOption = FormatMessageOption::FromString | FormatMessageOption::ArgumentArray | FormatMessageOption::AllocateBuffer;
    constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;
    constexpr auto windowError = WindowError::Success;

    return FormatErrorMessage(messageOption, messageWidth, message, windowError, languageID, ReinterpretCast(resultMessage), 0, ReinterpretCast(arguments));
}

System::WindowsDWord System::FormatStringMessage(const TChar* message, WindowsHLocal& resultMessage, va_list* arguments) noexcept
{
    constexpr LanguageIDData languageID{};
    constexpr auto messageOption = FormatMessageOption::FromString | FormatMessageOption::AllocateBuffer;
    constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;
    constexpr auto windowError = WindowError::Success;

    return FormatErrorMessage(messageOption, messageWidth, message, windowError, languageID, ReinterpretCast(resultMessage), 0, arguments);
}
