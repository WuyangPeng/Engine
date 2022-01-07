///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:39)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_H
#define CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(JsonGenerateImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE JsonGenerate final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(JsonGenerate);
        using String = System::String;

    public:
        explicit JsonGenerate(const JsonHead& jsonHead, JsonGenerateType jsonGenerateType);

        CLASS_INVARIANT_DECLARE;

        void GenerateFile(const String& directory) const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_H