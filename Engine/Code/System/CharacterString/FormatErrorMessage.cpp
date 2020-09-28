//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 13:19)

#include "System/SystemExport.h"

#include "FormatErrorMessage.h"
#include "Flags/FormatMessageFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "System/SystemOutput/Data/LanguageIDData.h"
#include "System/Window/Flags/PlatformErrorFlags.h"

namespace System
{
    TChar* ReinterpretCast(WindowHLocal& errorMessage) noexcept
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
        return reinterpret_cast<TChar*>(&errorMessage);
#include STSTEM_WARNING_POP
    }

    va_list* ReinterpretCast(WindowPtrDWord* arguments) noexcept
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
        return reinterpret_cast<va_list*>(arguments);
#include STSTEM_WARNING_POP
    }
}

System::WindowDWord System::FormatErrorMessage([[maybe_unused]] FormatMessageOption flag, [[maybe_unused]] FormatMessageWidth widthFlag, [[maybe_unused]] WindowConstVoidPtr source, [[maybe_unused]] WindowError messageID,
                                               [[maybe_unused]] const LanguageIDData& languageID, [[maybe_unused]] TChar* buffer, [[maybe_unused]] WindowDWord size, [[maybe_unused]] va_list* arguments) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::FormatMessage(EnumCastUnderlying(flag) | EnumCastUnderlying(widthFlag), source, EnumCastUnderlying(messageID), languageID.GetLanguageID(), buffer, size, arguments);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FormatErrorMessage(WindowHLocal& errorMessage, WindowError lastError) noexcept
{
    constexpr LanguageIDData languageID{};
    constexpr auto messageOption = FormatMessageOption::FromSystem | FormatMessageOption::IgnoreInserts | FormatMessageOption::AllocateBuffer;
    constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;

    const auto size = FormatErrorMessage(messageOption, messageWidth, nullptr, lastError, languageID, ReinterpretCast(errorMessage), 0, nullptr);

    return size != 0;
}

System::WindowDWord System::FormatErrorMessage(WindowError lastError, TChar* buffer, WindowDWord size) noexcept
{
    constexpr LanguageIDData languageID{};
    constexpr auto messageOption = FormatMessageOption::FromSystem | FormatMessageOption::IgnoreInserts;
    constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;

    return FormatErrorMessage(messageOption, messageWidth, nullptr, lastError, languageID, buffer, size, nullptr);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)
bool System::FormatErrorMessage(WindowHLocal& errorMessage, DynamicLinkModule module, WindowError lastError) noexcept
{
    constexpr LanguageIDData languageID{};
    constexpr auto messageOption = FormatMessageOption::FromHModule | FormatMessageOption::IgnoreInserts | FormatMessageOption::AllocateBuffer;
    constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;

    const auto size = FormatErrorMessage(messageOption, messageWidth, module, lastError, languageID, ReinterpretCast(errorMessage), 0, nullptr);

    return size != 0;
}

System::WindowDWord System::FormatErrorMessage(const DynamicLinkModule module, WindowError lastError, TChar* buffer, WindowDWord size) noexcept
{
    constexpr LanguageIDData languageID{};
    constexpr auto messageOption = FormatMessageOption::FromHModule | FormatMessageOption::IgnoreInserts;
    constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;

    return FormatErrorMessage(messageOption, messageWidth, module, lastError, languageID, buffer, size, nullptr);
}
#include STSTEM_WARNING_POP

System::WindowDWord System::FormatStringMessage(const TChar* message, TChar* buffer, WindowDWord size, WindowPtrDWord* arguments) noexcept
{
    constexpr LanguageIDData languageID{};
    constexpr auto messageOption = FormatMessageOption::FromString | FormatMessageOption::ArgumentArray;
    constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;
    constexpr auto windowError = WindowError::Success;

    return FormatErrorMessage(messageOption, messageWidth, message, windowError, languageID, buffer, size, ReinterpretCast(arguments));
}

System::WindowDWord System::FormatStringMessage(const TChar* message, TChar* buffer, WindowDWord size, va_list* arguments) noexcept
{
    constexpr LanguageIDData languageID{};
    constexpr auto messageOption = FormatMessageOption::FromString;
    constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;
    constexpr auto windowError = WindowError::Success;

    return FormatErrorMessage(messageOption, messageWidth, message, windowError, languageID, buffer, size, arguments);
}

System::WindowDWord System::FormatStringMessage(const TChar* message, WindowHLocal& resultMessage, WindowPtrDWord* arguments) noexcept
{
    constexpr LanguageIDData languageID{};
    constexpr auto messageOption = FormatMessageOption::FromString | FormatMessageOption::ArgumentArray | FormatMessageOption::AllocateBuffer;
    constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;
    constexpr auto windowError = WindowError::Success;

    return FormatErrorMessage(messageOption, messageWidth, message, windowError, languageID, ReinterpretCast(resultMessage), 0, ReinterpretCast(arguments));
}

System::WindowDWord System::FormatStringMessage(const TChar* message, WindowHLocal& resultMessage, va_list* arguments) noexcept
{
    constexpr LanguageIDData languageID{};
    constexpr auto messageOption = FormatMessageOption::FromString | FormatMessageOption::AllocateBuffer;
    constexpr auto messageWidth = FormatMessageWidth::NoRestrictions;
    constexpr auto windowError = WindowError::Success;

    return FormatErrorMessage(messageOption, messageWidth, message, windowError, languageID, ReinterpretCast(resultMessage), 0, arguments);
}
