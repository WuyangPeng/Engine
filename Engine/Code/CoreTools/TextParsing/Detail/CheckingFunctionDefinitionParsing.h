///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:07)

#ifndef CORE_TOOLS_TEXT_PARSING_CHECKING_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_CHECKING_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "DefaultFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CheckingFunctionDefinitionParsing : public DefaultFunctionDefinitionParsing
    {
    public:
        using ClassType = CheckingFunctionDefinitionParsing;
        using ParentType = DefaultFunctionDefinitionParsing;
        using StringView = System::StringView;

    public:
        explicit CheckingFunctionDefinitionParsing(const CSVHead& csvHead, const String& className);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD String GenerateCheckingFunctionDefinition() const;
        NODISCARD String GenerateIsValidFunctionDefinition() const;

    private:
        NODISCARD String GenerateChecking() const;
        NODISCARD String GenerateCheckingMember(int index, bool isBegin) const;
        NODISCARD String GenerateCheckingMemberScopeExpression(const String& scopeExpression) const;

        NODISCARD String GenerateThrowException(const String& variableName) const;

        NODISCARD String GenerateIsValid() const;
        NODISCARD String GenerateIsValidAchieve() const;
        NODISCARD String GenerateIsValidMember(int index, bool isBegin) const;
        NODISCARD String GenerateIsValidMemberScopeExpression(const String& scopeExpression) const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CHECKING_FUNCTION_DEFINITION_PARSING_H