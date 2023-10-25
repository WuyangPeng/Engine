///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/09 15:03)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_FWD_HEAD_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_FWD_HEAD_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVTotalGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVTotalGenerateFwdHeadFile final : public CSVTotalGenerateImpl
    {
    public:
        using ClassType = CSVTotalGenerateFwdHeadFile;
        using ParentType = CSVTotalGenerateImpl;

    public:
        explicit CSVTotalGenerateFwdHeadFile(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, const CodeMappingAnalysis& codeMappingAnalysis);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetFileSuffix() const override;
        NODISCARD String GetContent(const String& codeDirectory) const override;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_FWD_HEAD_FILE_H