///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 11:53)

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
        explicit JsonGenerateDefaultFunctionDefinition(const JsonHead& jsonHead) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateDefinition() const;
        NODISCARD String GenerateDefinition(const JsonNode& jsonNode) const;

    private:
        JsonHead jsonHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_DEFAULT_FUNCTION_DEFINITION_H