///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:09)

#ifndef CORE_TOOLS_TEXT_PARSING_ENUM_HEAD_FILE_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_ENUM_HEAD_FILE_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE EnumHeadFileParsing final : public Parsing
    {
    public:
        using ClassType = EnumHeadFileParsing;
        using ParentType = Parsing;

    public:
        EnumHeadFileParsing(CSVHead csvHead, CSVContent csvContent, String className) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateIoStreamHead() const;
        NODISCARD String GenerateEnumContent() const;

        NODISCARD String GenerateEnumOperator() const;
        NODISCARD String GenerateEnumFunction() const;

    private:
        using SplitType = std::vector<String>;

    private:
        NODISCARD bool HasIoStreamOperator() const;
        NODISCARD bool HasIoStreamOperator(int index, const String& column) const;
        NODISCARD bool IsOperatorTrue(const SplitType& result, int index) const;

        NODISCARD String GetEnumVariableContent(const String& column, int idIndex, int nameIndex, int describeIndex) const;
        NODISCARD String GetEnumVariableContent(const String& name, const String& id, const String& describe) const;

        NODISCARD String GenerateEnumOperator(const String& field, const SplitType& element, const String& operatorDescribe) const;
        NODISCARD String GenerateOperatorDescribe(const String& operatorDescribe) const;

        NODISCARD String GenerateStringCast() const;
        NODISCARD String GenerateEnumCastString() const;
        NODISCARD String GenerateGetEnumDescribe() const;

    private:
        CSVHead csvHead;
        CSVContent csvContent;
        String className;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ENUM_HEAD_FILE_PARSING_H