/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:20)

#ifndef CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H
#define CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(FormatErrorMessageImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE FormatErrorMessage final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(FormatErrorMessage);

        using String = System::String;
        using WindowError = System::WindowError;

    public:
        explicit FormatErrorMessage(WindowError lastError);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetErrorMessage() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H