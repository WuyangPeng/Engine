///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:17)

#ifndef CORE_TOOLS_TEXT_CSV_ROW_PARSING_DEFAULT_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_CSV_ROW_PARSING_DEFAULT_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "DefaultFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVRowDefaultFunctionDefinitionParsing final : public DefaultFunctionDefinitionParsing
    {
    public:
        using ClassType = CSVRowDefaultFunctionDefinitionParsing;
        using ParentType = DefaultFunctionDefinitionParsing;

    public:
        explicit CSVRowDefaultFunctionDefinitionParsing(const CSVHead& csvHead, const String& className);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateCSVRowChildConstructorDefinition() const;
        NODISCARD String GenerateCSVRowConstructorDefinition() const;

    private:
        NODISCARD String GenerateCSVRowConstructorDefinitionContent() const;

        NODISCARD String GenerateParentMember() const;
        NODISCARD String GenerateMemberColon() const;
        NODISCARD String GenerateMemberDefinition(int index, CSVPoistionType csvPoistionType) const;
        NODISCARD String GenerateChecking() const;
    };
}

#endif  // CORE_TOOLS_TEXT_CSV_ROW_PARSING_DEFAULT_FUNCTION_DEFINITION_PARSING_H