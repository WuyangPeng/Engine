///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 22:45)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H
#define SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H

#include "System/SystemDll.h"

#include "Fwd/CharacterStringFlagsFwd.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputDataFwd.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"

namespace System
{
    // 格式化错误消息。

    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE FormatErrorMessage(FormatMessageOption flag,
                                                                     FormatMessageWidth widthFlag,
                                                                     WindowsConstVoidPtr source,
                                                                     WindowError messageID,
                                                                     const LanguageIDData& languageID,
                                                                     TChar* buffer,
                                                                     WindowsDWord size,
                                                                     va_list* arguments) noexcept;

    // errorMessage分配的内存需要使用LocalMemoryFree进行释放。
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FormatErrorMessage(WindowsHLocal& errorMessage, WindowError lastError) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE FormatErrorMessage(WindowError lastError, TChar* buffer, WindowsDWord size) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FormatErrorMessage(WindowsHLocal& errorMessage, DynamicLinkModule module, WindowError lastError) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE FormatErrorMessage(const DynamicLinkModule module, WindowError lastError, TChar* buffer, WindowsDWord size) noexcept;

    // resultMessage分配的内存需要使用LocalMemoryFree进行释放。
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE FormatStringMessage(const TChar* message, TChar* buffer, WindowsDWord size, WindowsPtrDWord* arguments) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE FormatStringMessage(const TChar* message, TChar* buffer, WindowsDWord size, va_list* arguments) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE FormatStringMessage(const TChar* message, WindowsHLocal& resultMessage, WindowsPtrDWord* arguments) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE FormatStringMessage(const TChar* message, WindowsHLocal& resultMessage, va_list* arguments) noexcept;

    NODISCARD constexpr WindowsDWord MakeSoftwareException(Severity severity, Facility facility, WindowsDWord exception) noexcept
    {
        // 异常码
        constexpr WindowsDWord exceptionShift{ 0 };

        // 设备码
        constexpr WindowsDWord facilityShift{ 16 };

        // 保留的(0)
        constexpr WindowsDWord reservedShift{ 28 };

        // MS(0) 或 自定义(1)
        constexpr WindowsDWord customerShift{ 29 };

        // 严重性
        constexpr WindowsDWord severityShift{ 30 };

        return (EnumCastUnderlying(severity) << severityShift) |
               (1 << customerShift) |
               (0 << reservedShift) |
               (EnumCastUnderlying(facility) << facilityShift) |
               (exception << exceptionShift);
    }
}

#endif  // SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H
