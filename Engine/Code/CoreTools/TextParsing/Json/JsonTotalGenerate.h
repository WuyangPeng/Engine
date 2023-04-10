///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:12)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_TOTAL_GENERATE_H
#define CORE_TOOLS_TEXT_PARSING_JSON_TOTAL_GENERATE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <vector>

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(JsonTotalGenerateImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE JsonTotalGenerate final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(JsonTotalGenerate);
        using String = System::String;
        using JsonHeadContainer = std::vector<JsonHead>;

    public:
        JsonTotalGenerate(const String& nameSpace, const JsonHeadContainer& jsonHeadContainer, JsonTotalGenerateType jsonTotalGenerateType);

        CLASS_INVARIANT_DECLARE;

        void GenerateFile(const String& directory) const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_TOTAL_GENERATE_H