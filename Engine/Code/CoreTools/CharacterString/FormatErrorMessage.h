///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/12 14:08)

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

        NODISCARD String GetErrorMessage() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_FORMAT_ERROR_MESSAGE_H