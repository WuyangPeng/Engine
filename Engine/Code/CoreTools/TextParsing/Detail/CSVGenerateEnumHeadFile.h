///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/25 22:05)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_HEAD_FILE_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_HEAD_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVGenerateImpl.h"
#include "CoreTools/TextParsing/CSVContent.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateEnumHeadFile final : public CSVGenerateImpl
    {
    public:
        using ClassType = CSVGenerateEnumHeadFile;
        using ParentType = CSVGenerateImpl;

    public:
        explicit CSVGenerateEnumHeadFile(const CSVContent& csvContent);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        NODISCARD String GetSuffix() const noexcept final;
        NODISCARD String GetFilePrefix() const final;
        NODISCARD String GetFileSuffix() const final;
        NODISCARD String GetContent() const final;

        NODISCARD String GenerateIOStreamHead() const;
        NODISCARD String GenerateEnumContent() const;

        NODISCARD String GenerateEnumOperator() const;
        NODISCARD bool HasIOStreamOperator() const;
        NODISCARD bool HasIOStreamOperator(int index, const String& column) const;

        NODISCARD String GetEnumVariableContent(const String& column, int idIndex, int nameIndex, int describeIndex) const;
        NODISCARD String GenerateEnumOperator(CSVHead head, const String& field, const std::vector<String>& element, const String& operatorDescribe) const;
        NODISCARD String GenerateEnumIOStreamOperator(CSVHead head, const std::vector<String>& element) const;

        NODISCARD String GenerateEnumFunction() const;

    private:
        CSVContent csvContent;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_ENUM_HEAD_FILE_H