///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/03 17:01)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_DEFAULT_FUNCTION_DEFINITION_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_DEFAULT_FUNCTION_DEFINITION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSVHead.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <set>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateDefaultFunctionDefinition final
    {
    public:
        using ClassType = CSVGenerateDefaultFunctionDefinition;
        using String = System::String;

    public:
        explicit CSVGenerateDefaultFunctionDefinition(const CSVHead& csvHead, const String& suffix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateBaseDefaultFunctionDefinition() const;
        NODISCARD String GenerateChildDefaultFunctionDefinition() const;
        NODISCARD String GenerateDefaultFunctionDefinition() const;
        NODISCARD String GenerateContainerDefaultFunctionDefinition() const;

    private:
        NODISCARD String GenerateMemberDefinition(int index, bool isEnd) const;
        NODISCARD String GenerateCheckingFunctionDefinition() const;
        NODISCARD String GenerateNoCheckingFunctionDefinition() const;
        NODISCARD String GenerateCheckingMemberDefinition(int index, bool isBegin) const;
        NODISCARD String GenerateIsValidMemberDefinition(int index, bool isBegin) const;
        NODISCARD String GenerateCheckingMemberDefinition(int index, CSVPoistionType csvPoistionType) const;
        NODISCARD String GenerateContainerAddDataDefinition() const;
        NODISCARD String GenerateDefaultContainerAddDataDefinition() const;
        NODISCARD String GenerateVectorContainerAddDataDefinition() const;
        NODISCARD String GenerateMapContainerAddDataDefinition() const;
        NODISCARD String GenerateUniqueContainerAddDataDefinition() const;

    private:
        CSVHead csvHead;
        String suffix;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_DEFAULT_FUNCTION_DEFINITION_H