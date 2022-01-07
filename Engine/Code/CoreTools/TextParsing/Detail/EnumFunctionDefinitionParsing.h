///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:31)

#ifndef CORE_TOOLS_TEXT_PARSING_ENUM_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_ENUM_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE EnumFunctionDefinitionParsing : public Parsing
    {
    public:
        using ClassType = EnumFunctionDefinitionParsing;
        using ParentType = Parsing;
        using StringView = System::StringView;

    public:
        EnumFunctionDefinitionParsing(const CSVHead& csvHead, const CSVContent& csvContent, const String& className, int nameIndex);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD String GenerateEnumFunctionDefinition() const;

    protected:
        NODISCARD CSVHead GetCSVHead() const noexcept;
        NODISCARD CSVContent GetCSVContent() const noexcept;
        NODISCARD int GetNameIndex() const noexcept;

        NODISCARD String GetColumn(const String& describe, const String& space, CSVPoistionType csvPoistionType) const;
        NODISCARD String GetFindFunctionDefinition(const StringView& variable) const;

    private:
        NODISCARD virtual String GenerateHeader() const = 0;
        NODISCARD virtual String GenerateDescribe() const = 0;
        NODISCARD virtual String GenerateColumn(const String& space) const = 0;
        NODISCARD virtual String GenerateFindFunctionDefinition() const = 0;

        NODISCARD String GenerateFindTypeDescribe(const StringView& variable) const;
        NODISCARD String GenerateIterTypeDescribe() const;
        NODISCARD String GenerateTypeDescribeNotFind() const;

    private:
        CSVHead m_CsvHead;
        CSVContent m_CsvContent;
        String className;
        int nameIndex;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ENUM_FUNCTION_DEFINITION_PARSING_H