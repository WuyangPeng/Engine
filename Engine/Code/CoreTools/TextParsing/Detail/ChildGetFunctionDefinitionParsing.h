///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:12)

#ifndef CORE_TOOLS_TEXT_PARSING_CHILD_GET_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_CHILD_GET_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "GetFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ChildGetFunctionDefinitionParsing final : public GetFunctionDefinitionParsing
    {
    public:
        using ClassType = ChildGetFunctionDefinitionParsing;
        using ParentType = GetFunctionDefinitionParsing;

    public:
        ChildGetFunctionDefinitionParsing(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateGetFunctionDefinition() const override;

    private:
        NODISCARD String GenerateUserClassIsValidConst() const;

        NODISCARD String GenerateGetFunctionDefinition(int index) const;
        NODISCARD String GenerateGetFunctionArrayDefinition(int index) const;
        NODISCARD String GenerateGetFunctionMappingDefinition(int index) const;

        NODISCARD String GenerateGetKeyDefinition() const;
        NODISCARD String GenerateGetKeyConst() const;
        NODISCARD String GenerateReturnGetKey() const;
        NODISCARD String GenerateReturnVariableName(const String& variableName) const;

        NODISCARD String GenerateVariableFunction(int index, const String& actualType) const;
        NODISCARD String GenerateGetVariableName(const String& variableName) const;

        NODISCARD String GenerateGetFunctionArrayCountDefinition(const String& functionVariableName, const String& variableName) const;
        NODISCARD String GenerateGetFunctionArrayDefinition(const String& valueType, const String& functionVariableName, const String& variableName) const;
        NODISCARD String GenerateGetFunctionArrayBeginDefinition(const String& actualType, const String& functionVariableName, const String& variableName) const;
        NODISCARD String GenerateGetFunctionArrayEndDefinition(const String& actualType, const String& functionVariableName, const String& variableName) const;

        NODISCARD String GenerateGetFunctionArraySize(const String& variableName) const;
        NODISCARD String GenerateGetFunctionArrayIndex(const String& valueType, const String& functionVariableName) const;
        NODISCARD String GenerateReturnIter(const String& variableName, const StringView& endDescribe) const;

        NODISCARD String GenerateGetFunctionArrayMapping(const String& upperVariableName, const String& mapping) const;
        NODISCARD String GenerateGetFunctionMappingBody(const String& variableName, const String& mapping) const;
        NODISCARD String GenerateGetContainerMapping(const String& variableName, const String& upperMapping) const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CHILD_GET_FUNCTION_DEFINITION_PARSING_H