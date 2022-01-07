///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:31)

#ifndef CORE_TOOLS_TEXT_PARSING_ENUM_HEAD_FILE_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_ENUM_HEAD_FILE_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE EnumHeadFileParsing final : public Parsing
    {
    public:
        using ClassType = EnumHeadFileParsing;
        using ParentType = Parsing;

    public:
        EnumHeadFileParsing(const CSVHead& csvHead, const CSVContent& csvContent, const String& className);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateIOStreamHead() const;
        NODISCARD String GenerateEnumContent() const;

        NODISCARD String GenerateEnumOperator() const;
        NODISCARD String GenerateEnumFunction() const;

    private:
        using SplitType = std::vector<String>;

    private:
        NODISCARD bool HasIOStreamOperator() const;
        NODISCARD bool HasIOStreamOperator(int index, const String& column) const;
        NODISCARD bool IsOperatorTrue(const SplitType& result, int index) const;

        NODISCARD String GetEnumVariableContent(const String& column, int idIndex, int nameIndex, int describeIndex) const;
        NODISCARD String GetEnumVariableContent(const String& name, const String& id, const String& describe) const;

        NODISCARD String GenerateEnumOperator(const String& field, const SplitType& element, const String& operatorDescribe) const;
        NODISCARD String GenerateOperatorDescribe(const String& operatorDescribe) const;
        NODISCARD String GenerateEnumIOStreamOperator(const SplitType& element) const;

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