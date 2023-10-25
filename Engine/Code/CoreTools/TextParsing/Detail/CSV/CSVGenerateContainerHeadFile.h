///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/23 09:29)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CONTAINER_HEAD_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CONTAINER_HEAD_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateContainerHeadFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateContainerHeadFile;
        using ParentType = CSVGenerateImpl;

    public:
        CSVGenerateContainerHeadFile(const CSVHead& csvHead, const CodeMappingAnalysis& codeMappingAnalysis) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetSuffix() const override;
        NODISCARD String GetFilePrefix() const override;
        NODISCARD String GetFileSuffix() const override;
        NODISCARD String GetContent(const String& codeDirectory) const override;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CONTAINER_HEAD_FILE_H