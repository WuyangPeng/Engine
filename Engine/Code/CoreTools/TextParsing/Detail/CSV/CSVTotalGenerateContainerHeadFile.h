/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:39)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_CONTAINER_HEAD_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_CONTAINER_HEAD_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVTotalGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVTotalGenerateContainerHeadFile final : public CSVTotalGenerateImpl
    {
    public:
        using ClassType = CSVTotalGenerateContainerHeadFile;
        using ParentType = CSVTotalGenerateImpl;

    public:
        explicit CSVTotalGenerateContainerHeadFile(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, const CodeMappingAnalysis& codeMappingAnalysis);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetFileSuffix() const override;
        NODISCARD String GetContent(const String& codeDirectory) const override;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_CONTAINER_HEAD_FILE_H