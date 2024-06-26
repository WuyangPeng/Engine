/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 22:52)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_CONTAINER_SOURCE_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_CONTAINER_SOURCE_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVTotalGenerateImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVTotalGenerateContainerSourceFile final : public CSVTotalGenerateImpl
    {
    public:
        using ClassType = CSVTotalGenerateContainerSourceFile;
        using ParentType = CSVTotalGenerateImpl;

    public:
        explicit CSVTotalGenerateContainerSourceFile(const String& nameSpace, const CSVHeadContainer& csvHeadContainer, const CodeMappingAnalysis& codeMappingAnalysis);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetFileSuffix() const override;
        NODISCARD String GetContent(const String& codeDirectory) const override;

        NODISCARD String GetContainerIncludeContent(const ContainerType& dataType) const;
        NODISCARD String GetContainerMemberContent(const ContainerType& dataType) const;
        NODISCARD String GetSetContainerContent(const ContainerType& dataType) const;
        NODISCARD String GetVerifyContainerContent(const ContainerType& dataType) const;
        NODISCARD String GetContainerNotEqualNullptrContent(const ContainerType& dataType) const;
        NODISCARD String GetContainerDefineContent(const ContainerType& dataType) const;

        NODISCARD String GetContainerMemberContent(int index, int size, const String& element) const;
        NODISCARD String GetSetContainerContent(int index, const String& element) const;
        NODISCARD String GetVerifyContainerContent(const String& element) const;
        NODISCARD String GetContainerNotEqualNullptrContent(int index, int size, const String& element) const;
        NODISCARD String GetContainerDefineContent(const String& element) const;

    private:
        String templateName;
        String containerInclude;
        String containerMember;
        String beginContainerMember;
        String endContainerMember;
        String elseSetContainer;
        String setContainer;
        String verifyContainer;
        String getContainerDefine;
        String containerNotEqualNullptr;
        String beginContainerNotEqualNullptr;
        String endContainerNotEqualNullptr;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_TOTAL_GENERATE_CONTAINER_SOURCE_FILE_H