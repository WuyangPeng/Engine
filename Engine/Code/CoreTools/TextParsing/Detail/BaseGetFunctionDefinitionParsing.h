///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/14 10:09)

#ifndef CORE_TOOLS_TEXT_PARSING_BASE_GET_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_BASE_GET_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "GetFunctionDefinitionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE BaseGetFunctionDefinitionParsing final : public GetFunctionDefinitionParsing
    {
    public:
        using ClassType = BaseGetFunctionDefinitionParsing;
        using ParentType = GetFunctionDefinitionParsing;

    public:
        BaseGetFunctionDefinitionParsing(const CSVHead& csvHead, const String& className, const String& keyTypeDescribe);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateGetFunctionDefinition() const override;

    private:
        NODISCARD String GenerateBaseGetFunctionDefinition(int index) const;
        NODISCARD String GenerateBaseGetFunctionReturnDefinition(CSVDataType dataType, const String& actualType) const;
        NODISCARD String GenerateBaseGetFunctionArrayDefinition(int index) const;
        NODISCARD String GenerateBaseGetFunctionMappingDefinition(int index) const;

        NODISCARD String GenerateGetKeyDefinition() const;

        NODISCARD String GenerateGetKeyConst() const;
        NODISCARD String GenerateVariableFunction(int index, const String& actualType) const;

        NODISCARD String GenerateBaseGetReturnDefinition(const StringView& endDescribe) const;
        NODISCARD String GenerateBaseGetEnumReturnDefinition(const String& actualType) const;
        NODISCARD String GenerateBaseGetFunctionReturnDefinition(CSVDataType dataType) const;

        NODISCARD String GenerateBaseGetFunctionArrayCountDefinition(const String& functionVariableName) const;
        NODISCARD String GenerateBaseGetFunctionArrayDefinition(const String& valueType, const String& functionVariableName) const;
        NODISCARD String GenerateBaseGetFunctionArrayBeginDefinition(const String& actualType, const String& functionVariableName) const;
        NODISCARD String GenerateBaseGetFunctionArrayEndDefinition(const String& actualType, const String& functionVariableName) const;

        NODISCARD String GenerateBaseGetFunctionArrayIndex(const String& valueType, const String& functionVariableName) const;
        NODISCARD String GenerateBaseGetFunctionArrayMapping(const String& upperVariableName, const String& mapping) const;
        NODISCARD String GenerateBaseGetFunctionArrayBody() const;
        NODISCARD String GenerateBaseGetFunctionMappingBody() const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_BASE_GET_FUNCTION_DEFINITION_PARSING_H