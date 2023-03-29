///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 11:04)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_GET_FUNCTION_DEFINITION_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_GET_FUNCTION_DEFINITION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CSVGenerateGetFunctionDefinition final
    {
    public:
        using ClassType = CSVGenerateGetFunctionDefinition;
        using String = System::String;

    public:
        CSVGenerateGetFunctionDefinition(const CSVHead& csvHead, const String& suffix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateBaseGetFunctionDefinition(const String& keyTypeDescribe) const;
        NODISCARD String GenerateGetFunctionDefinition(const String& keyTypeDescribe) const;
        NODISCARD String GenerateContainerFunctionDefinition(const String& keyTypeDescribe) const;
        NODISCARD String GenerateContainerDetailDefinition() const;
        NODISCARD String GenerateStringCastEnumDefinition() const;

    private:
        CSVHead csvHead;
        String suffix;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_GET_FUNCTION_DEFINITION_H