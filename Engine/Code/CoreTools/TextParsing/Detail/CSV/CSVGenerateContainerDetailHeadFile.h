/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:30)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CONTAINER_DETAIL_HEAD_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CONTAINER_DETAIL_HEAD_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateContainerDetailHeadFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateContainerDetailHeadFile;
        using ParentType = CSVGenerateImpl;

    public:
        CSVGenerateContainerDetailHeadFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetSuffix() const override;
        NODISCARD String GetFilePrefix() const override;
        NODISCARD String GetFileSuffix() const override;
        NODISCARD String GetContent(const String& codeDirectory) const override;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CONTAINER_DETAIL_HEAD_FILE_H