/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:30)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_TOTAL_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_TOTAL_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateEnumTotalFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateEnumTotalFile;
        using ParentType = CSVGenerateImpl;

    public:
        CSVGenerateEnumTotalFile(const CSVContent& csvContent, const CodeMappingAnalysis& codeMappingAnalysis);

        CLASS_INVARIANT_FINAL_DECLARE;

        void GenerateFile(const String& codeDirectory, const String& directory) const override;

    private:
        NODISCARD String GetSuffix() const noexcept override;
        NODISCARD String GetFilePrefix() const noexcept override;
        NODISCARD String GetFileSuffix() const noexcept override;
        NODISCARD String GetContent(const String& codeDirectory) const noexcept override;

    private:
        CSVContent csvContent;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_TOTAL_FILE_H