///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/09 12:35)

#ifndef CORE_TOOLS_ENGINE_CONFIGURATION_STRING_REPLACING_H
#define CORE_TOOLS_ENGINE_CONFIGURATION_STRING_REPLACING_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(StringReplacingImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE StringReplacing final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(StringReplacing);
        using String = System::String;

    public:
        explicit StringReplacing(const std::string& configurationFileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD const String GetReplacing(const String& original) const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_ENGINE_CONFIGURATION_STRING_REPLACING_H
