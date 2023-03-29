///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/08 18:10)

#ifndef CORE_TOOLS_TEXT_PARSING_CHILD_GET_FUNCTION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_CHILD_GET_FUNCTION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "GetFunctionParsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ChildGetFunctionParsing final : public GetFunctionParsing
    {
    public:
        using ClassType = ChildGetFunctionParsing;
        using ParentType = GetFunctionParsing;

    public:
        ChildGetFunctionParsing(const CSVHead& csvHead, const String& keyTypeDescribe);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD String GenerateGetFunction() const override;

    private:
        NODISCARD String GenerateChildGetFunction(int index) const;

        NODISCARD String GenerateGetKey() const;
        NODISCARD String GenerateChecking() const;

        NODISCARD String GenerateFunctionVariableName(CSVDataType dataType, const String& actualType, const String& functionVariableName) const;

        NODISCARD String GenerateArray(const String& actualType, const String& valueType, const String& functionVariableName) const;
        NODISCARD String GenerateMapping(int index, const String& mapping) const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CHILD_GET_FUNCTION_PARSING_H