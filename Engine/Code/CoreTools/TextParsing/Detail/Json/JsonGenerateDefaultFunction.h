///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 11:53)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_DEFAULT_FUNCTION_H
#define CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_DEFAULT_FUNCTION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

#include <set>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonGenerateDefaultFunction final
    {
    public:
        using ClassType = JsonGenerateDefaultFunction;
        using String = System::String;

    public:
        explicit JsonGenerateDefaultFunction(const JsonHead& jsonHead) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateContainerDefaultFunction() const;
        NODISCARD String GenerateContainerDefaultFunction(const JsonNode& jsonNode) const;

    private:
        JsonHead jsonHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_DEFAULT_FUNCTION_H