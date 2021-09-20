///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/27 18:23)

#ifndef CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H
#define CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

#include <string>

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(FormatErrorMessageImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE FormatErrorMessage final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(FormatErrorMessage);

        using WindowError = System::WindowError;
        using String = System::String;

    public:
        explicit FormatErrorMessage(WindowError lastError);

        CLASS_INVARIANT_DECLARE;

        NODISCARD const String GetErrorMessage() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H