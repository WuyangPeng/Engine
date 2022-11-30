///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/13 10:41)

#include "System/SystemExport.h"

#include "FormatErrorMessage.h"
#include "Data/FormatErrorMessageParameter.h"
#include "System/Helper/PragmaWarning.h"

#include <array>

namespace System
{
    va_list* ReinterpretCast(WindowsDWordPtrSizeType* arguments) noexcept
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        return reinterpret_cast<va_list*>(arguments);

#include STSTEM_WARNING_POP
    }
}

System::TChar* System::ReinterpretCast(WindowsHLocal& errorMessage) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<TChar*>(&errorMessage);

#include STSTEM_WARNING_POP
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

System::String System::FormatErrorMessage(WindowError lastError)
{
    constexpr auto bufferSize = 256u;
    using BufferType = std::array<TChar, bufferSize>;

    BufferType buffer{};
    const auto size = FormatErrorMessage(lastError, buffer.data(), bufferSize - 1);

    if (0 < size)
        return String{ buffer.data() };
    else
        return String{};
}

bool System::FormatErrorMessage(WindowsHLocal& errorMessage, WindowError lastError) noexcept
{
    constexpr FormatErrorMessageParameter parameter{ FormatMessageOption::FromSystem | FormatMessageOption::IgnoreInserts | FormatMessageOption::AllocateBuffer };

    const auto size = FormatErrorMessage(parameter.GetOption(), parameter.GetWidth(), nullptr, lastError, parameter.GetLanguageIDData(), ReinterpretCast(errorMessage), 0, nullptr);

    return size != 0;
}

System::WindowsDWord System::FormatErrorMessage(WindowError lastError, TChar* buffer, WindowsDWord size) noexcept
{
    constexpr FormatErrorMessageParameter parameter{ FormatMessageOption::FromSystem | FormatMessageOption::IgnoreInserts };

    return FormatErrorMessage(parameter.GetOption(), parameter.GetWidth(), nullptr, lastError, parameter.GetLanguageIDData(), buffer, size, nullptr);
}

bool System::FormatErrorMessage(WindowsHLocal& errorMessage, ConstDynamicLinkModule module, WindowError lastError) noexcept
{
    constexpr FormatErrorMessageParameter parameter{ FormatMessageOption::FromHModule | FormatMessageOption::IgnoreInserts | FormatMessageOption::AllocateBuffer };

    const auto size = FormatErrorMessage(parameter.GetOption(), parameter.GetWidth(), module, lastError, parameter.GetLanguageIDData(), ReinterpretCast(errorMessage), 0, nullptr);

    return size != 0;
}

System::WindowsDWord System::FormatErrorMessage(ConstDynamicLinkModule module, WindowError lastError, TChar* buffer, WindowsDWord size) noexcept
{
    constexpr FormatErrorMessageParameter parameter{ FormatMessageOption::FromHModule | FormatMessageOption::IgnoreInserts };

    return FormatErrorMessage(parameter.GetOption(), parameter.GetWidth(), module, lastError, parameter.GetLanguageIDData(), buffer, size, nullptr);
}

System::WindowsDWord System::FormatStringMessage(const TChar* message, TChar* buffer, WindowsDWord size, WindowsDWordPtrSizeType* arguments) noexcept
{
    constexpr FormatErrorMessageParameter parameter{ FormatMessageOption::FromString | FormatMessageOption::ArgumentArray };

    return FormatErrorMessage(parameter.GetOption(), parameter.GetWidth(), message, parameter.GetWindowError(), parameter.GetLanguageIDData(), buffer, size, ReinterpretCast(arguments));
}

System::WindowsDWord System::FormatStringMessage(const TChar* message, TChar* buffer, WindowsDWord size, va_list* arguments) noexcept
{
    constexpr FormatErrorMessageParameter parameter{ FormatMessageOption::FromString };

    return FormatErrorMessage(parameter.GetOption(), parameter.GetWidth(), message, parameter.GetWindowError(), parameter.GetLanguageIDData(), buffer, size, arguments);
}

System::WindowsDWord System::FormatStringMessage(const TChar* message, WindowsHLocal& resultMessage, WindowsDWordPtrSizeType* arguments) noexcept
{
    constexpr FormatErrorMessageParameter parameter{ FormatMessageOption::FromString | FormatMessageOption::ArgumentArray | FormatMessageOption::AllocateBuffer };

    return FormatErrorMessage(parameter.GetOption(), parameter.GetWidth(), message, parameter.GetWindowError(), parameter.GetLanguageIDData(), ReinterpretCast(resultMessage), 0, ReinterpretCast(arguments));
}

System::WindowsDWord System::FormatStringMessage(const TChar* message, WindowsHLocal& resultMessage, va_list* arguments) noexcept
{
    constexpr FormatErrorMessageParameter parameter{ FormatMessageOption::FromString | FormatMessageOption::AllocateBuffer };

    return FormatErrorMessage(parameter.GetOption(), parameter.GetWidth(), message, parameter.GetWindowError(), parameter.GetLanguageIDData(), ReinterpretCast(resultMessage), 0, arguments);
}
