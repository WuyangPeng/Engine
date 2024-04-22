/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 22:52)

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

        NODISCARD String ContainerSharedPtrUsingContent(const ContainerType& dataType) const;
        NODISCARD String GetContainerSharedPtrUsingContent(const ContainerType& dataType) const;

        NODISCARD String GetContainerSharedPtrContent(const ContainerType& dataType) const;

        NODISCARD String GetContainerSharedPtrContent(const String& element) const;

    private:
        String templateName;
        String containerSharedPtrUsing;
        String getContainerSharedPtrUsing;
        String containerSharedPtr;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_CONTAINER_HEAD_FILE_H