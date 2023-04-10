///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:09)

#ifndef CORE_TOOLS_TEXT_PARSING_GET_FUNCTION_DEFINITION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_GET_FUNCTION_DEFINITION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE GetFunctionDefinitionParsing : public Parsing
    {
    public:
        using ClassType = GetFunctionDefinitionParsing;
        using ParentType = Parsing;

    public:
        GetFunctionDefinitionParsing(CSVHead csvHead, String className, String keyTypeDescribe) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD virtual String GenerateGetFunctionDefinition() const = 0;

    protected:
        NODISCARD String GetCSVClassName() const;
        NODISCARD String GetKeyTypeDescribe() const;
        NODISCARD CSVHead GetCSVHead() const noexcept;
        NODISCARD int GetCSVHeadCount() const;

        NODISCARD String GenerateReturnKey(int addIndentationCount = 0) const;
        NODISCARD String GenerateGetFunctionArrayCount(const String& functionVariableName) const;
        NODISCARD String GenerateGetFunctionArrayConstIterator(const String& actualType, const String& functionVariableName, const StringView& endDescribe) const;

        NODISCARD String GenerateLambdaFunctionReturnIter() const;

    private:
        String className;
        String keyTypeDescribe;
        CSVHead head;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_GET_FUNCTION_DEFINITION_PARSING_H