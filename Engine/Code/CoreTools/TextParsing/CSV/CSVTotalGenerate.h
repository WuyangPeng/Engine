///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/10 09:05)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <vector>

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(CSVTotalGenerateImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CSVTotalGenerate final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(CSVTotalGenerate);
        using String = System::String;
        using CSVHeadContainer = std::vector<CSVHead>;

    public:
        CSVTotalGenerate(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, CSVTotalGenerateType csvTotalGenerateType);

        CLASS_INVARIANT_DECLARE;

        void GenerateFile(const String& directory) const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_H