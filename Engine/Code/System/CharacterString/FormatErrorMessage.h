/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 17:07)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H
#define SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H

#include "System/SystemDll.h"

#include "Fwd/CharacterStringFlagsFwd.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/Fwd/SystemOutputDataFwd.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"

/// ��ʽ��������Ϣ��
namespace System
{
    NODISCARD SYSTEM_DEFAULT_DECLARE TChar* ReinterpretCast(WindowsHLocal& errorMessage) noexcept;

    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE FormatErrorMessage(FormatMessageOption flag,
                                                                     FormatMessageWidth widthFlag,
                                                                     WindowsConstVoidPtr source,
                                                                     WindowError messageId,
                                                                     const LanguageIdData& languageId,
                                                                     TChar* buffer,
                                                                     WindowsDWord size,
                                                                     va_list* arguments) noexcept;

    /// errorMessage������ڴ���Ҫʹ��LocalMemoryFree�����ͷš�
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FormatErrorMessage(WindowsHLocal& errorMessage, WindowError lastError) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE FormatErrorMessage(WindowError lastError, TChar* buffer, WindowsDWord size) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FormatErrorMessage(WindowsHLocal& errorMessage, ConstDynamicLinkModule module, WindowError lastError) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE FormatErrorMessage(ConstDynamicLinkModule module, WindowError lastError, TChar* buffer, WindowsDWord size) noexcept;
    NODISCARD String SYSTEM_DEFAULT_DECLARE FormatErrorMessage(WindowError lastError);

    /// resultMessage������ڴ���Ҫʹ��LocalMemoryFree�����ͷš�
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE FormatStringMessage(const TChar* message, TChar* buffer, WindowsDWord size, WindowsDWordPtrSizeType* arguments) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE FormatStringMessage(const TChar* message, TChar* buffer, WindowsDWord size, va_list* arguments) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE FormatStringMessage(const TChar* message, WindowsHLocal& resultMessage, WindowsDWordPtrSizeType* arguments) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE FormatStringMessage(const TChar* message, WindowsHLocal& resultMessage, va_list* arguments) noexcept;

    NODISCARD constexpr WindowsDWord MakeSoftwareException(const Severity severity, const Facility facility, const WindowsDWord exception) noexcept
    {
        return (EnumCastUnderlying(severity) << severityShift) |
               (1 << customerShift) |
               (0 << reservedShift) |
               (EnumCastUnderlying(facility) << facilityShift) |
               (exception << exceptionShift);
    }
}

#endif  // SYSTEM_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H
