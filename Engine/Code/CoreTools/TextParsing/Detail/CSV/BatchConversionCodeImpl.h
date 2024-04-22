/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/03 00:02)

#ifndef CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CODE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CODE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVTotalGenerate.h"

#include <filesystem>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE BatchConversionCodeImpl final
    {
    public:
        using ClassType = BatchConversionCodeImpl;

        using String = System::String;

    public:
        explicit BatchConversionCodeImpl(const String& inputDirectory, const String& codeDirectory, const String& outputDirectory);

        CLASS_INVARIANT_DECLARE;

    private:
        using CSVHeadContainer = CSVTotalGenerate::CSVHeadContainer;

    private:
        void LoadConfigure(const String& inputDirectory);
        void LoadConfigure(const std::filesystem::directory_entry& inputPath);

        void GenerateFile() const;
        void GenerateFile(const CSVHead& csvHead) const;

        void TotalGenerateFile() const;
        void TotalGenerateFile(CSVTotalGenerateType csvTotalGenerateType) const;

        NODISCARD static String GetNativeFileName(const std::filesystem::directory_entry& inputPath);

    private:
        String nameSpace;
        CSVHeadContainer container;
        CodeMappingAnalysis codeMappingAnalysis;
        String codeDirectory;
        String outputDirectory;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_BATCH_CONVERSION_CODE_IMPL_H