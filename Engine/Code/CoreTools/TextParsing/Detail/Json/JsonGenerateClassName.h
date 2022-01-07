///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 11:53)

#ifndef CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_CLASS_NAME_H
#define CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_CLASS_NAME_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/TextParsing/TextParsingInternalFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE JsonGenerateClassName final
    {
    public:
        using ClassType = JsonGenerateClassName;
        using String = System::String;

    public:
        explicit JsonGenerateClassName(const JsonHead& jsonHead) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GenerateContainerClassName() const;
        NODISCARD String GenerateUsing() const;
        NODISCARD String GenerateContainerClassName(const JsonNode& jsonNode) const;
        NODISCARD String GenerateUsing(const JsonNode& jsonNode) const;

    private:
        JsonHead jsonHead;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_JSON_GENERATE_CLASS_NAME_H