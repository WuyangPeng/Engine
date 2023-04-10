///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:09)

#ifndef CORE_TOOLS_TEXT_PARSING_GET_FUNCTION_PARSING_H
#define CORE_TOOLS_TEXT_PARSING_GET_FUNCTION_PARSING_H

#include "CoreTools/CoreToolsDll.h"

#include "Parsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE GetFunctionParsing : public Parsing
    {
    public:
        using ClassType = GetFunctionParsing;
        using ParentType = Parsing;

    public:
        GetFunctionParsing(CSVHead csvHead, String keyTypeDescribe) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD virtual String GenerateGetFunction() const = 0;

    protected:
        NODISCARD String GetKeyTypeDescribe() const;
        NODISCARD CSVHead GetCSVHead() const noexcept;
        NODISCARD int GetCSVHeadCount() const;

        NODISCARD String GenerateGetKeyFunction() const;

        NODISCARD String GenerateCountFunction(const String& functionVariableName, const StringView& beginDescribe, const StringView& endDescribe) const;
        NODISCARD String GenerateGetValueFunction(const String& valueType, const String& functionVariableName, const StringView& beginDescribe, const StringView& endDescribe) const;
        NODISCARD String GenerateBeginIterFunction(const String& actualType, const String& functionVariableName, const StringView& beginDescribe, const StringView& endDescribe) const;
        NODISCARD String GenerateEndIterFunction(const String& actualType, const String& functionVariableName, const StringView& beginDescribe, const StringView& endDescribe) const;

    private:
        NODISCARD String GenerateKeyFunctionStatement() const;
        NODISCARD String GenerateReturnKey() const;
        NODISCARD String GenerateKeyParameter() const;

    private:
        String keyTypeDescribe;
        CSVHead head;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_GET_FUNCTION_PARSING_H