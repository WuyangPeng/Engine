///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 12:13)

#ifndef CORE_TOOLS_TEXT_PARSING_BASE_GET_FUNCTION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_BASE_GET_FUNCTION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "GetFunctionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE BaseGetFunctionParsing final : public GetFunctionParsing
    {
    public:
        using ClassType = BaseGetFunctionParsing;
        using ParentType = GetFunctionParsing;

    public:
        BaseGetFunctionParsing(const CSVHead& csvHead, const String& keyTypeDescribe);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateGetFunction() const override;

    private:
        NODISCARD String GenerateBaseGetFunction(int index) const;

        NODISCARD String GenerateGetKey() const;
        NODISCARD String GenerateFunctionVariableNameBegin(const String& actualType, const String& functionVariableName) const;
        NODISCARD String GenerateFunctionVariableName(CSVDataType dataType, const String& actualType, const String& functionVariableName) const;

        NODISCARD String GenerateArray(const String& actualType, const String& valueType, const String& functionVariableName) const;
        NODISCARD String GenerateMapping(int index, const String& mapping) const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_BASE_GET_FUNCTION_PARSING_H