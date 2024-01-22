/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:28)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CharacterStringFwd.h"
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
        CSVTotalGenerate(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, const CodeMappingAnalysis& codeMappingAnalysis, CSVTotalGenerateType csvTotalGenerateType);

        CLASS_INVARIANT_DECLARE;

        void GenerateFile(const String& codeDirectory, const String& directory) const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_H