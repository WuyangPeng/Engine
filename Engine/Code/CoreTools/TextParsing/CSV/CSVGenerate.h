///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/26 13:44)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CharacterStringFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(CSVGenerateImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CSVGenerate final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(CSVGenerate);

        using String = System::String;

    public:
        CSVGenerate(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis, CSVGenerateType csvGenerateType);
        CSVGenerate(const CSVContent& csvContent, const CodeMappingAnalysis& codeMappingAnalysis, CSVGenerateType csvGenerateType);

        CLASS_INVARIANT_DECLARE;

        void GenerateFile(const String& codeDirectory, const String& directory) const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_H