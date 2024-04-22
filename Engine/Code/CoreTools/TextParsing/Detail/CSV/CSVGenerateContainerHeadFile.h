/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/02 22:51)

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

        NODISCARD String GetContainerStdIncludeContent() const;
        NODISCARD String GetContainerGetFunctionReplace() const;
        NODISCARD String GetMappingContainerUsingReplace() const;
        NODISCARD String GetContainerTypeReplace() const;
        NODISCARD String GetContainerUsingReplace() const;
        NODISCARD String GetMapNameReplace() const;
        NODISCARD String GetUniqueFunctionReplace() const;
        NODISCARD String GetKeyParameterReplace() const;

    private:
        String templateName;
    };

}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_CONTAINER_HEAD_FILE_H