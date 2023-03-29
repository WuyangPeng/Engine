///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/10 13:37)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_DEFAULT_FUNCTION_DEFINITION_H
#define CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_DEFAULT_FUNCTION_DEFINITION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonGenerateDefaultFunctionDefinition final
    {
    public:
        using ClassType = JsonGenerateDefaultFunctionDefinition;
        using String = System::String;

    public:
        explicit JsonGenerateDefaultFunctionDefinition(JsonHead jsonHead) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateDefinition() const;
        NODISCARD String GenerateDefinition(const JsonNode& jsonNode) const;

    private:
        JsonHead jsonHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_DEFAULT_FUNCTION_DEFINITION_H