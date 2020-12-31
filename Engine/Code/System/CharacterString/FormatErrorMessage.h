//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 13:17)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H
#define SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H

#include "System/SystemDll.h"

#include "Fwd/CharacterStringFlagsFwd.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputDataFwd.h"
#include "System/Window/Fwd/WindowFlagsFwd.h"

namespace System
{
    // 格式化错误消息。

    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE FormatErrorMessage(FormatMessageOption flag, FormatMessageWidth widthFlag, WindowConstVoidPtr source, WindowError messageID,
                                                                        const LanguageIDData& languageID, TChar* buffer, WindowDWord size, va_list* arguments) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE FormatErrorMessage(WindowHLocal& errorMessage, WindowError lastError) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE FormatErrorMessage(WindowError lastError, TChar* buffer, WindowDWord size) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE FormatErrorMessage(WindowHLocal& errorMessage, DynamicLinkModule module, WindowError lastError) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE FormatErrorMessage(const DynamicLinkModule module, WindowError lastError, TChar* buffer, WindowDWord size) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE FormatStringMessage(const TChar* message, TChar* buffer, WindowDWord size, WindowPtrDWord* arguments) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE FormatStringMessage(const TChar* message, TChar* buffer, WindowDWord size, va_list* arguments) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE FormatStringMessage(const TChar* message, WindowHLocal& resultMessage, WindowPtrDWord* arguments) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE FormatStringMessage(const TChar* message, WindowHLocal& resultMessage, va_list* arguments) noexcept;

    [[nodiscard]] constexpr WindowDWord MakeSoftwareException(Severity severity, Facility facility, WindowDWord exception) noexcept
    {
        // 异常码
        constexpr WindowDWord exceptionShift{ 0 };

        // 设备码
        constexpr WindowDWord facilityShift{ 16 };

        // 保留的(0)
        constexpr WindowDWord reservedShift{ 28 };

        // MS(0) 或 自定义(1)
        constexpr WindowDWord customerShift{ 29 };

        // 严重性
        constexpr WindowDWord severityShift{ 30 };

        return (EnumCastUnderlying(severity) << severityShift) | (1 << customerShift) | (0 << reservedShift) |
               (EnumCastUnderlying(facility) << facilityShift) | (exception << exceptionShift);
    }
}

#endif  // SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H
