/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 22:51)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_HEAD_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_HEAD_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateEnumHeadFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateEnumHeadFile;
        using ParentType = CSVGenerateImpl;

    public:
        CSVGenerateEnumHeadFile(const CSVContent& csvContent, const CodeMappingAnalysis& codeMappingAnalysis);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetSuffix() const noexcept override;
        NODISCARD String GetFilePrefix() const override;
        NODISCARD String GetFileSuffix() const override;
        NODISCARD String GetContent(const String& codeDirectory) const override;

        NODISCARD String GetClassNameMemberContent() const;
        NODISCARD String GetClassNameMemberContent(int idIndex, int nameIndex, int describeIndex, int index) const;

    private:
        CSVContent csvContent;
        String templateName;
        String classNameMember;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_HEAD_FILE_H